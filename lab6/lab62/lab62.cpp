// lab62.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#define FILE(path, file, mode)\
FILE* file;\
file = fopen (path, mode);\
	if (!file) {\
		printf("Error");\
		return -1;\
	}
#define COPY(file, dest, buf, b)\
while (!feof(file)) {\
	b = fgets(buf, sizeof(buf), file);\
	if (b == NULL) {\
		if (feof(file) != 0) {\
			printf("Read ends\n");\
			break;\
		}\
		else {\
			printf("Error\n");\
			break;\
		}\
	}\
	fprintf(dest, "%s", buf);\
}

int main()
{
	char a[512];
	char *b;
	char file1[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file1.txt";
	char file2[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file2.txt";
	char file3[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file3.txt";
	char file4[] = "C:\\Users\\User\\source\\repos\\lab 6\\lab 6_2\\file4.txt";
	FILE(file1, fp1, "r");
	FILE(file2, fp2, "r");
	FILE(file3, fp3, "r");
	FILE(file4, fp4, "w");
	COPY(fp1, fp4, a, b);
	COPY(fp2, fp4, a, b);
	COPY(fp3, fp4, a, b);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	system("pause");
	return 0;
}
