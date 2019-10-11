
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 11-oct-2019		*/
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
int sfd;
char buf_snd[]="This is server\n";
char buf_rcv[50];
socklen_t len=sizeof(struct sockaddr_in);

/*Creating server socket*/
sfd=socket(AF_INET,SOCK_DGRAM,0);
perror("socket");

/*Assigning 0 to all the structure fields*/
memset(&svr_addr,0,len);
perror("memset");

/*Assigning structure sockaddr_un feilds*/
svr_addr.sin_family=AF_INET;
svr_addr.sin_port=htons(50000);
inet_pton(AF_INET,"192.168.43.164",&svr_addr.sin_addr.s_addr);

/*Binding socket to an address*/
bind(sfd,(struct sockaddr*)&svr_addr,len);
perror("bind");

/*receiving message from client*/
recvfrom(sfd,buf_rcv,50,0,(struct sockaddr*)&cln_addr,&len);
perror("recvfrom");
printf("Client: %s\n",buf_rcv);

/*sending message to client*/
sendto(sfd,buf_snd,strlen(buf_snd)+1,0,(struct sockaddr*)&cln_addr,len);
perror("sendto");


sleep(5);
/*closing the socket*/
close(sfd);
perror("close");
return 0;
}

