#include <stdio.h>

int main(void)
{	
	int i = 0;
	int sum = 0;
	do
	{
		i++;//单语句 do只管到这一句,后面应该是一个while了
		sum += i;
	}
	while(i<100);
			
	/*
		5.c: In function ‘main’:
		5.c:9:3: error: expected ‘while’ before ‘sum’
		   sum += i;
		   ^

	*/
	printf("%d\n",sum);
}