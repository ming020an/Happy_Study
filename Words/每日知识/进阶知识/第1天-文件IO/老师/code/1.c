#include <stdio.h>



int main()
{
	//step1:打开文件
	FILE *fp = fopen("2.txt","r");
	if(fp == NULL)
	{
		perror("open error");
		return -1;
	}
	printf("open right\n");
	//step2：文件操作
	
	//step3:文件关闭
	
	fclose(fp);
}
