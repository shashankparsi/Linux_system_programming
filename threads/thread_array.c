#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *func(void *arg)
{
int *i=(void*)(arg);
printf("hello im executing thread %d\n",*i);
printf("i=%d\n",*i);
return NULL;
}

int main()
{
pthread_t tids[4];
int value[4];
void *res;
int i;
for(i=0;i<4;i++)
{
value[i]=i;
pthread_create(tids+i,NULL,func,value+i);
}
for(i=0;i<4;i++)
{
pthread_join(&tids[i],&res);
}
return 0;
}


