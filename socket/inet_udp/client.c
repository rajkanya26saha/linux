	
/************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 12-oct-2019		*/
/*Filename	: client.c	*/
/*Description	: source file for client application*/
/***********************************************************/

/* Included header files */
#include "client.h"

/* Global variable declarations*/


/*main function definition */
int main(int argc,char *argv[])
{
struct sockaddr_in svr_addr,cln_addr;
int soc_fd;
char server_msg[100];
char client_msg[100];
socklen_t len=sizeof(struct sockaddr_in);

soc_fd=socket(AF_INET,SOCK_DGRAM,0);
/*construct address of server*/
memset(&svr_addr,0,len);
svr_addr.sin_family=AF_INET;
svr_addr.sin_port=htons(atoi(argv[1]));
inet_pton(AF_INET,argv[2],&svr_addr.sin_addr.s_addr);

while(1)
{
scanf("%[^\n]",client_msg);
//sending msg to server
sendto(soc_fd,client_msg,strlen(client_msg)+1,0,(struct sockaddr*)&svr_addr,len);
//sleep(2);
if((strcmp(client_msg,"Good bye")==0))
break;
//waiting to receive msg from server side
recvfrom(soc_fd,server_msg,100,0,(struct sockaddr*)&svr_addr,&len);
printf("\033[01;33m");
printf("Server: %s\n",server_msg);
printf("\033[0m");
getchar();
}
close(soc_fd);
return 0;
}

