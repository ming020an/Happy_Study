#include <stdio.h>
#include <windows.h>
//数组指针
int main()
{
    int *arr[10];
    int a=100;
    int *p = &a;
    arr [0]=p;
    printf ("%d\n",*arr[0]);
    return 0;

}