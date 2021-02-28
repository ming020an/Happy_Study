//100000!末尾有多少个0
#include <stdio.h>
int main()
{
	int i;
	//int x;
	int n;
for(i=0;i<=100000;i++)
			{
				while(i%10 == 0) //if(x%5 == 0) //某个数能被5整除
				{
					n++; //表示因数中5的个数 +1
					//x /= 5;
					/*
					if(x%5 == 0)
					{
						n++; //表示因数中5的个数 +1
						x /= 5;
					}
					*/
				}
			}
			printf ("n=%d\n",n);
			return 0;
			}