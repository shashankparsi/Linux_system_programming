#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
int main()
{
key_t key;
int msgid;
key=ftok("hello.txt",66);
printf("key: %d\n",key);
msgid=msgget(key,IPC_CREAT);
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
