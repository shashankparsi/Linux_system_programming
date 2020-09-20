#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
int filedes[2];
pipe(filedes);
char buffer[]="hello shashank";
pid_t pid;
pid=fork();
if(pid==0)
{
printf("in child process: %d\n",getpid());
read(filedes[0],buffer,sizeof(buffer));
printf("data read: %s\n",buffer);
close(filedes[0]);
}
else
{
printf("in parent process: %d\n",getppid());
write(filedes[1],buffer,sizeof(buffer));
printf("data written: %s\n",buffer);
close(filedes[1]);
}
return 0;
}

