#include <stdio.h>

int main(void)
{
	int a = 3;
	int b = 4;
	/*a++；
	编译器报错如下：
	1.c: In function ‘main’://1.c文件在函数main
	1.c:7:2: error: stray ‘\357’ in program
	1.c文件第7行第二个字符：出错：翻译不过来
	  a++；
	*/
	a++;
	b--;
	(a+b)++;
	/*
	1.c: In function ‘main’:
	1.c:16:7: error: lvalue required as increment operand
	  (a+b)++;
	*/
}