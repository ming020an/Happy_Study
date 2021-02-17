/*
 * @Author: lgw
 * @Date: 2021-02-17 16:13:05
 * @LastEditTime: 2021-02-17 16:19:17
 * @LastEditors: Do not edit
 * @FilePath: \test_0217\test_2.c
 * @Description: // 场景 1 统计十个人的语文成绩 并计算出平均值
 *  11 22 33 44 55 66 77 88 99 100
 */
#include <stdio.h>
int main(void)
{

    int i = 0;
    int code[10] = {11,22,33,44,55,66,77,88,99,100}; // 代表十个人分数
    int sum = 0,p;
    for(i=0;i<10;i++)
    {
        sum += code[i];
    }
    p = sum/10;
    printf("总分sum = %d , 平均分p = %d",sum,p);
    return 0;
}
