#include<unistd.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
pid_t pid;
pid=fork();
if(pid>0)
{
printf("parent process creatd: %d\n",getpid());
}
else if(pid==0)
{
sleep(10);
printf("child process created: %d\n",getpid());
//sleep(10);
}
return 0;
}
