#include <stdio.h>
#include <errno.h>

int main()
{
	char filename[256];
	char *file = "xxx.mp3";
	char *file2 = "yyy.mp3";
	int r = 0;
	 r += sprintf(filename, "/home/%s ", file);  // filename: /home/xxx.mp3 

	r +=	sprintf(filename + r, "/home/%s ", file2); // filename: /home/yyy.mp3 


	printf("%s\n", filename);
	
}
