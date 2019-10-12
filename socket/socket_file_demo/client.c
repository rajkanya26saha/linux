
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
struct sockaddr_in svr_addr;
int soc_fd,fd1,fd2;
char client_msg[2578]="";
char server_data[2732]="";
socklen_t len=sizeof(struct sockaddr_in);
soc_fd=socket(AF_INET,SOCK_DGRAM,0);

fd2=open("f1",O_WRONLY,0664);

memset(&svr_addr,0,len);
svr_addr.sin_family=AF_INET;
svr_addr.sin_port=htons(atoi(argv[1]));
inet_pton(AF_INET,argv[2],&svr_addr.sin_addr.s_addr);

fd1=open("f2",O_RDONLY,0664);
read(fd1,client_msg,2578);
//sending msg to server
sendto(soc_fd,client_msg,strlen(client_msg)+1,0,(struct sockaddr*)&svr_addr,len);

//sleep(2);
//waiting to receive msg from server side
recvfrom(soc_fd,server_data,2732,0,(struct sockaddr*)&svr_addr,&len);
write(fd2,server_data,2732);
printf("Server: %s\n",server_data);

sleep(5);
close(soc_fd);
close(fd1);
close(fd2);
return 0;
}

