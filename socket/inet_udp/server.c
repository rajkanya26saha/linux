	
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
int soc_fd;
char server_msg[100];
char client_msg[100];
socklen_t len=sizeof(struct sockaddr_in);

soc_fd=socket(AF_INET,SOCK_DGRAM,0);
/*Assigning 0 to all the structure feilds*/
memset(&svr_addr,0,len);

/*Assigning structure sockaddr_in fields*/
svr_addr.sin_family=AF_INET;
svr_addr.sin_port=htons(atoi(argv[1]));
inet_pton(AF_INET,argv[2],&svr_addr.sin_addr.s_addr);

//bind a name to the socket
bind(soc_fd,(struct sockaddr*)&svr_addr,len);
while(1)
{
//waiting to receive msg from client side
recvfrom(soc_fd,client_msg,100,0,(struct sockaddr*)&svr_addr,&len);
printf("\033[1;31m");
printf("Client: %s\n",client_msg);
printf("\033[0m");
scanf("%[^\n]",server_msg);
//sending msg to client
sendto(soc_fd,server_msg,strlen(server_msg)+1,0,(struct sockaddr*)&svr_addr,len);

if((strcmp(server_msg,"Good bye")==0))
break;
getchar();
}
close(soc_fd);
return 0;
}

