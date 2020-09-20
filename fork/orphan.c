#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
pid_t pid;
if(pid==0)
{
printf("child created: %d\n",getpid());
sleep(20);
}
else
{
printf("parent created: %d\n",getpid());
exit(EXIT_SUCCESS);
}
return 0;
}
