#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_fn(void *arg)
{
printf("in thread function with tid: %u\n",pthread_self());
return  NULL;
}


int main()
{

pthread_t tid;
pthread_create(&tid,NULL,thread_fn,NULL);
printf("ID of thread main: %lu\n",tid);
pthread_join(tid,NULL);
return 0;
}
