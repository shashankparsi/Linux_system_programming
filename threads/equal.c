#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_t tid[2];
void *thread_fn(void *arg)
{
printf("in thread function.....\n");
sleep(1);
if(pthread_equal(tid[0],pthread_self()))
{
printf("thread 0 is executing\n");
}
else
{
printf("thread 1 is executing\n");
}
}


int main()
{
//pthread_t tid[2];
int ret;
//ret=pthread_create(&tid,NULL,thread_fn,NULL);
for(int i=0; i<2; i++)
{
ret=pthread_create(&tid[i],NULL,thread_fn,NULL);
if(ret==0)
{
printf("thread %d created successfully\n",i);
}
else
{
printf("thread  %d creation failed\n",i);
}
pthread_exit(NULL);
}
printf("after thread execution\n");
return 0;
}

