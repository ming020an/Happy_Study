/*************************************************************************
  > File Name: 2.c
  > Author: 刘广伟
  > Mail: gwacoe@163.com 
  > Created Time: Thu 01 Feb 2018 07:02:24 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
 char *jiaoji(char*s,char*s1,char*s2);
int main (void)
{
	char* a1="abcdefgh";
	char* a2="cbdefg";
	char  s[10]={0};
	char *q=jiaoji(s,a1,a2);
	printf("%s\n",q);
}

char* jiaoji(char*s,char*s1,char*s2)
{
	int j,n=0,i=0;
	char a=strlen(s1);
	char b=strlen(s2);
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(*s1==*(s2+j))
			{
				s[n]=*(s2+j);
				n++;
			}
			else
				continue;
		}
		s1++;//
	}

	return s;
}
