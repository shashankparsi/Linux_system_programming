#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/wait.h>

int main()
{
int fd;
char *address;

fd=open("hello.txt",O_RDWR);
if(fd<0)
{
perror("fd");
}

address=mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
if(address==MAP_FAILED)
{
perror("mmap");
}
pid_t pid;
pid=fork();
if(pid==0)
{
printf("in child process\n");
printf("data: %s\n",address);
munmap(address,20);
exit(0);
}
else
{
printf("in parent process\n");
wait(NULL);
printf("data: %s\n",address);
munmap(address,20);
}
close(fd);
}


