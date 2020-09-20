#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/signal.h>

void signal_handler(int signum)
{
printf("snoozing...");
alarm(2);
//signal(SIGINT,SIG_DFL);
//alarm(0);
}

void alarm_handler(int signum)
{
printf("buzz....buzz...buzzzz\n");
signal(SIGINT,signal_handler);
}


int main()
{
signal(SIGALRM,alarm_handler);

alarm(5);

//signal(SIGINT,signal_handler);

while(1)
{
pause();
}
}
