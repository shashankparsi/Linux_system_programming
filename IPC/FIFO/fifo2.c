#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#define FIFO_NAME "my_fifo"
int main()
{
int retval,result,fd;
char buffer[]="linux";
if(access(FIFO_NAME,F_OK))
{
result=mkfifo(FIFO_NAME,0666);
if(result==!0)
{
printf("fifo creation failed\n");
}
}
printf("process %d opened fifo\n",getpid());
fd=open(FIFO_NAME,O_RDWR);
if(fd<0)
{
printf("open failed\n");
}
else
{
retval=write(fd,buffer,sizeof(buffer));
printf("retval: %d\n",retval);
printf("data written: %s\n",buffer);
memset(buffer,0,sizeof(buffer));
printf("buffer after setting values to 0: %s\n",buffer);
read(fd,buffer,sizeof(buffer));
printf("buffer: %s\n",buffer);
}
return 0;
}



