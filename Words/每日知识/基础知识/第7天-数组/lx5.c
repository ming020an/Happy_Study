/*4."鞍点": 行最大&&列最小 
					可能没有
				x_max  ==   y_min  == 本身  ----->鞍点
				a[1][2]    a[0][2]  a[2][2]    a[3][2] ...*/
#include<stdio.h>
int main(void)
{
	int s=0,i,j,n=0,x_max=0;
	int index,k;
	int andian=0,flag=1;
	int b[4]={0};
	int a[4][4]={
				1,8,5,6,
				9,7,5,7,
				4,6,5,5,
				2,9,2,8};
	for(i=0;i<4;i++)
	{
		x_max = a[i][0];
		index = 0;
		for(j=0;j<4;j++)
		{
			
			if(x_max<a[i][j])
			{
				x_max = a[i][j];
				index = j;//只需记录下标，然后把最大值赋值给另一个数组。
			}
			
		}
		b[n]=a[i][index];
			n++;
		for(k=0;k<4;k++)
		{
			if(b[i]>a[k][index])
			flag=0;
		}
		if(flag==1)
		andian++;
	}
	for(n=0;n<4;n++)
		printf("%d\n",b[n]);
		
	
	printf("andian=%d\n",andian);
	return 0;
}