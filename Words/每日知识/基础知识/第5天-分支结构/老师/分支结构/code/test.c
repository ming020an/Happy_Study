#include <stdio.h>

int main(void)
{
	int a,b,c;
	int tmp;
	printf("please input 3 num\n");
	scanf("%d%d%d",&a,&b,&c);
	
	if(a>b)
	{
		/*用中间变量交换*/
		tmp = a;
		a = b;
		b = tmp;
	}//确保 a 比 b 小
	//printf("%d %d %d\n",a,b,c);
	//sleep(10);
	
	if(a > c)
	{
		/*用 按位异或 交换*/
		a = a^c;
		c = a^c;
		a = a^c;
	}//确保 a 是三个数中最小的数
	//printf("%d %d %d\n",a,b,c);
	//sleep(10);
	
	if(b > c)
	{
		/*用 算术运算交换*/
		b = b + c;
		c = b - c; // --> b + c - c;  ---》 c = b
		b = b - c; // --> b + c - b；
		
	}//确保b比c小
	printf("%d<%d<%d\n",a,b,c);
	
	return 0;
}