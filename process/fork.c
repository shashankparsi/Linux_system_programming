#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t pid;
printf("my process id: %d\n",getpid());
fork();
if(pid==0)
{
printf("child created with PID: %d\n",getpid());
while(1);
}
else
{
printf("newly created child pid: %d\n",getpid());
while(1);
}
return 0;
}

