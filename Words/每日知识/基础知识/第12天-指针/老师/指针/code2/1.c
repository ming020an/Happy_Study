#include <stdio.h>

int main(void)
{
	int t = 5;
	//typeof(t) *k = t;
	int *k = &t;
	
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	//typeof(a) * p  = a;//类型不兼容
	int (*p)[10] = &a; //a是指向int型的指针
					//p是指向int[10]的指针
	printf("%p\n",&a);
	printf("%p\n",p);
}
