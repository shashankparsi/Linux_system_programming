#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void handler(int signum)
{
printf("im in handler\n");
exit(0);
}

int main()
{
int a=5;
signal(SIGFPE,handler);
a=5/0;
return 0;
}
