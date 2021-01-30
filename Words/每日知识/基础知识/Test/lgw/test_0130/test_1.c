/*
 * @Author: lgw
 * @Date: 2021-01-30 15:29:38
 * @LastEditTime: 2021-01-30 15:46:19
 * @LastEditors: Do not edit
 * @FilePath: \test_0130\test_1.c
 * @Description: 
 */
#include<stdio.h>

/* 九九乘法口诀 */
int main(void)
{
    int i, j;
    for(i = 1;i <10; i++)
    {
        for(j =i;j>0;j-- )
        {
            printf(" %d*%d = %d \t",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}