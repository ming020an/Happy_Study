/*
 * @Author: lgw
 * @Date: 2021-03-01 21:03:32
 * @LastEditTime: 2021-03-01 21:41:02
 * @LastEditors: Do not edit
 * @FilePath: \shu zu\8.c
 * @Description: 
 */
#include <stdio.h>
void main()
{
    int i;
    long f = 24;
    int c = 0;
    for(i=5; i<=100; i++)
    {
        f *= i;
        if(f%10==0)
        {
            f /= 10;
            c++;
        }
        else
        {
            f = f % 10;
        }
    }
    while(f%10 == 0)
    {
        f = f / 10;
        c++;
    }
    printf("末尾0的总数量：%d", c);
}