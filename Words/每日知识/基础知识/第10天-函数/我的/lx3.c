/*二分法把输入的10个数插入一个有序数组
判断
找出mod，判断插入的数比mod大还是小，

*/
#include<stdio.h>
int main(void)
{
	int i,j,m,b,c,d;
	int high,low,flag;
	int a[20]={1,2,3,4,5,6,7,8,9,10};
		high = 11;
		low = 0;
		int n=11;
	for(i=0;i<10;i++)
	{
		scanf("%d",&b);//输入数字
		//(high-low)!=0
		/*if(b>a[high])
		{
			flag=high+1;
		}
		else if(b<a[low])
		{
			flag=low;
		}
		else
		{*/
			
			//c=high;//因为high值在while中改变，后面移位又要用到，先放入c中
			while(low<=high)
			{ 
				flag=(high+low)/2;
				if(b>a[flag])
				{
					low=flag+1;
					
				}
				else if(b<a[flag])
				{
					high = flag-1;
					
				}
				else
				{
					high=flag;
				
				 break;
				 }
			}
			//high = c;//完成二分找位置操作后把原来值附回来。
			//low = 0;
	    //}
		//移位
		for(;n>flag;n--)
		{
			a[n]=a[n-1];
		}
		//插入
		a[flag+1]=b;
		//high++;
		n=12;
		printf("a[%d]=%d\n",flag,a[flag]);
	}
	
	for(m=0;m<20;m++)
	printf("%3d",a[m]);
	return 0;
}