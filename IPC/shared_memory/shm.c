#include<sys/mman.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#define NAME "/my_shm"
int main()
{
int fd;
fd=shm_open(NAME,O_CREAT|O_RDWR|O_EXCL,0666);
if(fd<0)
{
printf("shm_open failed\n");
return -1;
}
else
{
printf("shm_open success\n");
}
//fd=shm_unlink(NAME);
ftruncate(fd,4096);
close(fd);
}
