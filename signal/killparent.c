#include<signal.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t child,parent;
child=fork();
if(child==0)
{
printf("child created successfully: %d\n",getpid());

printf("getting parent process id: %d\n",getppid());

parent=getppid();
kill(parent,SIGUSR1);
exit(0);
}
else
{
wait(NULL);
printf("waiting for child to terminate....\n");
}
return 0;
}
