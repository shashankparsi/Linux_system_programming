#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd;
char *address;
fd=open("hello.txt",O_RDWR);
int fsize=lseek(fd,0,SEEK_END);
if(fd<0)
{
perror("fd");
}
address=mmap(NULL,fsize, PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
if(address==MAP_FAILED)
{
perror("mmap");
}
mprotect(address,10,PROT_WRITE);
address[0]='S';
address[1]='P';

printf("data: %s\n",address);
printf("%c\n",address[0]);
printf("%c\n",address[1]);
printf("%c\n",address[2]);
printf("%c\n",address[3]);
printf("%c\n",address[4]);
munmap(address,5);
//printf("%c\n",address[2]);
close(fd);
return 0;
}
