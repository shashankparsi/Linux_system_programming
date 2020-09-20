#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char **argv,char **envp)
{
int i;
printf("number of args: %d\n",argc);
for(i=0;i<argc;i++)
{
printf("%d\n",argv[i]);
}
i=0;
while(1)
{
if(envp[i]==NULL)
{
break;
}
printf("%s\n",envp[i]);
i++;
}
}
