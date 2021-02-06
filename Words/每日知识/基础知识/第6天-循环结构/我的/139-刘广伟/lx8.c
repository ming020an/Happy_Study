/*输入两个数n，a；sn=a+aa+aaa+....n*a */
#include<stdio.h>
int main(void)
{
	int a,n,b,c=1;
	int i,j=0,k;
	int sn=0;
	scanf("%d%d",&a,&n);
	b=a;
	while(a>=1)
	{
		a=a/10;
		j++;
	}
	printf("a是%d位数\n",j);
	for(k=0;k<j;k++)
	{
		c=10*c;
		printf("c=%d\n",c);
	}
	for(i=0;i<=n;i++)
	{
		sn=sn+a;
	//	printf("sn=%d\n",sn);
		a=(a*c)+b;
	//	printf("a=%d\n",a);
		//sn+=c;
		
	}
printf("sn=%d\n",sn);
return 0;
}