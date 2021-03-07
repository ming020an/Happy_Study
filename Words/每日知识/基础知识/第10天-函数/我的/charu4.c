#include<stdio.h>
int main()
{
	int a[15]={56,6,4,2,1,7,32,8,2,1,7,1,39,5};
	int i,j,k,b,c=0,n=0;
	
	for(i=0;i<15;i++)
	{	
		
		c=a[i];
		//n=i;
		for(j=0;j<i;j++)
		{	
			if(a[j]>a[i])    //n为要插入的位置
				{
				n=j;
				break;
				}
			else
				n=i;
		}
		if(n==i)
		{
			continue;
		}
		else
		{
			for(j=i;j>n;j--)
			{
				a[j]=a[j-1];
			}
			a[n]=c;	
		}
	}
	
	for(i=0;i<15;i++)
		printf("%3d",a[i]);
	printf("\n");
	
}