#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void attr_dump(pthread_t pid)
{
pthread_attr_t attr;
void *stkaddr; //for stack address
ssize_t stksize,guardsize; // stack size and guard size
int thread_state,schedule_policy; // threadstate and scheduling policy

pthread_getattr_np(pid,&attr);
printf("printing default attributes\n");
pthread_attr_getstack(&attr,&stkaddr,&stksize);
printf("stack size: %d\n",stksize);
printf("stack addr: %p\n",stkaddr);
pthread_attr_getdetachstate(&attr,&thread_state);
if(thread_state==PTHREAD_CREATE_JOINABLE)
{
printf("threadstate: joinable\n");
}
else
{
printf("thread state: detachable\n");
}

pthread_attr_getguardsize(&attr,&guardsize);
printf("guard size: %d\n",guardsize);


pthread_attr_getschedpolicy(&attr,&schedule_policy);
if(schedule_policy==SCHED_OTHER)
{
printf("other scheduling policy\n");
}
else if(schedule_policy==SCHED_RR)
{
printf("RR policy\n");
}
else if(schedule_policy==SCHED_FIFO)
{
printf("FIFO policy\n");
}
}

void *thread_fn(void *arg)
{
printf("in thread_fn\n");
attr_dump(pthread_self());
pthread_exit(NULL);
}

int main()
{
pthread_t tid;
//pthread_attr_t attr;
pthread_create(&tid, NULL,thread_fn, NULL);
pthread_exit(NULL);
}
