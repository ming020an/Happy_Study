//有一个数，范围0-10000，加100得的数是完全平方数，再加168还是完全平方数；

#include<stdio.h>
#include"math.h"
int main (void)
{
	int i=0;
	int j,k;

	for(i=0;i<1000;i++)
	{
		j=sqrt(i+100);
		k=sqrt(i+268);
		if(j*j==i+100&&k*k==i+268)
	printf("%d\n",i);
	
	}
	return 0;

}