#include <stdio.h>
#include <windows.h>
//指针函数 返回值为指针的函数
int b;
int *func(int a)
{
    b=a;
    return &b;
}
int main()
{
    int *p;
    p=func(1000);
    printf("%p,*p=%d\n",p,*p);
    return 0;

}