/*输入十个数，从小到大排列*/
// 判断是不是第一数；找插入位置；位置后的数都要移位； 插入；
#include<stdio.h>
int main (void)
{
	int i,flag=0;
	int n,j,c,m;
	int a[10]={0};
	for(i=0;i<10;i++)
	{
	
		scanf("%d",&a[i]);
		if(i==0)//判断是不是第一个
		continue;
		
		c=a[i];
		
		for(n=0;n<i;n++)
		{
			if(a[n]>a[i])
			{
				flag=n;
				break;//当找到就跳出，以免n以后又有满足条件的数，重新刷新flag
			}
			else
				flag=i;	
		}
		if(flag==i)//又是少了一个等号
		{
			continue;
		}
		else
		{
			/*for(j=flag;j<i;j++)
			{
				a[j-1]=a[j];
			}需要仔细弄懂一下移位*/
			for(j=i;j>flag;j--)
			{
				a[j]=a[j-1];
			}
			a[flag]=c;
		}
	
	}
			for(m=0;m<10;m++)
			printf("%d\t",a[m]);
	return 0;
}