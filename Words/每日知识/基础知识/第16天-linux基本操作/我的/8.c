//写一个函数实现将任意位数（<=10）数字字符串（0-9）转化为相应
//的数字，如：将  “123”转化成  123。不能使用atoi函数
// int str2num(char *s);lsvi 

#include<stdio.h>
void *str2num(char*s,int a[10]);
int main(void)
{	int j;
	int a[10]={0};
	char s[10]="5316870245";
	str2num(s,a);
	for(j=0;j<10;j++)
	printf("%d",a[j]);
	printf("\n");
}
void *str2num(char*s,int a[10])
{
	int i=0;
	for(i=0;i<11;i++)
	{
	a[i]=(*(s+i)-'0');
	
	}

}
