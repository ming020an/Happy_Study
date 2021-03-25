#include<stdio.h>
#include<windows.h>
// 指针函数 type *func (参数列表)       返回值为指针
// 函数指针 type (*func) (参数列表)     指向函数的指针
// 函数指针数组 type (*func[ ])(参数列表 )  一个成员都是函数指针的数组
// 函数指针数组指针 type (* (*func )[ ])(参数列表 ) 指向函数指针数组的指针

void fun1()
{
    printf("调用函数fun1\n");
}
void fun2()
{
    printf("调用函数fun2\n");
}
void fun3()
{
    printf("调用函数fun3\n");
}
int main()
{
    // 函数指针指向函数地址
    //void(*pfun)() = &fun1;
    //void(*pfun2)() = &fun2;
    //void(*pfun3)() = &fun3;
    //接下来就是定义一个数组把他们三个装进去。
    void(*pfunarr[3])();
    void(*(*pfunarr2)[3])();
    //在这里呢看着个指针数组，他就是一个具有3个以函数指针为内容的元素的函数指针数组。
    pfunarr[0] = &fun1;
    pfunarr[1] = &fun2;
    pfunarr[2] = &fun3;

    pfunarr2 = &pfunarr;
    (*pfunarr2)[0]();
    pfunarr[1]();
    system("pause");
    return 0;
}