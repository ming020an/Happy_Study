#include<stdio.h>
int main ()
{
	int y = 0;
    for (y=0;y<=2018;y++)
	{
	if(y%4==0&&y%100!=0||y%400==0)
	printf("%d\n",y);
	}
	return 0;
}
