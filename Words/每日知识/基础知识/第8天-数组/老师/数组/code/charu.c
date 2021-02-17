/*
	插入排序:一个已经 有序 的数组
	(1) 找到要插入的位置
		插入到最后面:一直没有找到比输入的数要大的数 (升序)
		插入到中间位置:将该位置开始 到最后一个元素 全部后移一位 (空出找到的位置)
		
	(2) 插入:将输入的数据插入到找到的位置
*/

#include <stdio.h>

int main(void)
{
	int a[10] = {0};
	int n = 0; //计算,数组元素个数
	int x;
	int i , j;
	int i_max = 0;
	
	//for(j=0;j<10;j++)
	while(1)
	{
		scanf("%d",&x); //如果输入0,表示输入结束
		if(x == 0)
		{
			break;
		}
		// 1 
		for(i=0;i<n;i++)
		{
			if(a[i]>x) //找到第一个比x要大的数
			{
				i_max = i; // 记录找到的插入位置
				break;
			}
		}
		
		if(i == n)//插入的数(x)是数组中最大的
		{
			a[n] = x;
			n++;
			continue;
		}
		
		for(i=n;i>i_max;i--) //后移
		{
			a[i] = a[i-1];
		}
		a[i_max] = x; //插入
		n++;
		
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return 0;
}