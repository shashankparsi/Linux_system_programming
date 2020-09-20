#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
int fd;
fd=open("dup2.temp",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
if(fd<0)
{
printf("open failed\n");
}
else
{
dup2(fd,1);

printf("hello shashank\n");
fprintf(stderr,"look in to dup2.temp for o/p\n");
return 0;
}
}
