/**汉诺塔排法
分三步走：1、n-1a移到b；2、n a移到c；3、n-1 b移到c;
函数括号里的 前面是源，中间为借助物，最后为目标；

分两个盘看，一个是n，一个是n-1，n到c只要一步；n-1到c要两步；
**/

#include<stdio.h>
int my_hanot(int n,char a,char b,char c)
{
	if(n==1)
	{
		printf("%c--->%c\n",a,c);
		return 0;
	}
	else 
	{
		my_hanot(n-1,a,c, b);//n-1个盘第一步，从a--b
		printf("%c--->%c\n",a,c);//打印要按上面位置写
		my_hanot(n-1,b,a, c);//n-1 第二步 ，从b--c；
		
	}
	
}
int main(void)
{	
	my_hanot(3,'A','B','C');
	return 0;
}