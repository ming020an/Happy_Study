#include<stdio.h>

int main(void)
{
	int a[10];
	int *p = NULL;
	*p = 10; //错误,因为p指向一个空地址,而空地址是不能被操作的
	p = a; //把a的值赋值给p  p指向了a所指向的空间(&a[0])
	p = &a[4];
	p = &a; //这里应该要一个指向 typeof(a)类型的指针
			//但 p是一个指向 int 型的指针
}