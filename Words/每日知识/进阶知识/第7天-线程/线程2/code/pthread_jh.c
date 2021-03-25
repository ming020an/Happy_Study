#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void * t_routine(void *data)
{
	printf("data = %p\n",data);

	int b = *((int *)data);
	printf("b = %d\n", b);

	char *p = malloc(1);
	*p = 'A';

	pthread_exit(p);
	//return p;
}


int main()
{
	pthread_t ptid;//���������߳�ID
	int a = 1024;
	printf("a = %p\n", &a);
	int r = pthread_create(&ptid, NULL,t_routine, (void *)&a);

	//sleep(1);	//main()��ʾ���̣߳����߳̽������ͱ�ʾ���̽�����

	char *ret = NULL;
	pthread_join(ptid, (void **)&ret);
	printf("*ret = %c\n",*ret);

	free(ret);

	return 0;
}

#if 0
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int share ; //
pthread_mutex_t slock; //�̻߳���������������Ϊ��ʲô?
					//��Ϊ�˱���share�����ڵ�

void * routine1(void *data)
{
	pthread_detach(pthread_self());

	char *msg = (char *)data;
	
	pthread_mutex_lock(&slock);//P() //pthread_mutex_lock
	while (*msg != '\0')
	{
		fprintf(stderr, "%c", *msg);
		usleep(100);
		msg++;
	}
	pthread_mutex_unlock(&slock);//V()//pthread_mutex_unlock

	char *p = malloc(sizeof(char));

	*p = 'A';
	pthread_exit(p);
}

int main()
{
	int r;
	pthread_t tid1,tid2; //���������´������߳�ID

	pthread_mutex_init(&slock, NULL); //��ʼ���̻߳�����

	r = pthread_create(
			&tid1, //��һ������, pthread_t *,�����������̵߳�ID
			NULL, //�ڶ���������Ϊ�߳����ԣ�NULL���ʾ����Ĭ������
			routine1,// void * (*start_routine) (void *),����������������ָ�룬ָ���̺߳���
			"AAAAAAAAAAAAAAAAAAAAA" //���ĸ�����������Ϊ�̺߳����Ĳ�����
	);

	if (r == -1)
	{
		perror("pthread_create error:");
		return -1;
	}

	r = pthread_create(
			&tid2, //��һ������, pthread_t *,�����������̵߳�ID
			NULL, //�ڶ���������Ϊ�߳����ԣ�NULL���ʾ����Ĭ������
			routine1,// void * (*start_routine) (void *),����������������ָ�룬ָ���̺߳���
			"BBBBBBBBBBBBBBBBBBBBBB" //���ĸ�����������Ϊ�̺߳����Ĳ�����
	);

	if (r == -1)
	{
		perror("pthread_create error:");
		return -1;
	}

	char *ret = NULL;

	pthread_join(tid1,(void **) &ret);
	printf("*ret1 = %c\n", *ret);

	pthread_join(tid2,(void **) &ret);
	printf("*ret2 = %c\n", *ret);

	free(ret);

	/*main���������̣߳� ���߳̽�������ʾ���̾���
	�����ˣ���ô����������ڵ����������̣߳�Ҳ��
	over��*/

	pthread_mutex_destroy(&slock);
	pthread_exit(NULL);
}

#endif

