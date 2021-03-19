/*
 * @Author: lgw
 * @Date: 2021-03-07 19:56:49
 * @LastEditTime: 2021-03-07 21:03:46
 * @LastEditors: Do not edit
 * @FilePath: \project\manage_system.c
 * @Description: ѧ���ɼ�����ϵͳ��������ɾ�Ĳ�ɼ� v1.0
 */

#include<stdio.h>
#include<string.h>
#define N 100
// ѧ������
char stu_name[N][256];
// Ӣ�ĳɼ�
int stu_en_score[N];
// ���ĳɼ�
int stu_ch_score[N];
// ��ѧ�ɼ�
int stu_ma_score[N];

// ��¼ϵͳ����������
int num =0;

void head_print()
{
    printf("*******ѧ���ɼ�����ϵͳ*********\n");
    printf("*       ���������°���:        *\n");
    printf("*       1������ѧ���ɼ�        *\n");
    printf("*       2��ɾ��ѧ���ɼ�        *\n");
    printf("*       3���޸�ѧ���ɼ�        *\n");
    printf("*       4����ѯѧ���ɼ�        *\n");
    printf("*       0���˳�ϵͳ            *\n");
    printf("*******************************\n");

}

// ��ʼ��
void init_sys()
{
    memset(stu_name,'0',N*256);

    memset(stu_en_score,0,N);
    memset(stu_ch_score,0,N);
    memset(stu_ma_score,0,N);

}

int manage_sys()
{
    int key = 0;

    scanf("%d",&key);

    while (key !=0)
    {
        switch (key)
        {
        case 1:
                insert_score(num);
                num++;
            break;
        case 2:
                del_score();
            break;
        case 3:
                modify_score();
            break;
        case 4:
             select_core();
             break;
        default:
            break;
        }

        printf("���ٴ�����ָ��\n");
        scanf("%d",&key);

    }
    return 0;
}

void insert_score(int index)
{
    printf("������ѧ������!\n");
    scanf("%s",&stu_name[index]);

    printf("������ѧ��Ӣ��ɼ�!\n");
    scanf("%d",&stu_en_score[index]);

    printf("������ѧ�����ĳɼ�!\n");
    scanf("%d",&stu_ch_score[index]);

    printf("������ѧ����ѧ�ɼ�!\n");
    scanf("%d",&stu_ma_score[index]);

    printf("����ɹ���\n");
}

void del_score()
{
    int index = 0;
    int i;
    printf("�����ɾ���ڼ������ݣ�");
    scanf("%d",&index);

    for( i = num ;i>index;index++)
    {
        strcpy(stu_name[index],stu_name[index+1]);
        stu_en_score[index] = stu_en_score[index+1];
    }

}


void modify_score()
{
    printf("������޸ĵڼ������ݣ�\n");
    int index = 0;
    scanf("%d",&index);

    insert_score(index);

}

void select_core()
{
    int i=0;
    printf("|NO\t | Name\t | English | Chinese | Math \n");

    for(i=0;i<num;i++)
    {
        printf("|%d\t |%s\t | %d\t | %d\t | %d\t \n",i,stu_name[i],stu_en_score[i],stu_ch_score[i],stu_ma_score[i]);

    }
}

int main()
{
    head_print();
    init_sys();
    manage_sys();
    return 0;
}

