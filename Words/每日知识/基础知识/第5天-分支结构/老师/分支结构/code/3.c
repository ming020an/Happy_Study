#include <stdio.h>

int main(void)
{
	char c;
	scanf("%c",&c);

	if(c>='A' && c<='Z')
	{
		printf("%c\n",c+32);
	}
	else // 'a'<= c <= 'z'
	{
		printf("%c\n",c-32);
	}
	
	return 0;
}