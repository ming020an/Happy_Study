#include <stdio.h>

int main(void)
{
	int m,n,i=1;
	scanf("%d%d",&n,&m);
	while(i<=n)
	{
		if(i%m !=0 )
		{
			printf("*");
		}
		else
		{
			printf("*\n");
		}
		i++;
	}
	
	return 0;
}