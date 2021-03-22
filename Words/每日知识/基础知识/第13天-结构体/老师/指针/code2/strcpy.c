/*************************************************************************
	> File Name: strcpy.c
	> Author: csgec
	> Mail: csgec@163.com 
	> Created Time: Sat 27 Jan 2018 12:41:34 AM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void)
{
	char p[1000] = "abcdefg";
	char *q = "12345";

	strncpy(p,q,2);

	printf("%s\n",p);
}
