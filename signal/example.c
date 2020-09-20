#include<stdio.h>
#include<unistd.h>

int main()
{
printf("my process id: %d\n",getpid());
int time=60;
while(time--)
{
write(1,".",1);
sleep(1);
}
write(1,"DONE",5);
return 0;
}

