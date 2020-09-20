#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char**argv,char **envp)
{
int i=0;
printf("number of args: %d\n",argc);
for(i=0;i<argc;i++)
{
printf("%d %s\n",i,argv[i]);
}

char *env;
env=getenv("HOME");
printf("%s\n",env);
env=getenv("PATH");
printf("%s\n",env);

return 0;
}
