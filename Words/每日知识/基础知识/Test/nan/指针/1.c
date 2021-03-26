#include <stdio.h>
#include <windows.h>
//指针使用
int main()
{
int *p;    //表示一个指向整形数的指针p
int a=100;
p=&a;
printf("a=%d,p=%d,p=%p\n",a,*p,p);
return 0;
}