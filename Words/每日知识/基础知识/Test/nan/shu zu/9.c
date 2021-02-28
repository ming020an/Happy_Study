#include <stdio.h>
int main ()
{
    int i = 0;
		int sum = 0;
		while(i<100)
		{
			i++;
			if(i%2 == 0)
			{
				sum += i;
			}
		}
        printf ("sum=%d\n",sum);
        return 0;
}