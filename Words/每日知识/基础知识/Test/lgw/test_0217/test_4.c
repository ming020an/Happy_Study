/*
 * @Author: lgw
 * @Date: 2021-02-17 16:35:47
 * @LastEditTime: 2021-02-17 16:39:37
 * @LastEditors: Do not edit
 * @FilePath: \test_0217\test_4.c
 * @Description: 字符数组
 */
#include <stdio.h>

int main(void)
{
    char string[10]={'a','b','c'};
    
    printf(" string = %c\n",string[0]);
    printf(" 串string = %s\n",string);// 相当于 名字为string 指针

    return 0;
}