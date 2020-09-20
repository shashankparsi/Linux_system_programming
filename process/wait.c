#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int k=20;
pid_t pid;
int childstatus;
pid=fork();
if(pid==0)
{
printf("child process created: %d\n",getpid());
k=44;
printf("child process exited\n");
exit(100);
}
else
{
printf("parent process id: %d\n",getpid());
printf("pid of newly created child: %d\n",pid);
printf("*** value of k=%d\n",k);
wait(&childstatus);
printf("childstatus: %d\n",childstatus);
printf("childstaus: %d\n",WEXITSTATUS(childstatus));
//return 0;
}
return 0;

}
