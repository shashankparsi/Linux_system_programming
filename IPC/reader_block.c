#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void handler(int signum)
{
printf("no one is reading\n");
}

int main()
{
char writebuffer[]="shashank";
signal(SIGPIPE,handler);
pid_t pid;
int filedes[2];
pipe(filedes);
pid=fork();
if(pid>0)
{
printf("parent process: %d\n",getpid());
close(filedes[0]);
}
else
{
printf("child process: %d\n",getpid());
write(filedes[1],"one",3);
sleep(2);
write(filedes[1],"two",3);
close(filedes[1]);
}
return 0;
}
