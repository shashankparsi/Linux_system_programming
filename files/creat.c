#include<fcntl.h>
#include<stdio.h>
int main()
{
int fd;
fd=creat("hello.txt",0777);
if(fd<0)
{
printf("creat failed\n");
}
else
{
printf("creat success\n");
}
close(fd);
return 0;
}
