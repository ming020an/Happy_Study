/*
 * @Author: lgw
 * @Date: 2021-03-03 20:53:58
 * @LastEditTime: 2021-03-07 19:08:22
 * @LastEditors: Do not edit
 * @FilePath: \test_0302\test_1.c
 * @Description: 输入10个数，并排序
 */
#include<stdio.h>
#include <string.h>

int insert_sort()
{
    int number[10];     // 存放排序好的数
    int index;          // 存放每次输入的数
    int i,j;

    memset(number,0,sizeof(int)*10);
    for(i = 1 ;i<10;i++)
    {
        printf("第 %d个数 =%d\n",i,number[i]);
    }

    for(i = 1;i<=10;i++)
    {
        printf("请输入第 %d个数\n",i);
        // 输入数
        scanf("%d",&index);
        for(j = i;j>0;j--)
        {
            if(number[j-1]>index)
            {   
                number[j]=number[j-1];
            }
            else
            {
                break;
            }
        }
        number[j] = index ;

    }
    for(i = 0 ;i<10;i++)
    {
        printf("第 %d个数 =%d\n",i+1,number[i]);
    }

    return 0;
}

int main ()
{
    int ret;
    ret = insert_sort();
    printf("ret = %d\n",ret);
    return 0 ;
}

