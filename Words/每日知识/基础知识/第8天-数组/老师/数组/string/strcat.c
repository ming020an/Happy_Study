#include <stdio.h>
#include <string.h>

int main(void)
{
	/**
	char a[10] = "he";
	char b[10] = "nihaoa!!";
	strncat(a,b,7);
	printf("a:%s\nb:%s\n",a,b);
	printf("%d\n",strlen(a));
	**/
	
	char a[100] = {"hello nihaoa zhe ge shijie"};
	char *p = strstr(a,"h");
	if(p == NULL)
	{
		printf("no the needle\n");
	}
	else
	{
		printf("%s\n",p);
	}
	return 0;
}