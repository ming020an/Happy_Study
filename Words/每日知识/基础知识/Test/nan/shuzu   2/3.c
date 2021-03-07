#include <stdio.h>
int main()
{
    int sum = 1;
	int i;
    int y;
    int x=1024;
	for (i = 0; i < y; i++) 
    {
		sum = sum*x%1000;   //计算一个数次方后的后三位
	}
    printf ("sum=%d\n",sum)
	return sum;
}