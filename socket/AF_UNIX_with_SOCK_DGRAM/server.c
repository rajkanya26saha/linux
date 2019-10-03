
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 03-oct-2019		*/
/*Filename	: server.c	*/
/*Description	: source file for server application*/
/***********************************************************/

/* Included header files */
#include "server.h"

/* Global variable declarations*/


/*main function definition */
int main(int argc,char argv[])
{
struct sockaddr_un svr_addr,cln_addr;
int sfd;
char buf_snd[]="This is server\n";
char buf_rcv[50];
const char *SOCKNAME="SOCKET1";
socklen_t len=sizeof(struct sockaddr_un);

/*Creating server socket*/
sfd=socket(AF_UNIX,SOCK_DGRAM,0);
perror("socket");

/*Assigning 0 to all the structure fields*/
memset(&svr_addr,0,sizeof(struct sockaddr_un));
perror("memset");

/*Assigning structure sockaddr_un feilds*/
svr_addr.sun_family=AF_UNIX;
strncpy(svr_addr.sun_path,SOCKNAME,sizeof(svr_addr.sun_path)-1);

/*Binding socket to an address*/
bind(sfd,(struct sockaddr*)&svr_addr,sizeof(struct sockaddr_un));
perror("bind");

/*receiving message from client*/
recvfrom(sfd,buf_rcv,50,0,(struct sockaddr*)&cln_addr,&len);
perror("recvfrom");
printf("Client: %s\n",buf_rcv);

/*sending message to client*/
sendto(sfd,buf_snd,strlen(buf_snd)+1,0,(struct sockaddr*)&cln_addr,len);
perror("sendto");

/*Remove socket file*/
remove(SOCKNAME);
sleep(5);
/*closing the socket*/
close(sfd);
perror("close");
return 0;
}

