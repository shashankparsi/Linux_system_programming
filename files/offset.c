#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int fd;
char buf[10];
off_t currentpos;
fd=open("hello.txt",O_CREAT|O_RDWR);
if(fd<0)
{
printf("open failed\n");
}
else
{
printf("open success\n");
currentpos=lseek(fd,0,SEEK_CUR);
printf("currentpos: %d\n",currentpos);
read(fd,buf,sizeof(buf));
currentpos=lseek(fd,0,SEEK_CUR);
printf("currentpos: %d\n",currentpos);
close(fd);
return 0;
}
}

