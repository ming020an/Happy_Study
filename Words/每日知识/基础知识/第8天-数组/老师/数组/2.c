#include <stdio.h>

int main(void)
{
	int a[10] = {0};
	int i = 0;
	int a_max; //a_max最先保存数组的第一个元素
	int i_max = 0;
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	a_max = a[0]; //a_max最先保存数组的第一个元素
	i=0;
	while(i<10)
	{
		if(a_max < a[i])
		{
			a_max = a[i];
			i_max = i;
		}
		
		i++;
	}
	
	printf("max is a[%d]:%d\n",i_max,a_max);
	
	return 0;
}