/*求一千以内完数，除本身以外因数之和=本身*/
#include<stdio.h>
int main(void)
{
	int a;
	int sum;
	int i;
	for(a=1;a<1000;a++)
	{
		sum = 0;
		for(i=1;i<a;i++)
		{
			if(a%i==0)
			{
				sum+=i;
			}	
		}
		if(sum==a)
			printf("%d\n",sum);
	}
	return 0;
}