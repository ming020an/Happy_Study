/*取最大值*/
#include<stdio.h>
int my_max(int a,int b)
{
	if(b>a)
	{
		a=a^b;
		b=a^b;
		a=a^b;
	}
	printf("%d\n",a);
	return a;
}
int main(void)
{	
	my_max(5,6);
	return 0;
}