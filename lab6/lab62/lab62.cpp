// lab62.cpp : Defines the entry point for the console application.
//

Отключить для языка: английский
#include "stdafx.h"

#define FILE(path, file, mode)\
FILE* file;\
file = fopen (path, mode);\
	if (!file) {\
		printf("Error");\
		return -1;\
	}

int copy(FILE*, FILE*, char[], char[]);

int main()
{
	char a[512];
	char *b = 0;
	char file1[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file1.txt";
	char file2[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file2.txt";
	char file3[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file3.txt";
	char file4[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file4.txt";
	FILE(file1, fp1, "r");
	FILE(file2, fp2, "r");
	FILE(file3, fp3, "r");
	FILE(file4, fp4, "w");
	copy(fp1, fp4, a, b);
	copy(fp2, fp4, a, b);
	copy(fp3, fp4, a, b);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	system("pause");
	return 0;
}

int copy(FILE* file, FILE* dest, char buf[], char b[]) {
	while (!feof(file)) {
		b = fgets(buf, sizeof(buf), file);
		if (b == NULL) {
			if (feof(file) != 0) {
				printf("Read ends\n");
				break;
			}
			else {
				printf("Error\n");
				break;
			}
		}
		fprintf(dest, "%s", buf);
	}
	return 0;
