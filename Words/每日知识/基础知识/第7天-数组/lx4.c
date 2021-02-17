/*求山顶的个数
				"山顶":  上下左右它最高,就是山顶
					  ?:
					上   (i-1)?i-1
					下   i+1
					左   j-i
					右   j+1 */
#include<stdio.h>
int main(void)
{
	int s=0,i,j;
	int a[4][4]={
				1,3,5,7,
				9,6,5,4,
				8,1,5,6,
				2,5,2,5};
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{	
				if(i==0)
				{
					if(j==0)
					{
				if(a[i][j]>a[i][j+1]&&a[i][j]>a[i+1][j])
				{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
				}
					}
				else if(j==3)
					{
					if(a[i][j]>a[i][j-1]&&a[i][j]>a[i+1][j])
					{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
					}
					}
				else
					{
					if(a[i][j]>a[i][j+1]&&
					a[i][j]>a[i][j-1]&&
					a[i][j]>a[i+1][j])
					{
						printf("a[i][j]=%d\n",a[i][j]);
						s++;
					}
					}
					
				}
			else if(i==3)
				{
					if(j==0)
					{
				if(a[i][j]>a[i][j+1]&&a[i][j]>a[i-1][j])
				{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
				}
					}
				else if(j==3)
					{
					if(a[i][j]>a[i][j-1]&&a[i][j]>a[i-1][j])
					{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
					}
					}
				else
					{
					if(
					a[i][j]>a[i][j-1]&&
					a[i][j]>a[i][j+1]&&
					a[i][j]>a[i-1][j])
				{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
				}
					}
				
				}
			else
				{
				if(j==0)
					{
				if(a[i][j]>a[i][j+1]&&a[i][j]>a[i-1][j])
				{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
				}
					}
				else if(j==3)
					{
					if(a[i][j]>a[i][j-1]&&a[i][j]>a[i-1][j])
					{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
					}
					}
				else
					{
					if(
					a[i][j]>a[i][j-1]&&
					a[i][j]>a[i][j+1]&&
					a[i][j]>a[i-1][j])
				{
					printf("a[i][j]=%d\n",a[i][j]);
					s++;
				}
					}
				}
			}
		}
		printf("%d\n",s);
	return 0;
}