#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define FIFO_NAME "my_fifo"
int main()
{
int fd;
int result;

if(access(FIFO_NAME,F_OK)==-1)
{
result=mkfifo(FIFO_NAME,0777);
if(result==0)
{
printf("fifo success\n");
}
}
printf("process: %d open fifo\n",getpid());
fd=open(FIFO_NAME,O_RDWR);
if(fd<0)
{
printf("open success\n");
}
else
{
//printf("open failed\n");
close(fd);
}
return 0;
}
