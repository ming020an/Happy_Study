/*
 * @Author: lgw
 * @Date: 2021-02-06 10:37:46
 * @LastEditTime: 2021-02-06 10:42:43
 * @LastEditors: Do not edit
 * @FilePath: \test_0206\test_3.c
 * @Description: 
 */
#include<stdio.h>
int main()
{
    int a = 0;
    int b = 2;
    /*分支结构 if结构*/
    if( a == b)
    {
        printf("a 等于 b\n");
    }
    else
    {
        printf("a 不等于 b\n");

    }

   if( a == b)
    {
        printf("a 等于 b\n");
    }
    else if(a ==0)
    {
        printf("a 等于 0\n");

    }
    else
    {
        printf("a 不等于 b\n");

    }

    
    return 0;
}