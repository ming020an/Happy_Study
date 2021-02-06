#include<stdio.h>
int main(void)
{
	int i=0;
	int sum=0;
	flag:
		i++;
		sum+= i ;
		if(i<100)
		{
			goto flag;
		}
		printf("%d\n",sum);
		return 0;
}