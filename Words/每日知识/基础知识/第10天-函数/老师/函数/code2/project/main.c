#include<stdio.h>

/*外部声明,声明一下在其他文件中定义了一个函数*/
extern int add(int ,int);

int main(void)
{
	printf("%d\n",add(3,4));
}