#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int filedes[2]; 
int retval=pipe(filedes);
if(retval==0)
{
printf("pipe connected\n");
printf("read: %d and write: %d and retval: %d\n",filedes[0],filedes[1],retval);
}
else
{
printf("pipe failed\n");
}
return 0;
}

