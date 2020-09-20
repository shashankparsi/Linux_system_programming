#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
pid_t pid;
char buf[10];
int fd;
off_t offset;
fd=open("hello.txt",O_CREAT|O_RDWR,0666);
pid=fork();
if(pid==0)
{
printf("child process created: %d\n",getpid());
read(fd,buf,2);
offset=lseek(fd,2,SEEK_SET);
printf("current ofset is : %d\n",offset);
}
else
{
printf("in parent process: %d\n",getpid());
read(fd,buf,5);
offset=lseek(fd,0,SEEK_CUR);
printf("current offset: %d\n",offset);
}
close(fd);
}
