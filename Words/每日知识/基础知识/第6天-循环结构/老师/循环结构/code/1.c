#include <stdio.h>

int main(void)
{
	int i;
lable:
		i = 0;
		i++;
		printf("%d\n",i);//printf是一个带缓冲区的输出，有三种情况会打印到屏幕上
						// 1、遇到'\n'
						// 2、程序结束，则输出缓冲区中的数据
						// 3、缓冲区满了，也会输出缓冲区的数据
		sleep(1);
		goto lable;
		
	return 0;
}