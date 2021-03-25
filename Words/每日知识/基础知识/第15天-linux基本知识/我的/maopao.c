/*冒泡排序，从小到大**/
#include<stdio.h>
#define N 10
int main()
{
	int i,j,t;
	int a[N]={0};
	//int b[N]={0};
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		printf("a[%d]=%d\n",i,a[i]);
	}
	for(i=1;i<11;i++)
	{
		for(j=0;j<10-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<N;i++)
	printf("%d\t",a[i]);
}