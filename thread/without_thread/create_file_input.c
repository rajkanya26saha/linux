#include<stdio.h>

int main()
{
int arr[1000];
int i;
FILE *fp=fopen("file_input","w");
for(i=1;i<=1000;i++)
{
	arr[i]=i;
fprintf(fp,"%d ",arr[i]);
}
fclose(fp);
return 0;
}
