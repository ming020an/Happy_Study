/*九九乘法表*/
#include<stdio.h>
int main(void)
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
		printf("%d*%d = %d ",j,i,j*i);
		}
		printf("\n");
		//printf("%d*%d=%d\v",i,j,i*j);
	printf("\v");
	}
	
	return 0;
}