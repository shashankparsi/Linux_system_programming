#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/un.h>
int main()
{
const char *SOCK_PATH="/tmp/srv_socket";
char buffer[10000];
int fd,client_fd;
struct sockaddr_un addr,client_addr;
socklen_t addr_len;
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
if(bind(fd,(struct sockaddr*)&addr,sizeof(struct sockaddr_un))==-1)
{
perror("bind failed\n");
return -1;
}
listen(fd,5);
perror("listen");
while(1)
{
int done=0;
client_fd=accept(fd,(struct sockaddr*)&client_addr,&addr_len);
perror("accept");
printf("accept returned: %d\n",client_fd);

do {

int len=recv(client_fd,buffer,1000,0);
perror("receive");
printf("recv buffer: %s\n",buffer);
send(client_fd,buffer,len,0);
perror("send");
printf("send buffer: %s\n",buffer);
}while(!done);
/*read(client_fd,buffer,sizeof(buffer));
printf("buffer from client: %s\n",buffer);*/
close(client_fd);
return 0;
}
}





