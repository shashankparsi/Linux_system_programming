#include<stdio.h>
#include<unistd.h>
int main()
{
char buffer[256];
int length;
length=read(STDIN_FILENO,buffer,sizeof(buffer));
buffer[length]='\0';
printf("data from console is : %s\n",buffer);
write(STDOUT_FILENO,buffer,sizeof(buffer));
printf("data written to STDOUT is : %s\n",buffer);
write(STDERR_FILENO,buffer,sizeof(buffer));
printf("data written to STDERR is :%s\n",buffer);
return 0;
}
