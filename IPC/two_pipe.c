#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int filedes1[2],filedes2[2];
char writebuffer[30]="hello shashank parsi";
char readbuffer[100];
pipe(filedes1);
pipe(filedes2);
pid_t pid;
pid=fork();
if(pid==0)
{
printf("child process executing...: %d\n",getpid());
write(filedes1[1],writebuffer,sizeof(writebuffer));
memset(writebuffer,0,sizeof(writebuffer));
strcpy(writebuffer,"hello parent..!!");
printf("written to filedes1[1]: %s\n",writebuffer);
read(filedes2[0],readbuffer,sizeof(readbuffer));
//memset(writebuffer,0,sizeof(writebuffer));
//strcpy(writebuffer,"hello parent..!!");
printf("data written: %s\n",readbuffer);
}
else
{
printf("parent process executing: %d\n",getpid());
write(filedes2[1],writebuffer,sizeof(writebuffer));
printf("data written: %s\n",writebuffer);
read(filedes1[0],readbuffer,sizeof(readbuffer));
printf("data read: %s\n",readbuffer);
}
return 0;
}

