#include<fcntl.h>
#include<stdio.h>
int main()
{
int fd;
fd=open("hello.txt",O_WRONLY|O_CREAT|O_EXCL);
if(fd<0)
{
printf("failed to open file : %d\n",fd);
return -1;
}
else
{
printf("file opened success : %d\n",fd);
return 0;
}
}
