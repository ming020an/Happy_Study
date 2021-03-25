#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int pfd[2];
	int pfd2[2];
	int r;

	r = pipe(pfd);
	if (r == -1)
	{
		perror("pipe failed:");
		return -1;
	}

	r = pipe(pfd2);
	if (r == -1)
	{
		perror("pipe failed:");
		return -1;
	}

	pid_t pid = fork();
	if (pid > 0) //�����̿��Զ�д��ֻ�Ƕ���pfd2��д��pfd��
	{
		/*�����̣����ܵ���д��Ӧ�ùرն���*/
		 //close(pfd[0]);
		 //close(pfd2[1]);

		char *str = "nihao, son";

		sleep(3);
		r = write(pfd[1], str, strlen(str));
		if (r == -1)
		{
			perror("write error:");
			return -1;
		}

		printf("write finished\n");

		char buf[256];
		r = read(pfd2[0], buf, 256);
		if (r > 0)
		{
			buf[r] = '\0';
			printf("%s\n", buf);
		}
	}

	else if (pid == 0) //�ӽ��̿��Զ�д��ֻ�Ƕ���pfd��д��pfd2��
	{
		/*�ӽ��̣��ӹܵ������Ӧ�ùر�д��*/
		// close(pfd[1]);
		//close(pfd2[0]);

		char buf[256];

		printf("before read\n");
		r = read(pfd[0], buf, 256);
		if (r > 0)
		{
			buf[r] = '\0';
			printf("%s\n", buf);
		}
		printf("read over\n");

		write(pfd2[1], buf, r);
	}
	else
	{
		perror("fork failed:");
		return -1;
	}
}
/*
before read//�ӽ��̵ȴ�
write finished //������д��
nihao, son//�ӽ��̶���
read over//�ӽ��̶���
////�ӽ��̽��������Ϣд��ܵ�pfd2
nihao, son//�����̴ӹܵ�pfd2����
*/



