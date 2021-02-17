#include<stdio.h>
int main(void)
{
			int a[10] = {0};
			int n = 0; //计算,数组元素个数
			int x;
			int i , j;
			int i_max;
		for(n=0;n<10;n++)
		{
			scanf("%d",&x);
			/*输入的是第一个元素吗?*/
			if(n == 0) //数组中没有元素
			{
				a[0] = x;
			}
			//如果已经有元素了,那么找第一个比x大的数
			for(i=0;i<n;i++)
			{
				if(a[i]>x)
				{
					i_max = i; // 记录找到的插入位置
					break;
				}
			
			//找 位置  移位 插入 输出
			/*找到要插入的位置了!!!!*/
				if(i == n)//一直没找到比输入的数要大的数
				{
					a[n] = x;
					n++;
				}
				else
				{
					/*+
						a[n] = a[n-1];
						a[n-1] = a[n-1 -1];
						...
						a[i_max+1] = a[i_max];
					*/
					for(i=n;i>i_max;i--)
					{
						a[i] = a[i-1];
					}
					a[i_max] = x;
					n++;
				}
			}
		}
		for(i=0;i<10;i++)
			printf("%d\n",a[i]);
	return 0;
}