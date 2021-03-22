#include <stdio.h>

int main(void)
{
	int a[3][4] = {0};
	//a[2][2] = 1024;  //直接赋值
	// int *q = &a[2][2]; //int *q;q = &a[2][2];
	// *q = 1024; //通过变量地址间接赋值
	// *(a[2]+2) = 1024;//a[2]表示的是二维数组的第三个(行下标为2)一维数组
	
	int (*w)[3][4] = &a; //指针w指向整个数组a
	// w == &a; 
	// *w == *(&a);
	// *w == a;
	// a[0] == &a[0][0];
	// a == &a[0]; //a是数组名,是常量指针,指向数组的第一个元素
			//对于二维数组来说,第一个元素就是第一个一维数组
	// *w == &a[0]
	// *w+2 == &a[2]
	// *(*(*w+2)+2) == *(&a[2] + 2)== a[2][2]
	*(*(*w+2)+2) = 1024;
	printf("%d\n",a[2][2]);
}