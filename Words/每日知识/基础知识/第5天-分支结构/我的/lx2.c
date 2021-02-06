#include<stdio.h>
int main()
{
	char a;
	scanf("%c",&a);
	if(a>='a'&&a<='z')
	printf("%c\n",a-32);
	if(a>='A'&&a<='Z')
	printf("%c\n",a+32);
	
	return 0;

}