#include<sys/signal.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
sigset_t mask_set;
sigemptyset(&mask_set);

sigaddset(&mask_set,SIGINT);
sigaddset(&mask_set,SIGQUIT);

if(sigismember(&mask_set,SIGINT))
{
printf("SIGINT is a member\n");
}
else
{
printf("SIGINT is not a member\n");
}

sigdelset(&mask_set,SIGQUIT);

if(sigismember(&mask_set,SIGQUIT))
{
printf("SIGQUIT is a member\n");
}
else
{
printf("SIGQUIT is not a member\n");
}

return 0;
}
