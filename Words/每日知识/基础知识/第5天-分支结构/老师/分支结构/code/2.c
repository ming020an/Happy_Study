#include <stdio.h>

int main(void)
{
	int a = 3;
	int b = 4;
	if(a+b>a-b)
		a = 10; //if已经滚蛋了！！！
	b = 15;
	else
		a = a+b;
	printf("%d\n",a);
	
	/*
		2.c: In function ‘main’:
		2.c:10:2: error: ‘else’ without a previous ‘if’
		  else
		  ^
		else没有一个配对的if！！！！
	*/
	
	
	return 0;
}