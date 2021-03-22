#include <stdio.h>

int main(void)
{
	int a = 5;
	int *p;
	p = &a;//p指向a,p保存a的地址
	*p = 10086;
	printf("a:%d   *p:%d\n",a,*p);
	
	return 0;
}