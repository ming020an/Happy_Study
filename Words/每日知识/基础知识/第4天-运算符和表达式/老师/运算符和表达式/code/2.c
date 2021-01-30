#include <stdio.h>

int main(void)
{
	int a = 5;
	int b = 1;
	//int c = a+++b;//--->a++ + b; 先a + b;再 a=a+1;
	int c = a + ++b;// 先++b ---> b = b+1;然后 a + b;
	printf("a=%d b=%d c=%d\n",a,b,c);
	//printf("a++表达式的值:%d\n",a++);
	//printf("a++运算后的值：%d\n",a);
	printf("++a表达式的值:%d\n",++a);
	printf("++a运算后的值：%d\n",a);
}