#include<fcntl.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
int shm_fd;
const char *name="myshm";
const char *message1="hello";
const char *message2="shashank";
const char *message3="parsi";
void *address;
shm_fd=shm_open(name,O_CREAT|O_RDWR,0666);
if(shm_fd<0)
{
printf("shm_open failed\n");
return -1;
}
ftruncate(shm_fd,4096);
address=mmap(0,4096,PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
printf("%s\n",(char*)address);
sprintf(address,"%s",message1);
address=address+strlen(message1);
sleep(3);
sprintf(address,"%s",message2);
address=address+strlen(message2);
return 0;
}


