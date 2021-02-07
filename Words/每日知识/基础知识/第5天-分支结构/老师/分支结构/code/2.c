/*
 * @Author: lgw
 * @Date: 2021-02-06 09:46:35
 * @LastEditTime: 2021-02-07 15:41:49
 * @LastEditors: Do not edit
 * @FilePath: \test_0206e:\U盘备份\Mygit\git\Happy_Study\Words\每日知识\基础知识\第5天-分支结构\老师\分支结构\code\2.c
 * @Description: 
 */
#include <stdio.h>

int main(void)
{
	int a = 3;
	int b = 4;
	if(a+b>a-b)
	{
		a = 10; //if已经滚蛋了！！！
		b = 15;
	}
	else
	{
		a = a+b;
	}
		
	printf("%d\n",a);
	
	/*
		2.c: In function ‘main’:
		2.c:10:2: error: ‘else’ without a previous ‘if’
		  else
		  ^
		else没有一个配对的if！！！！
	*/
	
	
	return 0;
}