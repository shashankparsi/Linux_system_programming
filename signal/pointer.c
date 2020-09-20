#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
void signal_handler(int signum)
{
printf("%s\n",__func__);
exit(0);
}
int main()
{
int *a=NULL;
signal(SIGSEGV,signal_handler);
*a=5;
return 0;
}
