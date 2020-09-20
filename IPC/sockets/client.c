#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/un.h>
int main()
{
char buffer[10000];
const char *SOCK_PATH="/tmp/srv_socket";
int fd;
struct sockaddr_un addr;
fd=socket(AF_UNIX,SOCK_STREAM,0);
if(fd<0)
{
printf("socket failed\n");
return -1;
}
printf("socket returned: %d\n",fd);
memset(&addr,0,sizeof(struct sockaddr_un));
addr.sun_family=AF_UNIX;
strncpy(addr.sun_path,SOCK_PATH,sizeof(addr.sun_path)-1);
/*if(bind(fd,(struct sockaddr*)&addr,sizeof(struct sockaddr_un))==-1)
{
perror("bind failed\n");
return -1;
}*/

if(connect(fd,(struct sockaddr *)&addr,sizeof(struct sockaddr_un))==-1)
perror("connect");
//write(fd,buffer,sizeof(buffer));
//close(fd);

while(printf(" > "),fgets(buffer,1000,stdin),!feof(stdin))
{
send(fd,buffer,strlen(buffer),0);
perror("send");
recv(fd,buffer,1000,0);
perror("recv");
printf("echo > %s:\n",buffer);

}
return 0;
}





