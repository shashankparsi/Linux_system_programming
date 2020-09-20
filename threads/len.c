#include<stdio.h>
#include<pthread.h>
#include<string.h>

void *func(void *arg)
{
char *str=(void*)arg;
printf("in thread function...%d\n",getpid());
return(void*) strlen(str);
}


int main()
{
pthread_t tid;
void *res;
int ret;
ret=pthread_create(&tid,NULL,func,"hello world");
if(ret!=0)
{
printf("thread creation failed\n");
return -1;
}
pthread_join(tid,&res);
printf("thread returned: %lu\n",(void*)res);
printf("in main: %d\n",getpid());
return 0;
}
