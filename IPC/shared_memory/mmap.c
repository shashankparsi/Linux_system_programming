#include<sys/mman.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define NAME "/my_shm1"
int main()
{
int fd;
int *address;
fd=shm_open(NAME,O_CREAT|O_EXCL|O_RDWR,0666);
if(fd<0)
{
printf("shm_open failed\n");
}
ftruncate(fd,4096);
address=(int *)mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
printf("mapped address: %p\n",address);
for(int i=0;i<100;i++)
{
//address[i]=i;
printf("address: %p\t and data: %d\n",address+i,address[i]);
}
munmap(address,4096);
close(fd);
return 0;
}
