/*
 * @Author: lgw
 * @Date: 2021-01-30 16:22:06
 * @LastEditTime: 2021-01-30 16:53:17
 * @LastEditors: Do not edit
 * @FilePath: \test_0130\test_3.c
 * @Description: 
 */
#include<stdio.h>
/* 运算符 测试*/
int main(void)
{
    /* 算术运算符*/
    // int li_count = 10;
    // int li_value = 101;
    // printf(" 第一次 li_count = %d\n",li_count);
    // li_count ++ ;
    // printf(" 第二次 li_count = %d\n",li_count);
    // li_count -- ;
    // printf(" 第三次 li_count = %d\n",li_count);

    // printf(" 取余结果 = %d\n",li_value % li_count);

    /*逻辑运算符 */
    // 在C语言中 非0 代表真 0代表假
    // int li_ture = 1;
    // int li_false = 0;
    // if( (li_ture == 1) || (li_false != 0)) // 真 || 假
    // {
    //     printf(" 结果是 真\n");
    // }
    // else
    // {
    //     printf(" 结果是 假\n");
    // }
    
    /*条件运算符*/
    int li_a = 1;
    int li_b = 2;
    int li_c = 0;
    li_c = li_b >li_a ? 111:222;
    printf(" li_c = %d\n",li_c);


    return 0;
}
