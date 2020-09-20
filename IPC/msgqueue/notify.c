#include<mqueue.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<fcntl.h>


static void fun(union sigval sg)
{
char buffer[256];
int priority=-1;
mqd_t mqdes=(sg.sival_int);
mq_receive(mqdes,buffer,sizeof(buffer),&priority);

printf("buffer: %s\t and priority: %d\n",buffer,priority);
}

int main()
{
mqd_t mqdes;
int status;
struct mq_attr attr;
mqdes=mq_open("/my_queue",O_RDWR|O_CREAT|O_NONBLOCK, 0666,NULL);
struct sigevent sev;
sev.sigev_notify=SIGEV_THREAD;
sev.sigev_notify_function=fun;
sev.sigev_notify_attributes=NULL;
sev.sigev_value.sival_int=mqdes;
mq_notify(mqdes,&sev);
while(1)
{}
status=mq_close(mqdes);
return 0;
}

