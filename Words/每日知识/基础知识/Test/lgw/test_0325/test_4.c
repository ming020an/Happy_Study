#include<stdio.h>
#include<windows.h>
// 函数指针使用
int getMax(int a,int b)
{
    int t;
    if(a>b)
    t = a;
    else
    t = b;
    return t;
}

int main()
{
    int (*func)();
    func = getMax;
    printf("%d\n",func(100,66));

    return 0;
}