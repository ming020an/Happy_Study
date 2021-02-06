/*
 * @Author: lgw
 * @Date: 2021-02-06 10:43:41
 * @LastEditTime: 2021-02-06 10:53:36
 * @LastEditors: Do not edit
 * @FilePath: \test_0206\test_4.c
 * @Description: 
 */

#include<stdio.h>
int main()
{
    int a = 2;
    char b ;
    b = 'b';
    switch (b)
    {
    case 'a':
            printf("字符 a\n");
        break;
    case 'b':
            printf("字符 b %c\n",b); 
        break;  
    default:
        break;
    }
    // switch (a)
    // {
    //     case 0:
    //         printf("a 等于 0\n");
    //         break;
    //     case 1:
    //         printf("a 等于 1\n");
    //         break;
    //     case 2:
    //         printf("a 等于 2\n");
    //     case 3:
    //         printf("a 等于 3\n");
    //         break;    
    //     default:

    //         break;
    // }


    return 0;
}