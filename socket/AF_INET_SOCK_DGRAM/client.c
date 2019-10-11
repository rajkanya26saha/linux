
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 11-oct-2019		*/
/*Filename	: client.c	*/
/*Description	: source file for client application*/
/************************************************************/

/* Included header files */
#include "client.h"

/* Global variable declarations*/


/*main function definition */
int main(int argc,char *argv[])
{
struct sockaddr_in cln_addr,svr_addr;
int sfd;
char buf_snd[]="This is client\n";
char buf_rcv[50];


socklen_t len=sizeof(struct sockaddr_in);

/*Creating client socket*/
sfd=socket(AF_INET,SOCK_DGRAM,0);
perror("socket");

/*Construct address of server*/
memset(&svr_addr,0,len);
svr_addr.sin_family=AF_INET;
svr_addr.sin_port=htons(50000);
inet_pton(AF_INET,"192.168.43.164",&svr_addr.sin_addr.s_addr);

/*sending message to server*/
sendto(sfd,buf_snd,strlen(buf_snd)+1,0,(struct sockaddr*)&svr_addr,len);
perror("sendto");

/*receiving message from server*/
recvfrom(sfd,buf_rcv,50,0,(struct sockaddr*)&svr_addr,&len);
perror("recvfrom");

printf("Server: %s\n",buf_rcv);

sleep(5);

/*closing the socket*/
close(sfd);
perror("close");
return 0;
}
