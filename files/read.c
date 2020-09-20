#include<stdio.h>
#include<fcntl.h>
int main()
{
char buffer[256];
int fd;
int retval;
fd=open("hello.txt",O_CREAT|O_RDONLY);
if(fd<0)
{
printf("open failed\n");
}
else
{
printf("open success\n");
do{
memset(buffer,0,sizeof(buffer));
retval=read(fd,buffer,sizeof(buffer));
printf("buffer: %s and retval:%d\n",buffer,retval);
sleep(2);
}while(retval!=0);
close(fd);
}
}
