#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void handler_3(int signum)
{
printf("hello handler 3 your PID is : %d\n",getpid());
//printf("calling handler 3\n");
signal(SIGINT,SIG_DFL);
}


void handler_2(int signum)
{
printf("hello handler 2 your PID is : %d\n",getpid());
printf("calling handler 3\n");
signal(SIGINT,handler_3);
}


void handler_1(int signum)
{
printf("hello handler1 your PID is: %d\n",getpid());
printf("calling handler 2\n");
signal(SIGINT,handler_2);
}

int main()
{
signal(SIGINT,handler_1);
while(1);
//raise(SIGINT);

return 0;
}
