
/*
 * @Author: lgw
 * @Date: 2021-03-01 21:46:28
 * @LastEditTime: 2021-03-01 21:50:11
 * @LastEditors: Do not edit
 * @FilePath: \shu zu\lx_9.c
 * @Description: 
 */
#include <stdio.h>
int main ()
{
    int a =10000;
    int i = 0;
    
    for( ; ;)
    {
        if(a >1 && (a%10==0))
        {
            printf(" --i = %d\n",i);
            a = a/10;
            i++;
        }
        else
        {
            break;
        }
    }
    printf(" i = %d",i);


    return 0;
}