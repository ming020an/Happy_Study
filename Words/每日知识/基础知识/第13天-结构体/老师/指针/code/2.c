#include <stdio.h>

void swap(int *p,int *q)
{
	int t;
	t = *p; // 把 *p (a) 的值赋值给t
	*p = *q; // *p左值   *q右值
	*q = t; //*q 左值
}

int main(void)
{
	int a = 3;
	int b = 4;
	swap(&a,&b);
	printf("a:%d b:%d\n",a,b);
}