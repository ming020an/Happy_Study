/*求1-100的和*/
#include <stdio.h>

int main(void)
{
	int i = 1;
	int sum = 0;

	/*
		for的执行：
		先执行语句1：i=1;
		然后判断语句2：i<=100;
		如果满足判断，则执行循环体：sum += i;
		再执行语句3：i++；
		循环判断语句2
		直到语句2不满足
	*/
	for(i=1;i<=100;i++)
	{
		sum += i;
		//sum = sum + i;
	}
	
	printf("%d\n",sum);
	
	return 0;
}