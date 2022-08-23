#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define COUNT 255

int main()
{
			/*1. Создать файл, записать строку, закрыть.
	 		  2. Вторично открыть файл и прочитать строку с конца файла.*/
	

	int file = open("test.txt", O_WRONLY | O_CREAT);
	if (file == -1)
	{
		printf("ошибка открытия файла\n");
		exit(1);
	}
	char*text = "hello world!";
	int returWrite;
	if ((returWrite = write(file, text, strlen(text))) == -1)
	{
		printf("ошибка записи файла\n");
		exit(1);
	}
	close(file);

	int file1 = open("test.txt", O_RDONLY);
	if (file1 == -1)
	{
		printf("ошибка открытия файла 1\n");
		exit(1);
	}
	char buf[COUNT] = {0};
	int returnRead;
	if ((returnRead = read(file1, buf, COUNT)) == -1)
	{
		perror("ошибка чтения файла\n");
		exit(1);
	}
	printf("text buffer = %s\n", buf);
	char reversBuf[COUNT] = {0};
	for (int i = COUNT; i >= 0; i--)
	{
		lseek(file1, i, SEEK_SET);
		if ((returnRead = read(file1, reversBuf, 1)) == -1)
			{
				perror("ошибка чтения файла\n");
				exit(1);
			}
		printf("%s", reversBuf);
	}
	printf("\n");
	close(file1);

	return 0;
} 