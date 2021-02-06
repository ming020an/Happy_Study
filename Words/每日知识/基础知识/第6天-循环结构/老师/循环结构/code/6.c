#include <stdio.h>

/*
	利用do while 求 n! (n从键盘输入)
	n! = n*(n-1)*(n-2)*(n-3)*.....*1;
*/
int main(void)
{
	int i = 0;
	int n;
	long long s = 1;
	scanf("%d",&n);
	
	do
	{
		i++;  //  1     2        3       4
		s *= i;// 1*1 1*1*2   1*2*3  1*2*3*4
	}while(i < n);
	
	printf("%d != %lld\n",n,s);
	
	return 0;
}

