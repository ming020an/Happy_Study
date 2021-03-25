#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
	   

#define  PATHNAME "/home/gec"
#define  PROJ_ID    143


//sizeof(struct msgbuf) = sizeof(mtype) ＝ 4
struct msgbuf
{
	long mtype;
	char mtext[0]; //柔性数组!!!
};


int main()
{
	key_t key;


	//生成一个system v ipc的key
	key = ftok(PATHNAME, PROJ_ID);
	if (key == -1)
	{
		perror("ftok error");
		return -1;
	}


	//打开一个 system v消息队列
	int msg_id = msgget(key, IPC_CREAT | 0664);
	if (msg_id == -1)
	{
		perror("msgget error:");
		return -1;
	}


	char buf[256];
	fgets(buf, 256,stdin);

	struct msgbuf *p = malloc(sizeof(struct msgbuf) + strlen(buf) + 1);
	p->mtype = 100;
	memcpy(p->mtext, buf, strlen(buf) + 1);


	int r = msgsnd(msg_id, (void*)p,  strlen(buf) + 1, 0);
	if (r == -1)
	{
		perror("msgsnd error");
		return -1;
	}

	
}
