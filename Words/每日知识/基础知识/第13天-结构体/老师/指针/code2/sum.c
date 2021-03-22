/*************************************************************************
	> File Name: sum.c
	> Author: csgec
	> Mail: csgec@163.com 
	> Created Time: Sun 28 Jan 2018 06:10:30 PM PST
 ************************************************************************/

#include<stdio.h>

int sum(int a[][4],int n,int m)
{
	int i,j;
	int s = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			s+=a[i][j]; 
		}
	}
	return s;
}


int sum1(int *a,int n)
{
	int i;
	int s = 0;
	for(i=0;i<n;i++)
	{
		s += *(a+i);
	}
	return s;
}

int sum2(int (*a)[4],int n)
{
	int i,j;
	int s = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			s += (*(a+i))[j];//=====>a[i][j]
		}
	}

	return s;
}

int main(void)
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//int s = sum(a,3,4);
	//int s = sum1(&a[0][0],12);
	//int s = sum2(a,3);
	int s;

	int (*p)(int (*)[4],int); //define p;
	p = sum2;
	s = p(a,3);
	printf("sum=%d\n",s);
	
	int (*q)(int[][4],int ,int);
	q = sum;
	s = q(a,3,4);
	printf("sum=%d\n",s);

	int (*t)(int*,int );
	t = sum1;
	s = t(*a,12); //s = t(&a[0][0],12);
	printf("sum=%d\n",s);
	return 0;
}
