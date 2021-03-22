/*************************************************************************
  > File Name: malloc.c
  > Author: csgec
  > Mail: csgec@163.com 
  > Created Time: Sun 28 Jan 2018 07:26:36 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char *p = malloc(sizeof(p)*4); //p指针分配了一块有 4*4=16 个字节的空间
	*p = 'n';
	*(p+1) = 'i';
	*(p+2) = 'd';
	*(p+3) = 'o';
	*(p+4) = 'n';
	*(p+5) = 'g';
	//....
	*(p+15) = '!';
	printf("%s\n",p);

	printf("sizeof(p):%d,sizeof(*p):%d\n",sizeof(p),sizeof(*p));
	free(p);
	return 0;
}
