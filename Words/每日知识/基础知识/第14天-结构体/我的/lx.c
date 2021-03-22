#include<stdio.h>
#include<string.h>
#define N 20
int main ()
{
	int i,b;
	char a[N]={0};
	gets(a);
	b=strlen(a);
	//char *a="abcdef";
	char *p= a+b-1;
	for(i=0;i<b;i++)
	{
		printf("%c ",*(p--));
	}
	return 0;
}