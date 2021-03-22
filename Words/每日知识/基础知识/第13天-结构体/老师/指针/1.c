#include <stdio.h>

void print(int *p,int *e)
{
	while(e>=p)
	{
		printf("%d ",*e--);
	}
	printf("\n");
}

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9};
	//print(a,9);
	print(&a[0],&a[8]);
}