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
		
		
	}


	closedir(dir);

	return size;
}


int main(int argc, char *argv[])
{
	printf("%d\n", dirsize(argv[1]));

	return 0;
}
