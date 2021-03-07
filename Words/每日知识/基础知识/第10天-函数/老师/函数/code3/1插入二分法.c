#include <stdio.h>
#define N 100

/*声明一个定义在外部的打印数组函数*/
extern void print(int a[],int n);

int main(void)
{
	int a[N] = {1,15,100,110,150,220,400,420,421,483};
	int n = 10;  // 1
	int low = 0;
	int mod;
	int hight = n - 1;
	int x;
	int i = 0;
	int j = 0;
	
	while(n<100)
	{
		scanf("%d",&x); //x = a[n];
		if(x == 0)
		{
			break;
		}
		low = 0;
		hight = n - 1;
		while(1)
		{
			mod = (low + hight)/2;
			if(x > a[mod])
			{
				low = mod + 1;
			}
			else if(x < a[mod])
			{
				hight = mod - 1; 
			}
			else 
			{
				break;
			}
			
			if(hight<low)
			{
				break;
			}
		}
		
		/*
			有两种可能 程序会执行到这个位置
			x == a[mod]
			hight - low <= 1
		*/
		if(x == a[mod])
		{
			i = mod;
		}
		if(hight < low)
		{
			i = hight+1;
		}
		
		/*后移步骤*/
		for(j=n;j>i;j--)
		{
			a[j] = a[j-1];
		}
		
		/*插入*/
		a[i] = x;
		n++;
		print(a,n);
	}
	
}