#include <stdio.h>

int  main(void)
{
	int a,b,c,d,m = 10086,n = 13800;
	a = 1;b = 2; c = 3;d = 4;
	(m = a>b) && (n = c > d);
	/*
		上述语句的执行过程：
		a>b？将结果赋值给 m
		m && 此时发现 m == 0的，因此 n = c>b 表达式不会执行
	*/
	printf("a=%d b=%d c=%d d=%d m=%d n=%d\n",a,b,c,d,m,n);
	
	return 0;
}