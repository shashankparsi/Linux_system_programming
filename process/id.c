#include<unistd.h>
#include<stdio.h>
int main()
{
printf("process id: %d\n",getpid());
printf("parent process id: %d\n",getppid());
printf("real user id: %d\n",getuid());
printf("real effective id: %d\n",geteuid());
printf("real group: %d\n",getgid());
printf("real effective gid: %d\n",getegid());

return 0;
}
