/*
 * @Author: lgw
 * @Date: 2021-01-23 15:24:10
 * @LastEditTime: 2021-01-23 16:16:32
 * @LastEditors: Do not edit
 * @FilePath: \我的\.vscode\lx_type.c
 * @Description: 
 */
#include<stdio.h>
#include"lx_type.h"
int main()
{
    int a;
    int gi_count;
    a = 1111;
    gi_a = 1234;
    printf ("a = %d\n",a);
    printf("main函数 gi_a = %d \n",gi_a);
    
    a = foo(1,2);
    printf ("a----- = %d\n",a);

    return 0;
}

int foo(int a,int b)
{
    gi_a =4321;
    printf("foo 函数中gi_a = %d \n",gi_a);
    return a+b;
}




