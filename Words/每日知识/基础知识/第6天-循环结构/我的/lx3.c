#include<stdio.h>
int main(void)
{
	int i=0;
	int sum=0;
	while(i<=100)
	{
		i=i+2;
		sum+=i;
	}
	printf("%d\n",sum);
	return 0;
}