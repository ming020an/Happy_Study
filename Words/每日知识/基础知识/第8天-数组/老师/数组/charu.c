#include <stdio.h>

int main(void)
{
	int i,j;
	int a[100] = {1,5,4,2,1,7,32,8,2,1,7,1,39,5};
	int i_max = 0;
	int a_num = 0;
	for(i=1;i<14;i++)
	{
		//a[i] ----> 要插入的数据  4
		a_num = a[i]; //4  2 1 7
		i_max = i;// 2     3 4 5
		for(j=0;j<i;j++)
		{
			if(a[j]>a[i])
			{
				//j就是要插入的位置
				i_max = j;//记录要插入的位置 1 1 1
				break;
			}
		}
		// j有两种情况: 第一种是 j = i_max;
				//		第二种是 j = i;
		/*就是要插入的位置了,明不明白!*/
		//{1,1,2,4,5,7,32,8,2,1,7,1,39,5};
		//插入:后移空出插入的位置,在插入
		for(j=i;j>i_max;j--) // 4 1 
		{
			a[j] = a[j-1];
		}
		
		/*j位置是一个已经准备好了能让您插入了!!*/
		a[j] = a_num;		
	}
	
	for(i=0;i<14;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");		
}