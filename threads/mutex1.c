#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
pthread_mutex_t *mtx1,*mtx2;

void *thread_fn1(void *arg)
{
printf("\n locking mutex1\n",__func__);
pthread_mutex_lock(mtx1);
printf("\n mutex1 is locked\n",__func__);
sleep(2);
pthread_yield();
printf("\n locking mutex2\n",__func__);
pthread_mutex_lock(mtx2);
printf("\n mutex 2 locked\n",__func__);
printf("\n mutex 2 unlocked\n",__func__);
pthread_mutex_unlock(mtx2);
printf("\n mutex 1 unlocked\n",__func__);
pthread_mutex_unlock(mtx1);
return NULL;
}

void *thread_fn2(void *arg)
{
sleep(3);
printf("\n locking mutex2\n",__func__);
pthread_mutex_lock(mtx2);
printf("\n mutex2 locked\n");
sleep(2);
pthread_yield();
printf("\n locking mutex1\n",__func__);
pthread_mutex_lock(mtx1);
printf("\n mutex1 is locked\n");

printf("\n unlocking mutex1\n",__func__);
pthread_mutex_unlock(mtx1);
printf("\n unlocking mutex 2\n",__func__);
pthread_mutex_unlock(mtx2);
return NULL;
}




int main()
{
pthread_t t1,t2;
int ret;
int loops=1000000;

mtx1=malloc(sizeof(pthread_mutex_t));
mtx2=malloc(sizeof(pthread_mutex_t));
ret=pthread_create(&t1, NULL,thread_fn1,&loops);
if(ret!=0)
{
perror("pthread\n");
}
ret=pthread_create(&t2,NULL,thread_fn2,&loops);
if(ret!=0)
{
perror("pthread");
}
ret=pthread_join(t1,NULL);
ret=pthread_join(t2,NULL);
return 0;
}






