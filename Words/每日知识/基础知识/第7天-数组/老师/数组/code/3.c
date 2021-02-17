#include <stdio.h>

int main(void)
{
	int i = 0;
	int x = 1024;
	int s = 1;
	
	for(i=0;i<65535;i++)
	{
		s = x*s%1000;
	}
	
	printf("%d\n",s);
}