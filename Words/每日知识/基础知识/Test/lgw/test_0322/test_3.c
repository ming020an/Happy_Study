#include<stdio.h>
#include<string.h>
#include<windows.h>
// 联合体
int main()
{
    int t = 0;
    union
    {
        //double c;
        char a ;
        int b;
        
    }test;
    // test.a = 'a';
    // test.b = 100;
    // test.c = 101;
    printf("%d",sizeof(test));
    //printf("地址a = %p,\n地址b = %p,\n地址c = %p,\n地址t = %p,\n ",test.a,test.b,test.c,&t);
    printf("地址a = %p,\n地址b = %p,\n地址t = %p,\n ",test.a,test.b,&t);

    system("pause");
    return 0;
}