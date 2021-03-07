#include <stdio.h>

/*
	print 打印数组的函数
		a[]   要打印的数组
		n     要打印的个数
*/
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	//return;  //这样是可以的
	//return 0; //这个是不对的,因为print函数的返回值类型是 void,不需要返回值
}