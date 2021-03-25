#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
	int r;
	int  pipefd[2]; //������Źܵ��Ķ���д�ļ���������
	int pid;
	
	r = pipe(pipefd);  //����fork�����ܵ�
	if (r == -1)
	{
		perror("pipe error:");
		return -1;
	}

	int st;
	pid = fork();
	if (pid > 0)  //������
	{
		r = write(pipefd[1], "hello", 5);
		wait(&st);
	} 
	else if (pid == 0) //�ӽ���
	{
		char str[256] = {0};
		r = read(pipefd[0], str, 256);
		if (r > 0)
		{
			printf("chlid data: %s\n",str);
		}
	}
	
	close(pipefd[0]);
	close(pipefd[1]);
	return 0;
}
//chlid data: hello
