/*
 * @Author: lgw
 * @Date: 2021-02-17 16:26:36
 * @LastEditTime: 2021-02-17 16:34:44
 * @LastEditors: Do not edit
 * @FilePath: \test_0217\test_3.c
 * @Description: 二维数组
 */
#include <stdio.h>
int main(void)
{
    int sum[10][3]={1,2,3,
                    11,22,33,
                    111,222,333};

    printf("sum[%d][%d]=%d",0,5,sum[2][0]);


    return 0;
}