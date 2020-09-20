#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
{
printf("child process created:%d\n",getpid());
exit(0);
}
else
{
printf("parent process created: %d\n",getpid());
//sleep(10);
while(1)
{
}
}
return 0;
}
