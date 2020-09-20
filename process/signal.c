#include<stdio.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
void sighand(int signum)
{
int childstatus;
printf("in signal handler\n");
}
int main()
{
int childstatus;
pid_t pid;
pid=fork();
if(pid==0)
{
printf("child created successfully: %d\n",getpid());
sleep(10);
printf("child exiting.......\n");
exit(0);
}
else
{
signal(SIGCHLD,sighand);
wait(&childstatus);
if(WIFSIGNALED(childstatus))
{
printf("child was killed due to signal\n");
}
}
}
