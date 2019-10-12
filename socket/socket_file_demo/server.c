
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 12-oct-2019		*/
/*Filename	: server.c	*/
/*Description	: source file for server application*/
/***********************************************************/

/* Included header files */
#include "server.h"

/* Global variable declarations*/


/*main function definition */
int main(int argc,char *argv[])
{
struct sockaddr_in svr_addr,cln_addr;
int soc_fd,fd1,fd2;
char server_msg[2734]="";
char client_msg[2578]="";
socklen_t len=sizeof(struct sockaddr_in);
soc_fd=socket(AF_INET,SOCK_DGRAM,0);
fd2=open("f1",O_RDONLY,0664);

memset(&svr_addr,0,len);

svr_addr.sin_family=AF_INET;
svr_addr.sin_port=htons(atoi(argv[1]));
inet_pton(AF_INET,argv[2],&svr_addr.sin_addr.s_addr);

//bind a name to the socket
bind(soc_fd,(struct sockaddr*)&svr_addr,len);

fd1=open("f2",O_WRONLY,0664);

//waiting to receive msg from client side
recvfrom(soc_fd,client_msg,2578,0,(struct sockaddr*)&cln_addr,&len);

write(fd1,client_msg,2578);

printf("Client: %s\n",client_msg);

sleep(3);
read(fd2,server_msg,2734);

//sending msg to client
sendto(soc_fd,server_msg,strlen(server_msg)+1,0,(struct sockaddr*)&cln_addr,len);
sleep(3);
close(soc_fd);
close(fd1);
close(fd2);
return 0;
}
