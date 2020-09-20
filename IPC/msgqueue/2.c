#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
int main()
{
key_t key;
int msgid;
key=ftok("hello.txt",66);
printf("key: %d\n",key);
msgid=msgget(IPC_PRIVATE,S_IRUSR|S_IWUSR);
if(msgid<0)
{
printf("msgget failed\n");
}
else
{
printf("msgget success\n");
}
printf("msgid: %d\n",msgid);
return 0;
}
