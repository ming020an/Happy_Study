//输出第一二大的数。
#include<stdio.h>
int main(void)
{
	int a[10];
	int i;
	int max1=0,max2=0;
	int a_max1=0,a_max2=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	i=0;//必须初始变量值
	while(i<10)
	{
		
		if(max2<a[i])
		{
			max2=a[i];
			a_max2=i;
			if(max1<max2)
			{
				max1=max1^max2;
				max2=max1^max2;
				max1=max1^max2;
				a_max1=a_max1^a_max2;
				a_max2=a_max1^a_max2;
				a_max1=a_max1^a_max2;
			}
		}
		i++;
	}
		printf("max1=a[%d]:%d\n",a_max1,max1);
		printf("max2=a[%d]:%d\n",a_max2,max2);
	return 0;
}