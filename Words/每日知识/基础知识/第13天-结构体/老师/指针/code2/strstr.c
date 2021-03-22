/*************************************************************************
	> File Name: strstr.c
	> Author: csgec
	> Mail: csgec@163.com 
	> Created Time: Sat 27 Jan 2018 12:47:43 AM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	char *p = strstr("ouyanghualiang","yan");
	if(p == NULL)
	{
		printf("huangying you du\n");
	}
	else
		printf("%s\n",p);
}
