#include<stdio.h>
#include<windows.h>
// �򵥵���ʾ��ָ��ʹ��
int main()
{
    int *p;
    int a = 100;
    int *p_null = 0;
    int *p_ye;
    p = &a;
    printf("a = %d,*p = %d,p = %p\n",a,*p,p);
    // printf("p_null = %d\n",*p_null);


    return 0;
}