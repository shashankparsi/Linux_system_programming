#include<fcntl.h>
#include<stdio.h>
#include<string.h>
int main()
{
int fd;
char buffer[256];
fd=open("hello.txt",O_CREAT|O_RDWR|O_APPEND);
ssize_t write_retval;
if(fd<0)
{
printf("open failed\n");
}
else
{
printf("open success\n");
printf("enter data to be written :");
scanf("%s",&buffer);
write_retval=write(fd,buffer,strlen(buffer));
printf("write_retval: %d and strlen is : %d\n",write_retval,strlen(buffer));
return 0;
}
}
