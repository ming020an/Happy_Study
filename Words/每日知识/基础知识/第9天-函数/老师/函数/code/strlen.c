#include <stdio.h>
#include <string.h>
//算法:利用循环一个一个访问数组的元素,如果不是\0我就+1
int my_strlen(char a[])
{
	int i = 0;
	int n = 0;
	//printf("%d\n",sizeof(a));
	//for(i=0;i<0xefffffff;i++)
	while(1)
	{
		if(a[i++] != '\0')
		{
			n++;
		}
		else
		{
			//break;
			return n;
		}
	}
	
	//return n;
}

int main(void)
{
	char b[5] = {'a','b','c','d','e'};
	char a[100] = "hello world"; //hello world\0\0\0\0.....
	int n = my_strlen(a);
	int m = my_strlen(b);
	
	printf("a:%d,b:%d\n",n,m);
	
}