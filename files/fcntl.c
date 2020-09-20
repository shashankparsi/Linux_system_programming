#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char **argv)
{
int retval;
retval=fcntl(atoi(argv[1]),F_GETFL,0);
printf("retval: %d\n",retval);

switch(retval & O_ACCMODE)
{
case O_RDONLY: 
printf("read only\n");
break;
case O_RDWR:
printf("read and write\n");
break;
case O_WRONLY:
printf("write only\n");
break;
default: 
fprintf(stderr, "unknown access mode\n");
exit(1);
break;
return 0;
}
}
