#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
	   

#define  PATHNAME "/home/gec"
#define  PROJ_ID    143


//sizeof(struct msgbuf) = sizeof(mtype) �� 4
struct msgbuf
{
	long mtype;
	char mtext[1024];
};


int main()
{
	key_t key;


	//����һ��system v ipc��key
	key = ftok(PATHNAME, PROJ_ID);
	if (key == -1)
	{
		perror("ftok error");
		return -1;
	}


	//��һ�� system v��Ϣ����
	int msg_id = msgget(key, IPC_CREAT | 0664);
	if (msg_id == -1)
	{
		perror("msgget error:");
		return -1;
	}



	struct msgbuf buf;

	int r = msgrcv(msg_id, &buf, 1024, 0/*��Ϣ���ͣ�0Ϊ��������*/, 0);
	if (r > 0)
	{
		printf("type: %ld\n", buf.mtype);
		printf("data:%s\n", buf.mtext);
	}
	
}
