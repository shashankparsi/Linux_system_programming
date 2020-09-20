#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
int main()
{
int shm_fd;
const char *name="myshm";
int *address;
shm_fd=shm_open(name,O_RDONLY,0666);
if(shm_fd<0)
{
printf("shm_open failed\n");
return -1;
}
address=mmap(0,1,PROT_READ,MAP_SHARED,shm_fd,0);
if(address=MAP_FAILED)
{
printf("mapping failed\n");
return 1;
}
printf("%s\n",(char *)address);
shm_unlink(name);
return 0;
}


