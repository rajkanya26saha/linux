
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 11-oct-2019		*/
/*Filename	: server.c	*/
/*Description	: source file for server application*/
/************************************************************/

/* Included header files */
#include "server.h"

/* Global variable declarations*/



/*main function definition */
int main(int argc,char *argv[])
{
struct sockaddr_in svr_addr,cln_addr[5];
int sfd,afd;
char buf_snd[]="This is server\n";
char buf_rcv[50];
socklen_t len=sizeof(struct sockaddr_in);

/*Creating server socket*/
sfd=socket(AF_INET,SOCK_STREAM,0);
perror("socket");

/*Assigning 0 to all the structure fields*/
memset(&svr_addr,0,len);
perror("memset");

/*Assigning structure sockaddr_un feilds*/
svr_addr.sin_family=AF_INET;
svr_addr.sin_port=htons(atoi(argv[1]));
inet_pton(AF_INET,argv[2],&svr_addr.sin_addr.s_addr);

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

/*closing the socket*/
close(afd);
perror("close_afd");

close(sfd);
perror("close_sfd");

return 0;
}
