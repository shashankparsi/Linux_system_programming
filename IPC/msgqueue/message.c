#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<mqueue.h>
#include<unistd.h>
int main()
{
mqd_t mqdes;
int status;
struct mq_attr attr;
mqdes=mq_open("/my_queue",O_CREAT|O_RDWR|O_NONBLOCK,0777,NULL);
mq_send(mqdes,"hello shashank",sizeof("hello shashank"),16);
printf("flags: %lu\n",attr.mq_flags);
printf("max messages: %lu\n",attr.mq_maxmsg);
printf("current message: %lu\n",attr.mq_curmsgs);
printf("size: %lu\n",attr.mq_msgsize);
mq_send(mqdes,"hello linux portal",sizeof("hello linux portal"),17);
getchar();
status=mq_close(mqdes);
status=mq_unlink("/myqueue");
return 0;
}
