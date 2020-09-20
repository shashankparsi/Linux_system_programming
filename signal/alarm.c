#include<stdio.h>
#include<sys/signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void signal_alarm(int signum)
{
printf("buzz  buzz   buzz.......\n");
printf("press power button to stop(only mobiles)");
//exit(0);
}

void signal_alarm2(int signum)
{
printf("sigint\n");
}

int main()
{
signal(SIGALRM,signal_alarm);
alarm(4);
alarm(1);
while(1)
{
pause();
alarm(1);
}
signal(SIGINT,signal_alarm2);
//while(1);
}
