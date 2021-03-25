#include <sys/types.h>
#include <dirent.h>

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>


int dirsize(const char *pathname)
{
	int size = 0; //该目录文件的大小

	DIR *dir = opendir(pathname);
	if (dir == NULL)
	{
		perror("opendir error:");
		return 0;
	}

	struct dirent *dirp = NULL ;

	while (dirp = readdir(dir))
	{

		if (strcmp(dirp->d_name, ".") == 0 || 
			strcmp(dirp->d_name, "..") == 0)
		{
			continue;
		}

		char filename[512];
		sprintf(filename, "%s/%s", pathname, dirp->d_name);
		struct stat st;

		stat(filename, &st);
		if (S_ISREG(st.st_mode))
		{
			size += st.st_size;
		}else if (S_ISDIR(st.st_mode))
		{
			size += dirsize(filename);
		}
		printf("文件大小：size = %d\n", size);
		return size;
	}


	closedir(dir);

	return size;
}

int main(int argc, char *argv[])
{
	int size;
	DIR *dir;
	dir = opendir(argv[1]);//输入你需要打开目录文件参数
	
	if (dir == NULL)
	{
		perror("opendir error");
		return -1;
	}

	struct dirent *dirp = NULL;
	size=dirsize(argv[1]);
	int num = 0;
	while (dirp = readdir(dir))
	{
		char filename[512]; //保存子文件的完整的文件名
		sprintf(filename, "%s/%s", argv[1], dirp->d_name);
		//printf("%s \n ", dirp->d_name);
		//printf("%s \n", filename);
		
		struct stat st;
		stat(filename, &st);

		if (S_ISDIR(st.st_mode))
		{
			num++;
		}
	}
	printf("文件大小：size = %d\n", size);
	printf("目录文件：num = %d\n", num);


	closedir(dir);
}