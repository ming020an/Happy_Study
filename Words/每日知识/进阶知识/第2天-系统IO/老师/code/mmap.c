#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd;
	char *p;
	
	fd = open(argv[1], O_RDWR );
	if (fd == -1)
	{
		perror("open failed");
		return -1;
	}

	p = mmap(	
			NULL, //��һ������Ϊӳ����£�NULL��ʾ�ò���ϵͳ���з���
			4096, //�ڶ�������Ϊӳ�����ݵĳ��ȣ������ֻӳ���ļ���һ��������
				//�����ڿ����ڴ�ʱ��������ȡPAGE_SIZE(4k)��������
			PROT_WRITE, //����������Ϊӳ�������ӳ��
			MAP_SHARED,//MAP_SHARED, //���ĸ�����Ϊӳ�䷽ʽ�������������Ƿ�ɼ�
			fd, //���������Ϊ�ļ�����������ʾҪӳ���ĸ��ļ�
			0 //����������Ϊƫ��������ʾҪ���ļ����ĸ�λ�ÿ�ʼӳ��
		);
	if (p == MAP_FAILED)
	{
		perror("MMAP failed");
		return -1;
	}

	strcpy(p, "better future");

	//while (1);



	munmap(p, 4096);
	close(fd);
}
