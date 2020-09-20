#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
pid_t pid;
while(1)
{
pid=fork();
perror("fork()");
int fd;
fd=tmpfile();
}
return 0;
}
