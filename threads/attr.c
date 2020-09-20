#include<stdio.h>
#include<pthread.h>


void *thread_fun(void *arg)
{
printf("hello thread...\n");
pthread_exit(NULL);
}


int main()
{
pthread_attr_t attr;
int ret;
ret=pthread_attr_init(&attr);
perror("attr");
ret=pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
perror("attr");
pthread_t tid;
ret=pthread_create(&tid,&attr,thread_fun,NULL);
sleep(2);
return 0;
}
