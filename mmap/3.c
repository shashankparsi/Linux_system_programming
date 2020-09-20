#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
char *address;
//int fd;
pid_t pid;
address=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
if(address==MAP_FAILED)
{
perror("mmap");
}
pid=fork();
switch(pid)
{
case -1: 
	printf("process failed\n");
	exit(1);
	break;
case 0: 
	printf("in child process\n");
	printf("add: %s\n",address);	
	munmap(address,sizeof(int));
	exit(EXIT_SUCCESS);
	break;
default: 
	printf("in parent process\n");
	printf("data: %s\n",address);
	munmap(address,sizeof(int));
	exit(EXIT_SUCCESS);
}
return 0;
}
