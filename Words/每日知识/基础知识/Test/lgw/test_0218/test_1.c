/*
 * @Author: lgw
 * @Date: 2021-02-18 14:30:32
 * @LastEditTime: 2021-02-18 16:17:58
 * @LastEditors: Do not edit
 * @FilePath: \test_0218\test_1.c
 * @Description: 数组练习1.定义一个数组,从键盘获取所有元素的数据
 */
#include<stdio.h>
int main()
{
    int i;
    int a[10];
    for(i=0;i<10;i++)
    {
        printf("请输入第 %d 个值 ：\n",i);
        scanf("%d",&a[i]); // 相当于 a[i] = 你输入的值
    }

    for(i=0;i<10;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    return 0;
}