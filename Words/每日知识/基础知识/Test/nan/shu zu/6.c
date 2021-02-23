//100000!末尾有多少个0
#include <stdio.h>
int main()
{
	int i;
	int x;
	int n;
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
			printf ("x=%d\n",x);
			return 0;
			}