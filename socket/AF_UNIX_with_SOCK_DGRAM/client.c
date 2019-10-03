
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 03-oct-2019		*/
/*Filename	: client.c	*/
/*Description	: source file for client application*/
/************************************************************/

/* Included header files */
#include "client.h"

/* Global variable declarations*/


/*main function definition */
int main(int argc,char argv[])
{
struct sockaddr_un cln_addr,svr_addr;
int sfd;
char buf_snd[]="This is client\n";
char buf_rcv[50];

const char *SOCKNAME1="SOCKET1";
const char *SOCKNAME2="SOCKET2";
socklen_t len=sizeof(struct sockaddr_un);

/*Creating client socket*/
sfd=socket(AF_UNIX,SOCK_DGRAM,0);
perror("socket");

/*Assigning 0 to all the structure fields for client*/
memset(&cln_addr,0,sizeof(struct sockaddr_un));
perror("memset");

/*Assigning structure sockaddr_un feilds for client*/
cln_addr.sun_family=AF_UNIX;
strncpy(cln_addr.sun_path,SOCKNAME2,sizeof(cln_addr.sun_path)-1);

/*Binding socket to an address*/
bind(sfd,(struct sockaddr*)&cln_addr,sizeof(struct sockaddr_un));
perror("bind");

/*Construct address of server*/
memset(&svr_addr,0,sizeof(struct sockaddr_un));
svr_addr.sun_family=AF_UNIX;
strncpy(svr_addr.sun_path,SOCKNAME1,sizeof(svr_addr.sun_path)-1);

/*sending message to server*/
sendto(sfd,buf_snd,strlen(buf_snd)+1,0,(struct sockaddr*)&svr_addr,len);
perror("sendto");

/*receiving message from server*/
recvfrom(sfd,buf_rcv,50,0,(struct sockaddr*)&svr_addr,&len);
perror("recvfrom");
printf("Server: %s\n",buf_rcv);

/*Remove socket file*/
remove(SOCKNAME2);
sleep(5);

/*closing the socket*/
close(sfd);
perror("close");
return 0;
}
