#include<stdio.h>
#include<windows.h>
int b;
// ָ�뺯�� ����ֵ��ָ��
int * func( int a)
{
    b = a;
    return &b;
}

int main()
{
    int * p;
    p = func(1000);

    printf("%p,*p =%d\n",p,*p);

    return 0;
}

