/**
 * ���һ��ѧ���ɼ�����ϵͳ��������ɾ�Ĳ�ѧ���ɼ�
 * 
 * ϵͳ2.0
 * 
 * 
*/
#include<stdio.h>
#include<string.h>

typedef struct student
{
    char name[256]; // ѧ������
    int math;       // ��ѧ�ɼ�
    int chinese;    // ���ĳɼ�
    int english;    // Ӣ��ɼ�

}STU;




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

int manage_system()
{
    int key;
    int i;
    int index;
    int num = 0; // ��¼�Ѳ����ѧ������
    STU str_stu[100];// �������ѧ����Ϣ
    // ��ʼ��
    memset(str_stu,0,sizeof(STU)*100);
    scanf("%d",&key);

    while (key!=0)
    {
        if(key == 1)
        {
            // 1�� ���ӳɼ�
            printf("������ѧ������!\n");
            scanf("%s",&str_stu[num].name);
            printf("������ѧ��Ӣ��ɼ�!\n");
            scanf("%d",&str_stu[num].english);

            printf("������ѧ�����ĳɼ�!\n");
            scanf("%d",&str_stu[num].chinese);

            printf("������ѧ����ѧ�ɼ�!\n");
            scanf("%d",&str_stu[num].math);
            num ++;
            printf("����ɹ���\n");
        }
        else if(key == 2)
        {
            // 2��ɾ��ѧ���ɼ�
            if(num ==0)
            {
                printf("ϵͳû�����ݣ������������\n");
            }
            else
            {
                printf("����ɾ����һ��ѧ��\n");
                scanf("%d",&index);
                for(i = num;i>index;index++)
                {
                    strcpy(str_stu[index].name,str_stu[index+1].name);
                    str_stu[index].chinese= str_stu[index+1].chinese;
                    str_stu[index].english= str_stu[index+1].english;
                    str_stu[index].math= str_stu[index+1].math;
                }
                num --;
            }
        }
        else if(key == 3)
        {
            // 3���޸�ѧ���ɼ�
            printf("�����޸���һ��ѧ��\n");
            scanf("%d",&index);

            printf("������ѧ������!\n");
            scanf("%s",&str_stu[index].name);
            printf("������ѧ��Ӣ��ɼ�!\n");
            scanf("%d",&str_stu[index].english);

            printf("������ѧ�����ĳɼ�!\n");
            scanf("%d",&str_stu[index].chinese);

            printf("������ѧ����ѧ�ɼ�!\n");
            scanf("%d",&str_stu[index].math);

            printf("����ɹ���\n");
        }
        else if(key == 4)
        {
            // 4����ѯѧ���ɼ�
            printf("|NO\t | Name\t | English | Chinese | Math \n");
            for(i = 0;i<num;i++)
            {
                printf("|%d\t |%s\t | %d\t | %d\t | %d\t \n",i,str_stu[i].name,str_stu[i].english,str_stu[i].chinese,str_stu[i].math);
            }
        }
        else
        {
            // ��ʾ����
            printf("������ˣ������� \n");

        }
        printf("���ٴ�����ָ�� \n");
        scanf("%d",&key);
    }
    



    return 0;
}


int main()
{
    head_print();
    manage_system();

    return 0;
}




