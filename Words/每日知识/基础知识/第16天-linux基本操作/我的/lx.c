/*************************************************************************
	> File Name: lx.c
	> Author: 刘广伟
	> Mail: gwacon@163.com 
	> Created Time: Thu 01 Feb 2018 02:10:12 PM CST
 ************************************************************************/

#include<stdio.h>
int main (void)
{
	int i;
	int sum=0;
	for(i=0;i<=100;i=i+2)
	{
		sum+=i;
	}
printf("%d\n",sum);
}
