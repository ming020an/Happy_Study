#include<stdio.h>
#include<windows.h>
// ָ�뺯�� type *func (�����б�)       ����ֵΪָ��
// ����ָ�� type (*func) (�����б�)     ָ������ָ��
// ����ָ������ type (*func[ ])(�����б� )  һ����Ա���Ǻ���ָ�������
// ����ָ������ָ�� type (* (*func )[ ])(�����б� ) ָ����ָ�������ָ��

void fun1()
{
    printf("���ú���fun1\n");
}
void fun2()
{
    printf("���ú���fun2\n");
}
void fun3()
{
    printf("���ú���fun3\n");
}
int main()
{
    // ����ָ��ָ������ַ
    //void(*pfun)() = &fun1;
    //void(*pfun2)() = &fun2;
    //void(*pfun3)() = &fun3;
    //���������Ƕ���һ���������������װ��ȥ��
    void(*pfunarr[3])();
    void(*(*pfunarr2)[3])();
    //�������ؿ��Ÿ�ָ�����飬������һ������3���Ժ���ָ��Ϊ���ݵ�Ԫ�صĺ���ָ�����顣
    pfunarr[0] = &fun1;
    pfunarr[1] = &fun2;
    pfunarr[2] = &fun3;

    pfunarr2 = &pfunarr;
    (*pfunarr2)[0]();
    pfunarr[1]();
    system("pause");
    return 0;
}