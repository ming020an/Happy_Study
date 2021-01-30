#include <stdio.h>

int main(void)
{
	int t;
	unsigned char a,b,c,d;
	printf("please input\n");
	scanf("%x",&t);//从键盘上以十六进制的形式，
					//获取一个数，存放到t的地址中
	a = t/(256*256*256);
	b = (t/(256*256))%256;
	c = (t/256)%256;
	d = t%256;
	printf("%x %x %x %x\n",a,b,c,d);//将有符号短型 赋值给 长型
	
	return 0;
}