#include <stdio.h>
#include <stdio.h>
//函数指针  指向函数的指针
//类型(*名字)(参数列表)
    int getmax (int a,int b)
    {
        int t;
        if (a>b)
        t=a;
        else
        t=b;
        return t;
    }
    int main()
    {
        int (*func)();
        func=getmax;
        printf("%d\n",func(100,66));
        return 0;
    }
