/*输入一个数组和一个数，判断数组里面元素和组合，有没有和数相等的*/
#include<stdio.h>
int my_sz(int a,int b[])
{
	int i,j;
	for(i=0;i<0xffff;i++)
	{
		int c=1;
		int sum=0;
		for(j=0;j<16;j++)
		{
			if(i&c)
			{
			sum+=b[j];
			//printf("b[i]=%d\t",b[i]);
			}
			c=c<<1;
		}
		if(a==sum)
		{
		printf("yes!\n");
		break;
		}

	}
	
}
int main(void)
{	
	int b[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	my_sz(200,b);
	return 0;
}