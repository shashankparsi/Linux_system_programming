#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int fd;
fd=access("hello.txt",F_OK);
if(fd<0)
{
printf("access failed\n");
}
else
{
printf("access success and file exists: %d\n",fd);
return 0;
}
}
