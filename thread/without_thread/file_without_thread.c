
/*************************************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 05-nov-2019		*/
/*Filename	: file_without_thread.c	*/
/*Description	: source file to demostrate application without implementating thread*/
/*************************************************************************************/

/* Included header files */
#include "file_without_thread.h"

/* Global variable declarations*/


/*main function definition */
int main(int argc,char *argv[])
{
	int num[1244];	//when using EOF
	int i;
	int x;
FILE *fp=fopen(argv[1],"r");

if(fp==NULL)
{
printf("Cannot opeen file\n");
exit(0);
}

for(i=0;num[i]!=EOF;i++)
{
fscanf(fp,"%d",&num[i]);
x=num[i];
//printf("num[%d]=%d\n",i,num[i]);
factorial(x);
}
fclose(fp);
return 0;
}

void factorial(int x)
{
int fact[MAX],i;
fact[0]=1;
int fact_size=1;
for(i=2;i<=x;i++)
	fact_size=multiply(i,fact,fact_size);
printf("Factorial of %d: ",x);
for(i=fact_size-1;i>=0;i--)
	printf("%d",fact[i]);
	printf("\n");
}

int multiply(int x,int fact[],int fact_size)
{
int carry=0,i;
for(i=0;i<fact_size;i++)
{
int mul=fact[i]*x+carry;
fact[i]=mul%10;
carry=mul/10;
}
while(carry)
{
fact[fact_size]=carry%10;
carry=carry/10;
fact_size++;
}
return fact_size;
}
