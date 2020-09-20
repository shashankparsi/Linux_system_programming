#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/stat.h>
int main()
{
int fd;
sem_t *sem;
int sem_value;
sem=sem_open("linux",O_CREAT|O_RDWR,0777,2);
printf("value of semaphore is: %d\n",sem_getvalue(sem,&sem_value));
printf("%d\n",sem_value);
sem_post(sem);
printf("%d\n",sem_getvalue(sem,&sem_value));
sem_wait(sem);
printf("%d\n",sem_getvalue(sem,&sem_value));

return 0;
}
