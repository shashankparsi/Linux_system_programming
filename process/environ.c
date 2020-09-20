#include<stdio.h>
#include<unistd.h>
extern char **environ;
int main(int argc,char **argv)
{
int index=0;
printf("number of args: %d\n",argc);
while(environ[index]!=NULL)
{
printf("%s\n",environ[index]);
index++;
}
return 0;
}
