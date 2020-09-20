#include<sys/stat.h>
#include<sys/types.h>
#include<mqueue.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
mqd_t mqdes;
int status;
mqdes=mq_open("my_queue",O_CREAT|O_RDWR, 0666,NULL);
//getchar();
//status=mq_close(mqdes);
//status=mq_unlink("my_queue");
return 0;
} 
