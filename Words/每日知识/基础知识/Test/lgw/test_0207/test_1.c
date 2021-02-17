/*
 * @Author: lgw
 * @Date: 2021-02-07 15:48:17
 * @LastEditTime: 2021-02-17 16:22:27
 * @LastEditors: Do not edit
 * @FilePath: \test_0207\test_1.c
 * @Description: 
 */
#include <stdio.h>
int main()
{
    int a = 0;
flag:
    a++;
    if(a<10)
    {
        printf("------a=%d\n",a);
        goto flag;
    }
    	printf("a=%d\n",a);

    
    return 0;
}