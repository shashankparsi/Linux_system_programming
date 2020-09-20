#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<mqueue.h>
#include<unistd.h>
int main()
{
mqd_t mqdes;
int status;
int priority=-1;
char buffer[256]=" hello shashank_parsi";
mqdes=mq_open("/my_queue",O_CREAT|O_RDWR,0777,NULL);
//mq_send(mqdes,"hello shashank",sizeof("hello shashank"),16);
mq_receive(mqdes,buffer,sizeof(buffer),&priority);
printf("buffer: %s and priority: %d\n",buffer,priority);
status=mq_close(mqdes);
//status=mq_unlink("/myqueue");
return 0;
}
