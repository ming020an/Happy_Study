/*
 * @Author: lgw
 * @Date: 2021-02-17 14:37:10
 * @LastEditTime: 2021-02-17 15:26:41
 * @LastEditors: Do not edit
 * @FilePath: \循环结构\1.c
 * @Description: 
 */
#include <stdio.h>
int main (void)
{
    int a =3;
    int sum = 0;
    for (a=3;a<=100;a++)
    {
        sum = sum  + a;
        if (a==98)
        {
            break;
        }
    } 

    
    printf("a = %d ,sum =%d",a,sum);



    return 0;
}