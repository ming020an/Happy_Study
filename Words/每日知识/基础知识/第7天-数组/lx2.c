/*1.定义一个二维数组,从键盘获取数据,并打印*/
#include<stdio.h>
int main(void)
{
	int a[3][3];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		scanf("%d",&a[i][j]);
		
		}
	
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("%d\t",a[i][j]);
		
		}
	
	}
	return 0;
}