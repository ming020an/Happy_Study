#include <stdio.h>
#include <errno.h>


int main()
{
	#if 0
	//char s[8];
	//char *s; //sָ���ĸ��ռ䣬��֪��!!!! mallocһ���ռ䣬��ֵ��s

	char *s = "12345"; //sָ��һ��ֻ���ռ䣬gets(s)Ҳ���������

	gets(s);//����Ҫȷ��sָ���һ��ռ䣬�ǿ���д�ġ�

	#endif

	char s1[8];
	char s2[8] = {"12345"};

	printf("%p\n%p\n",s1,s2);

	//gets(s1); //�����û��������8���ַ����������Ϊ��undefined 
	fgets(s1, 9, stdin);
	
	printf("%s\n%s\n", s1,s2);
	
}
