/*************************************************************************
  > File Name: 5.c
  > Author: csgec
  > Mail: csgec@163.com 
  > Created Time: Fri 26 Jan 2018 10:54:22 PM PST
 ************************************************************************/

#include<stdio.h>
int main(void)
{
	char a = 'i';
	char *s = "123456789";
	printf("%s\n",s);
	s++; //是向后指向一个地址
	*s++;//取s地址的变量后s向后移动
	*(s+1);//取s后面的那个地址的变量
	printf("------%d------\n",__LINE__);
	//*(s+1) = 'A'; //给s后面地址的变量赋值为'A'
	printf("------%d------\n",__LINE__);
	s = &a; //a是一个char型变量  将s改指向 a的地址
	printf("%s\n",s);
}
