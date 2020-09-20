#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char **argv, char **envp)
{

char *myname="MYNAME=shashank";
const char *name="MYNAME";
const char *value="aabbccdd";
	
if(putenv(myname)!=0)
{
printf("cannot set env\n");
}
else
{
printf("getenv: MYNAME=%s\n",getenv("MYNAME"));
}
if(setenv(name,value,1)!=0)
{
printf("failed to set env\n");
}
else
{
printf("getenv MYNAME=%s\n",getenv("MYNAME"));
}


return 0;
}
