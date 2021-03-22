
#include<stdio.h>
#define N 10

int sum(char *b[])
{
	int a=0;
	while(*b!=0)
	{
		a+=*(b);
		b++;
		printf("%d\n",b);	
	}
	return a;
}
int main (void)
{
	int b[2][5]={1,2,3,4,5,6,7,8,9,10};
	//sum(b);
	//int *my_sum();
	//my_sum=&sum(b);
	printf("%d\n",sum(b));
return 0;
}