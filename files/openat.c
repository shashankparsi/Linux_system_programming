#include<fcntl.h>
#include<stdio.h>
int main()
{
int fd;
if(!(chdir("\tmp")))
{
perror(" change directory success\n");
}
else
{
printf("failed to change dir\n");
}
fd=openat(AT_FDCWD,"hello.txt",O_CREAT|O_RDONLY);
if(fd<0)
{
printf("open failed\n");
}
else
{
printf("file opend success : %d\n",fd);
return 0;
}
}
