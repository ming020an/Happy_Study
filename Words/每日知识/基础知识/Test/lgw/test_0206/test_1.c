/*
 * @Author: lgw
 * @Date: 2021-02-06 10:06:42
 * @LastEditTime: 2021-02-07 14:45:26
 * @LastEditors: Do not edit
 * @FilePath: \test_0206\test_1.c
 * @Description: 
 */
#include <stdio.h>
int main()
{
    int a;
    int b;

    // for(a = 0; a<10 ;++a)
    // {
        // printf("a = %d\n",a++++);
    // }

   for(b = 0; b<10 ;b+2)
    {
        printf("pre b = %d\n",b);
        // ++a;
        
        // printf("last a = %d\n",a);
    }
     return 0;   
}