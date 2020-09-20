#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void hello(int signalnum)
{
//sleep(5);
printf("hello shashank\n");
}
int main()
{
signal(SIGUSR1,hello);
//sleep(5);
raise(SIGUSR1);
return 0;
}

