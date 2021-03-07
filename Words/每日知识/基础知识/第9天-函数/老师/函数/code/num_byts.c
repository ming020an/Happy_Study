#include <stdio.h>

int num_byts(int num)
{
	int i, n = 0;
	for(i=0;i<32;i++)
	{
		/*
		if(num>>i & 1)
		{
			n++;
		}
		*/
		if(num & 1<<i)
		{
			n++;
		}
	}
	
	return n;
}



int main(void)
{
	int n;
	scanf("%x",&n);
	int a = num_byts(n);
	printf("%d\n",a);
}