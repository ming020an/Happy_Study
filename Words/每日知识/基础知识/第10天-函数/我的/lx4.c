/**二分法插入一个有序的数列
**/

#include<stdio.h>
void my_charu(int b,int a[]);
int main(void)
{	
	int a[100]={15,20,25,36,45,57,68,79,88,94};
	int b,i;
	//for(i=0;i<10;i++)
	//{
	//	int j=i;
	printf("输入一个你想插入的数\n");
	scanf("%d",&b);
	my_charu(b,a);
	//}
	return 0;
}
void my_charu(int b,int a[])
{
	int m,n;
    int high=11;
	int low=0;
	int flag=0;
	int mid;
	while(low<high)
	{
		mid=(high+low)/2;
		if(b<a[mid])
		{
			high=mid-1;
			printf("a[%d]=%d\n",mid,a[mid]);
		}
		else if(b>a[mid])
		{
			low=mid+1;
			printf("a[%d]=%d\n",mid,a[mid]);
		}
		else
		{
			flag=high;
			break;
		}
	}
	for(n=100;flag<n;n--)
		a[n]=a[n-1];
		a[flag]=b;
	for(m=0;m<20;m++)
		printf("%3d",a[m]);
		printf("\n");
	
}