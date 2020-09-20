#include<stdio.h>
#include<pthread.h>

void *thread_fn1(void *arg)
{
printf("val: %d\n",*(int*)arg);
}

void *thread_fn(void *arg)
{
int var=20;
printf("in thread function\n");
pthread_t tid;
int err=pthread_yield();
pthread_create(&tid,NULL,thread_fn1,&var);
pthread_join(tid,NULL);
pthread_exit(NULL);
}

int main()
{
pthread_t id[2];
pthread_create(&id[0],NULL,thread_fn,NULL);\
pthread_exit(NULL);
}
