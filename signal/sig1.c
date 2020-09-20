#include<signal.h>
#include<unistd.h>
#include<stdio.h>

void term_signal(int signum)
{
printf("PID: %d\n",getpid());
}
int main()
{
char buf[256];
pid_t pid;
signal(SIGINT,term_signal);
printf("my pid: %d\n",getpid());
pid=fork();
if(pid==0)
{
printf("child process running...\n");
int i=10;
while(i--)
{
write(1,".",strlen(buf)-1);
printf("%s\n",buf);
sleep(1);
}
write(1,"write done",15);
}
else
{
int i=5;
while(i--)
{
kill(pid,SIGKILL);
sleep(5);
kill(pid,SIGCONT);
sleep(3);
}
//return 0;
}
return 0;
}
