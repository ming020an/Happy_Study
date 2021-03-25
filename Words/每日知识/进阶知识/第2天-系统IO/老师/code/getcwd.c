#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int  main()
{
	char buf[512];
	char *p;


	p = getcwd(buf, 512);
	if (p == NULL)
	{
		perror("getcwd error");
		return -1;
	}

	printf("current working directory : %s\n", buf);



	chdir("/home/gec");


	p = getcwd(buf, 512);
	if (p == NULL)
	{
		perror("getcwd error");
		return -1;
	}

	printf("current working directory : %s\n", buf);


	//fopen("1.txt", "w");
	return 0;
}
