#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
int fd;
int offset;
fd=open("hello.txt",O_CREAT|O_RDWR|O_APPEND,0644);
if(fd<0)
{
printf("open failed\n");
}
printf("fd=%d\n",fd);

write(fd,"AAAAAAA",10);
offset=lseek(fd,0,SEEK_CUR);
printf("file offset pos after writing AAAAAAA: %d\n",offset);

write(fd,"aaaaaa",5);
offset=lseek(fd,1,SEEK_SET);
printf("file offset after writing aaaaaa: %d\n",offset);




return 0;
}
