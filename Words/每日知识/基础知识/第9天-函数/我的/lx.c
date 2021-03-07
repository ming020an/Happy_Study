/*粘贴*/
#include<stdio.h>
#include<string.h>
#define N 100
char *my_strcat(char a[],char b[])
{
	int i;
	int j=strlen(b);
	for(i=0;i<=j;i++)
	{
		a[strlen(a)+i]=b[i];
	}
	return a;
}
int main(void)
{	int k;
	char a[N]="abcdefghrj";
	char b[]="asd";
	my_strcat(a,b);
	for(k=0;k<20;k++)
	printf("%c",a[k]);
	printf("\n");
}
