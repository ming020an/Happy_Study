#include<stdio.h>
#include<string.h>
#include<windows.h>
// ������
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
    //printf("��ַa = %p,\n��ַb = %p,\n��ַc = %p,\n��ַt = %p,\n ",test.a,test.b,test.c,&t);
    printf("��ַa = %p,\n��ַb = %p,\n��ַt = %p,\n ",test.a,test.b,&t);

    system("pause");
    return 0;
}