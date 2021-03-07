/*计算出一个数二进制中有几个1*/
#include<stdio.h>
int my_yw(int a)
{
	int i=0,num=0;
	 int b=1,sum=0;
	num=(sizeof(a)*8-1);
	for(i=0;i<num;i++)
	{
	//优先级问题。
		if((a&b)!=0)
		{
			sum++;
		}
		b=b <<1;
		printf("sum=%d\n",sum);
		//printf("%d\n",b);
	}
	printf("%d\n",sum);
	return sum;
}
int main(void)
{	
	int a=my_yw(5);
	
	printf("%d\n",a);
	return 0;
}