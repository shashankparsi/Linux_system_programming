#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>


void file_des(int fd)
{
int val;
val=fcntl(fd,F_GETFL,0);
switch(val&O_ACCMODE)
{
case O_RDONLY:
printf("read property\n");
break;
case O_RDWR:
printf("read and write property\n");
break;
case O_WRONLY:
printf("write property\n");
break;
default:
fprintf(stderr,"unknown");
exit(0);
}
}
int main()
{
int retval;
int filedes[2];
char writebuf[]="shashank";
char readbuf[100];
pipe(filedes);
write(filedes[0],writebuf,sizeof(writebuf));
printf("data written to write buffer: %s\n",writebuf);
read(filedes[1],readbuf,sizeof(readbuf));
printf("data read: %s\n",readbuf);
printf("printing flags of file des 0...\n");
file_des(filedes[0]);
printf("printing flags of filedes 1..\n");
file_des(filedes[1]);
close(filedes[0]);
close(filedes[1]);
return 0;
}

