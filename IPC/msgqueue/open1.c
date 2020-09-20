#include<fcntl.h>
#include<mqueue.h>
#include<stdio.h>
#include<sys/ipc.h>
int main()
{
int status;
mqd_t mqdes;
struct mq_attr attr;
mqdes=mq_open("/my_queue",O_CREAT|O_RDWR|O_NONBLOCK,0666,NULL);
mq_getattr(mqdes,&attr);
printf("flags:%lu\n",attr.mq_flags);
printf("max no of messages: %lu\n",attr.mq_maxmsg);
printf("max size: %lu\n",attr.mq_msgsize);
printf("number of msgs in current queue: %lu\n",attr.mq_curmsgs);
status=mq_close(mqdes);
status=mq_unlink("my_queue");
return 0;
}
