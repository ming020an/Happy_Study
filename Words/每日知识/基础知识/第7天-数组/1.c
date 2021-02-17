#include<stdio.h>
int main(void)
{
	float s;
	int k,n=5;
	s=1.0;
	for(k=1;k<=n;k++)
	s=s+1.0/(k*(k+1));
	printf("%f\n",s);
	return 0;
}