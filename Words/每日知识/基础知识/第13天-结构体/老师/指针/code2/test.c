/*************************************************************************
	> File Name: test.c
	> Author: csgec
	> Mail: csgec@163.com 
	> Created Time: Sun 28 Jan 2018 05:26:14 PM PST
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	int a = 5;
	int *p = &a;
	//int *q = p;
	int *q = &p;
}
