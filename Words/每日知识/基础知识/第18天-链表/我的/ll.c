/*************************************************************************
	> File Name: ll.c
	> Author: 刘广伟
	> Mail: gwacoe@163.com 
	> Created Time: Tue 06 Feb 2018 04:04:31 PM CST
 ************************************************************************/

#include<stdio.h>
int main (viod)
{
	int x,y,flag;
	int ji_sum,tu_sum;
	printf("请输入数量 和 腿数\n");
	scanf("%d %d",&x,&y);
	tu_sum=y-2*x;
	ji_sum=x-tu_sum;
	flag=tu_sum*4+ji_sum*2;
	if(flag!=y)
	{
	printf("no answer\n");
	return 0;
	}
	printf("tu_sum=%d  ji_sum=%d",tu_sum,ji_sum);
	return 0;
}
