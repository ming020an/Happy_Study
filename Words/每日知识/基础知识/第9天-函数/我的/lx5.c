#include<stdio.h>
int my_fblj(int a)
{
	if(a==1||a==2)
	{
		return 1;
	}
	else
	return my_fblj(a-1)+my_fblj(a-2);
}
int main(void)
{
	int nub;
	nub=my_fblj(10);
	printf("%d\n",nub);
	return 0;

}