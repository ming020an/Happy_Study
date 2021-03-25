#include <stdio.h>
#include <errno.h>

int main()
{
	char *s = "ABCDE";
	puts(s);

	fputs(s, stdout);
}
