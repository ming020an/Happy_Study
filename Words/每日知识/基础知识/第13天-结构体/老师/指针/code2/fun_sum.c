/*************************************************************************
	> File Name: fun_sum.c
	> Author: csgec
	> Mail: csgec@163.com 
	> Created Time: Sun 28 Jan 2018 05:21:09 PM PST
 ************************************************************************/

#include<stdio.h>

int sum(int a,int b)
{
	return a+b;
}

int main(void)
{
	//int(int,int) (*fun_sum)
	int (*fun_sum)(int,int);
	//fun_sum = sum;
	fun_sum = &sum;
	int ret = (*fun_sum)(3,4);

	printf("%d\n",ret);

	return 0;
}
