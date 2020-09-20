#include<pthread.h>
#include<stdio.h>

void *thread_fn(void *arg)
{
printf("in thread function\n");
pthread_detach(pthread_self());
//pthread_exit(NULL);
}
int main()
{
pthread_t tid;
pthread_create(&tid,NULL,thread_fn,NULL);
sleep(2);
pthread_join(tid,NULL);
//pthread_exit(NULL);

return 0;
}
