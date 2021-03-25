#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>


int main(int argc, char *argv[])
{
	int r;
	struct stat st;

	r = stat(argv[1], &st);
	if (r == -1)
	{
		perror("stat error");
		return -1;
	}


	char buf[512];
	r = 0;

	//�ļ�����
	if (S_ISREG(st.st_mode))
	{
		r += sprintf(buf + r, "-");
	}else if (S_ISDIR(st.st_mode))
	{
		r += sprintf(buf + r, "d");
	}else if (S_ISCHR(st.st_mode))
	{
		r += sprintf(buf + r, "c");
	}else if (S_ISBLK(st.st_mode))
	{
		r += sprintf(buf + r, "b");
	}else if (S_ISFIFO(st.st_mode))
	{
		r += sprintf(buf + r, "p");
	}else if (S_ISLNK(st.st_mode))
	{
		r += sprintf(buf + r, "l");
	}else if (S_ISSOCK(st.st_mode))
	{
		r += sprintf(buf + r, "s");
	}
	
	//�ļ�Ȩ��
	if (st.st_mode & S_IRUSR)
	{
		r += sprintf(buf + r, "r");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}

	if (st.st_mode & S_IWUSR)
	{
		r += sprintf(buf + r, "w");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}


	if (st.st_mode & S_IXUSR)
	{
		r += sprintf(buf + r, "x");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}

	if (st.st_mode & S_IRGRP)
	{
		r += sprintf(buf + r, "r");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}

	if (st.st_mode & S_IWGRP)
	{
		r += sprintf(buf + r, "w");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}


	if (st.st_mode & S_IXGRP)
	{
		r += sprintf(buf + r, "x");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}


	if (st.st_mode & S_IROTH)
	{
		r += sprintf(buf + r, "r");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}

	if (st.st_mode & S_IWOTH)
	{
		r += sprintf(buf + r, "w");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}


	if (st.st_mode & S_IXOTH)
	{
		r += sprintf(buf + r, "x");
	}
	else
	{
		r += sprintf(buf + r, "-");
	}


	//Ӳ������
	r += sprintf(buf + r, " %d ", st.st_nlink);

	//�û�id, ���û�id
	r += sprintf(buf + r, "%d %d ", st.st_uid, st.st_gid);

	//�ļ���С
	r += sprintf(buf + r, "%lu ", st.st_size);

	
	//����޸�ʱ��
	r += sprintf(buf+r, " %s", ctime(&st.st_mtime));
	buf[r-1] = ' ';
	
	//�ļ���
	r += sprintf(buf + r, "%s", argv[1]);

	//���
	printf("%s\n", buf);
	
	return 0;
}
