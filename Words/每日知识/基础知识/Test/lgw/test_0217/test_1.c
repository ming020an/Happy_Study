/*
 * @Author: lgw
 * @Date: 2021-02-17 14:50:48
 * @LastEditTime: 2021-02-17 16:12:45
 * @LastEditors: Do not edit
 * @FilePath: \test_0217\test_1.c
 * @Description: 
 */
#include <stdio.h>

int main(void)
{
    // int a = 0;
    // scanf("%d",&a);
    // printf("a = %d",a);
    int i = 0;
    int sum[10];
    //int sum[10] = {1,2,3,4,5,6,7,8,9,10};

    for(i = 0;i<10;i++)
    {
        sum[i] = i;
    }
    printf(" sum[%d] = %d\n",7,sum[7]);


    return 0;
}