#include <stdio.h>

int main(void)
{
	int i = 1;
	int sum = 0;
loop:
	sum += i;
	i++;//99  100
	if(i<=100)
	{
		goto loop;
	}
	
	printf("sum=%d\n",sum);
	
	return 0;	
}