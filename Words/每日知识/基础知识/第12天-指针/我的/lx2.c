#include<stdio.h>
void my_strcmp(char * a,char * b);
int main(void)
{
	char *a="abcdefg";
	char *b="abcdefh";
	 my_strcmp(a,b);
	
	return 0;
}

void my_strcmp(char * a,char * b)
{
	int c=0;
	if(*a-*b>0)
	{
	 printf("a>b\n");
	}
	else if(*a-*b<0)
	{
	 printf("a<b\n");
	}
	else
	{
		*a++;
		*b++;
		return my_strcmp(a, b);
	}
}