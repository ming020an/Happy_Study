#include <stdio.h>
#define N 10

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

/*
	main函数是c语言程序执行的开始
	一般main函数中只管编写程序的流程代码
		也就是说,main函数只管这个程序要做什么事情
		而这些事情要如何做,那么都交个"别人"了  ---->函数
*/
int main(void)
{
	int a[N] = {1,2,3,4,5,6,7,8,9,0};
	int b[50] = {0};
	print(a,0);
	print(b,10);

	
	return 0;	
}