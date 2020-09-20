#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
static pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
int global=0;

void *my_thread1(void *arg)
{
int j;
int loops=(*(int*)(arg));
printf("%s\n",__func__);
for(j=0;j<loops;j++)
{
pthread_mutex_lock(&mtx);
global++;
//pthread_yield();
pthread_mutex_unlock(&mtx);
//pthread_yield();
//pthread_mutex_lock(&mtx);
}
return NULL;
}

void *my_thread2(void *arg)
{
int loops=(*(int*)(arg));
printf("%s\n",__func__);
//pthread_mutex_lock(&mtx);
return NULL;
}

int main()
{
pthread_t t1,t2;
int ret;
int loops=1000000;

ret=pthread_create(&t1,NULL,my_thread1,&loops);
if(ret!=0)
{
perror("pthread create: ");
}
ret=pthread_create(&t2,NULL,my_thread1,&loops);
if(ret!=0)
{
perror("pthread create2: ");
}

ret=pthread_create(&t1,NULL,my_thread2,&loops);
ret=pthread_join(t1,NULL);
ret=pthread_join(t1,NULL);
ret=pthread_join(t2,NULL);

printf("global=%d\n",global);
return 0;
}





