#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
//#include<delay.h>
#include<signal.h>
#include<sys/types.h>
void sig_handler(int signum)
{
int childstatus;
printf("hello im signal\n");
//return 0;
}
int global_variable=100;
char buf[]="linux is easy";
int main()
{
int childstatus;
int local_variable=101;
write(STDOUT_FILENO,buf,sizeof(buf)-1);
perror("write");
pid_t pid;
pid=fork();
if(pid==0)
{
printf("child process created\n");
sleep(10);
global_variable++;
local_variable++;
//sleep(10);
}
else
{
printf("parent process created\n");
signal(SIGCHLD,sig_handler);
wait(&childstatus);
printf("childstatus=%d\n",childstatus);
printf("wexitstatus=%d\n",WEXITSTATUS(childstatus));
//signal(SIGINT,sig_handler);

//sleep(3);
}
printf("global_variable=:%d\t and local_variable=%d\n",global_variable,local_variable);

return 0;
}
