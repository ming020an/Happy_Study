#include <stdio.h>

int main(void)
{
	int x = 0;
	int i = 0;
	int n = 0;
	for(i=5;i<=100000;i+=5)
	{
		x = i;
		while(x%5 == 0) //if(x%5 == 0) //某个数能被5整除
		{
			n++; //表示因数中5的个数 +1
			x /= 5;
			/*
			if(x%5 == 0)
			{
				n++; //表示因数中5的个数 +1
				x /= 5;
			}
			*/
		}
	}
	
	printf("0的个数是%d\n",n);
	
	return 0;
}