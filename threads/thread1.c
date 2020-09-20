#pragma pack(1)
#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<pthread.h>

struct test
{
int a;
int b;
};

void *func(void *arg)
{
printf("in thread function: %lu\n",syscall(SYS_gettid));
//printf("%d\n", (void*)arg);
sleep(5);
struct test *ptr=(struct test*)arg;
printf("ptr->a=%d\t and ptr->b= %d\n",ptr->a,ptr->b);
printf("size of struct test : %lu\n",sizeof(ptr));
return NULL;
}


int main()
{
struct test hello={50,60};
pthread_t tid;
pthread_t tid1;
printf("before thread....\n");
printf("sizeof struct in main: %lu\n",sizeof(hello));
pthread_create(&tid,NULL,func,(void*)&hello);
pthread_join(tid,NULL);
//while(1)
//{}
return 0;
}
