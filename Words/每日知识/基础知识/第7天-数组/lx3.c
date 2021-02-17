/*矩阵变换:	(行列注意了啊啊啊啊啊啊!!!!!)
				比如: int a[2][3]  ====>  b[3][2]
				
					1 2 3                  1 4
					4 5 6                  2 5
					                       3 6 */
#include<stdio.h>
int main(void)
{
	int a[2][3]={1,2,3,4,5,6};
	int b[3][2];
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
		b[j][i]=a[i][j];
		}
	}
	printf("数列A:");
	for(j=0;j<2;j++)
	{
		printf("\n");
		for(i=0;i<3;i++)
		{
		printf("%d",a[j][i]);
		}
	}
	printf("数列B:");
	for(j=0;j<3;j++)
	{
		printf("\n");
		for(i=0;i<2;i++)
		{
		printf("%d",b[j][i]);
		}
	}
		printf("\n");
	return 0;
}