#include <stdio.h>

int main(void)
{
	while(1)
	{
		static int a = 5;
		printf("%d\n",a++);
		sleep(1);
	}
}