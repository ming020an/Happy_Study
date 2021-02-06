#include <stdio.h>

int main(void)
{
	int i,x;
	int n = 0;
	scanf("%d",&x); //12
	while(x)
	{
		i = x%10;//取出个位		
		n = n*10 + i;
		x = x/10;
	}
	printf("%d \n",n);
	
	return 0;
}