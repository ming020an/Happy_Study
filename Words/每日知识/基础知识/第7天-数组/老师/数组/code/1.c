#include <stdio.h>

int main(void)
{
	int a[10] = {0};
	int i = 0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);  //a[0]
	}
	
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return 0;
}