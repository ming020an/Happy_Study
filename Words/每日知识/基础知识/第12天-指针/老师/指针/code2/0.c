/*************************************************************************
	> File Name: 0.c
	> Author: csgec
	> Mail: csgec@163.com 
	> Created Time: Fri 26 Jan 2018 06:56:27 PM PST
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	int a[10] = {0,1,2};
	int *p = a;
	printf("%d\n",*p++);
}
