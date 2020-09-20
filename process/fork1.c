#include<stdio.h>
#include<unistd.h>
#include<string.h>
int gvar=10;
char buf[]="writing to STDOUT\n";
int main()
{
int lvar=20;
pid_t pid;
write(STDOUT_FILENO,buf,strlen(buf)-1);
if(pid==fork()<0)
{
printf("fork error\n");
}
else if (pid==0)
{
++gvar;
++lvar;
printf("%d\n",pid);
}
else
{
sleep(2);
}
printf("pid: %d\t gvar: %d\t lvar: %d\n",getpid(),gvar,lvar);
return 0;
}
