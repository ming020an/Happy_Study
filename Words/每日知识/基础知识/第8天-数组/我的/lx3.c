/*杨辉三角*/
#include<stdio.h>
int main(void)
{	
	int i,j;
	int a[10][10]={0};
	for(i=0;i<10;i++)
	{
		a[0][0]=1;
		for(j=0;j<=i;j++)
		{
			if(i==0)
			a[i][j]=1;
			else if(i==j)
			a[i][j]=1;
			else
		a[i][j] = a[i-1][j-1] + a[i-1][j];
		printf("%3d",a[i][j]);
		}
		printf("\n");//控制行数跨行
	}
	return 0;
}