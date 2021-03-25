#include <stdio.h>

int main(void)
{
	int a[5]={5,3,9,15,20};
	int i=0;
	int j=0;
	int t=0;
	for(j=0;j<5;j++)
	{
		for(i=0;i<5-j;i++)
		{	
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}