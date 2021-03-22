#include <stdio.h>

int test(int p[])
{
	printf("p:%p\n",p);
	p[55] = 1024;
}

int main(void)
{
	int a[100] = {1,2,3,4,5,6,7,8,9};
	printf("num a:%d\n",a);
	printf("a:%p\n",a);
	printf("调用前:a[55] == %d\n",a[55]);
	test(a);
	printf("调用后:a[55] == %d\n",a[55]);
}

/*
	参数的传递是不是一个赋值过程?????
	a----->是不是数组的首地址???
	把 a 的值赋值给了 p
*/