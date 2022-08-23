#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 255

int main()
{
			/*1. Создать файл, записать строку, закрыть.
	 		  2. Вторично открыть файл и прочитать строку с конца файла.*/
	
	FILE*test;
	if (NULL == (test = fopen("test.txt", "w")))
	{
		perror("ошибочка test.txt");
        exit(1);
	}
	char*text = "hello world!\n";
	fputs(text, test);
	fclose(test);

	if (NULL == (test = fopen("test.txt", "r")))
	{
		perror("ошибочка test.txt");
        exit(1);
	}
	char c[COUNT]={};
	while (NULL != (fgets(c, COUNT, test)))
	{
		printf("%s", c);
	}
	for (int i = strlen(c) - 1; i >= 0; i--)
	{
		fseek(test, i, SEEK_SET);
		fgets(c, sizeof(char)+1, test);
		printf("%s", c);
	}
	printf("\n");
	fclose(test);
	return 0;
} 