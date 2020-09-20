#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int res;
res=mkfifo("my_fifo",0777);
if(res==0)
{
printf("fifo created\n");
}
else
{
printf("failed\n");
}
unlink("my_fifo");
}
