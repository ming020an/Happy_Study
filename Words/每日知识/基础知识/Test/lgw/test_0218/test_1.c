/*
 * @Author: lgw
 * @Date: 2021-02-18 14:30:32
 * @LastEditTime: 2021-02-18 16:17:58
 * @LastEditors: Do not edit
 * @FilePath: \test_0218\test_1.c
 * @Description: ������ϰ1.����һ������,�Ӽ��̻�ȡ����Ԫ�ص�����
 */
#include<stdio.h>
int main()
{
    int i;
    int a[10];
    for(i=0;i<10;i++)
    {
        printf("������� %d ��ֵ ��\n",i);
        scanf("%d",&a[i]); // �൱�� a[i] = �������ֵ
    }

    for(i=0;i<10;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    return 0;
}