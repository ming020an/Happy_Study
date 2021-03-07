#include <stdio.h>
/*static修饰的全局变量
	只在当前文件有效
	别的文件是看不到的了!
	
*/
//static int a = 10;
//static int b = 100;
int a = 10;
int b = 100;

/*这两个是声明一下您在外面有人了*/
//extern int a;
//extern int b;

void print(void)
{
	printf("%d %d\n",a,b);
}

void swap(void)
{
	print();
	int t = a;
	a = b;
	b = t;
}