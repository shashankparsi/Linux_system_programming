#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int fd;
int childstatus;
char buf[2];
pid_t pid;
printf("process id: %d\n",getpid());
fd=open("hello.txt",O_RDONLY);
pid=fork();

if(pid==0)
{
printf("child process has been created with process id: %d\n",getpid());
read(fd,buf,2);
lseek(fd,3,SEEK_SET);
printf("buffer: %s\n",buf);
printf("child: %c\n",buf[0]);
printf("child: %c\n",buf[1]);
}
else
{
printf("parent process has been created with process id: %d\n",getppid());
wait(&childstatus);
read(fd,buf,2);
printf("data in buffer: %s\n",buf);
printf("parent: %c\n",buf[0]);
printf("parent: %c\n",buf[1]);
}
close(fd);
return 0;
}
