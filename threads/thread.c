#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<pthread.h>
#include<stdlib.h>
void *func(void *arg)
{
printf("hello thread\n");
printf("process id: %d\t and thread id: %lu\n",getpid(),syscall(SYS_gettid));
printf("%s\n",(char *)arg);
return NULL;
}


int main()
{
pthread_t tid;
printf("In main process id: %d\t and thread id: %lu\n",getpid(),syscall(SYS_gettid));
int i;
for(i=0;i<50000;i++)
{
pthread_create(&tid,NULL,func,"linux world");
}
//return 0;
while(1)
{}
}
