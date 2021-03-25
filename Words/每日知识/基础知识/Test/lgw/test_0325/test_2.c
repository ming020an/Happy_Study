#include<stdio.h>
#include<windows.h>
// 数组指针的使用
int main()
{
    int a = 110;
    int * arr[10];
    int *p = &a;

    arr[0] = p;
    printf(" %d \n",*arr[0]);

    return 0;
}