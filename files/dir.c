#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#define DIR_TO_CREAT "mkdir-example.temp"
int main()
{
int fd;
fd=mkdir(DIR_TO_CREAT,0777);
if(fd<0)
{
printf("dir failed\n");
}
else
{
printf("dir succeesss: %d\n",fd);
return 0;
}
}
