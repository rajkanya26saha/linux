
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 04-oct-2019		*/
/*Filename	: server.c	*/
/*Description	: source file for server application*/
/************************************************************/

/* Included header files */
#include "server.h"

/* Global variable declarations*/



/*main function definition */
int main(int argc,char argv[])
{
struct sockaddr_un svr_addr,cln_addr[5];
int sfd,afd;
char buf_snd[]="This is server\n";
char buf_rcv[50];
const char *SOCKNAME="SOCKET1";
socklen_t len=sizeof(struct sockaddr_un);

/*Creating server socket*/
sfd=socket(AF_UNIX,SOCK_STREAM,0);
perror("socket");

/*Assigning 0 to all the structure fields*/
memset(&svr_addr,0,len);
perror("memset");

/*Assigning structure sockaddr_un feilds*/
svr_addr.sun_family=AF_UNIX;
strncpy(svr_addr.sun_path,SOCKNAME,sizeof(svr_addr.sun_path)-1);

/*Binding socket to an address*/
bind(sfd,(struct sockaddr*)&svr_addr,len);
perror("bind");

/*Allowing incoming connection from client*/
listen(sfd,5);
perror("listen");

/*Accepting connection from client*/
afd=accept(sfd,(struct sockaddr*)&cln_addr[0],&len);
perror("accept");

/*receiving message from client*/
recv(afd,buf_rcv,50,0);
perror("recv");
printf("Client: %s\n",buf_rcv);

/*sending message to client*/
send(afd,buf_snd,16,0);
perror("send");

sleep(5);

/*Remove socket file*/
remove(SOCKNAME);

/*closing the socket*/
close(afd);
perror("close_afd");

close(sfd);
perror("close_sfd");

return 0;
}
