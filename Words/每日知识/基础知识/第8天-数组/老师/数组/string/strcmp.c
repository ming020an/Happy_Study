#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[10] = "Hehehe";
	char b[10] = "hahaha";
	int t = strcmp(a,b);
	if(t>0)
	{
		printf("a>b\n");
	}
	else if(t < 0)
	{
		printf("a<b\n");
	}
	else
		printf("a == b\n");
	
	return 0;
}