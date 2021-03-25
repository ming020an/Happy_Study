#include<stdio.h>
#include<windows.h>
// 简单的演示下指针使用
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