#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *max_data(char *a,char *b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);
	unsigned short *p = (short *)malloc(sizeof(short)*(len_a+len_b));
	unsigned char *t = (char *)malloc(sizeof(char)*(len_a+len_b));
	memset(p,0,(len_a+len_b)*sizeof(short));//将p的地址空间全部清0
	memset(t,0,len_a+len_b);
	int i,j;
	/*求各个字节的乘积*/
	for(i=len_a-1;i>=0;i--)
	{
		for(j=len_b-1;j>=0;j--)
		{
			*(p+i+j+1) += (*(a+i)-'0')*(*(b+j)-'0');
			//printf("%d*%d=%d\n",(*(a+i)-'0'),(*(b+j)-'0'),*(p+i+j+1));
		}
	}
	
	/*处理进位问题*/
	for(i=len_a+len_b-1;i>0;i--)
	{
		*(p+i-1) += *(p+i)/10;
		*(t+i) = (char)(*(p+i)%10) + '0';	
		//printf("%c ",*(t+i));
	}
	*t = *p+'0';
	
	
	while(*t == 0 || *t == '0')
	{
		t++;
	}
	
	return t;
	
}

int main(void)
{
	char a[1000] = {0};
	char b[1000] = {0};
	scanf("%s %s",a,b);
	char *p = max_data(a,b);
	printf("%s\n",p);
}