// lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


typedef double(*func_t)(double);
typedef int(*handler_t)(void*, FILE*);

void process_func(
	double a
	, double b
	, double h
	, double(*pf)(double)
);

int tabulate_func1(func_t, FILE*);
int tabulate_func2(func_t, FILE*);
double trapezia_metod(func_t, double, double, double);
double func1(double);
double func2(double);

int main()
{
	double a = 0, b = 1, eps = 1e-7;
	char file[] = "C:\\Users\\User\\source\\repos\\lab 6\\tab.txt";
	FILE* fp;
	fp = fopen(file, "w");
	if (!fp) {
		printf("Error");
		return -1;
	}
	fprintf(fp, "Function ¹1\n");
	tabulate_func1(func1, fp);
	printf("\n");
	fprintf(fp, "Function ¹2\n");
	tabulate_func2(func2, fp);
	fprintf(fp, "Integral F1 - %d\n", trapezia_metod(func1, a, b, eps));
	fprintf(fp, "Integral F2 - %d\n", trapezia_metod(func2, a, b, eps));
	fclose(fp);
	system("pause");
	return 0;
}

int tabulate_func1(func_t f, FILE* pf)
{
	double a = -0.5, b = 0.5, h = 0.1;
	double x = a;
	process_func(a, b, h, func1);
	for (; x <= b; x += h) {
		double y = f(x);
		FILE* fp = pf ? pf : stdout;
		fprintf(pf, "%f %f\n", x, y);
	}
	return 0;
}

int tabulate_func2(func_t func, FILE* pf)
{
	double a = -4, b = 5, h = 0.15;
	double x = a;
	for (; x <= b; x += h) {
		double y = func(x);
		FILE* fp = pf ? pf : stdout;
		fprintf(pf, "%f %f\n", x, y);
	}
	process_func(a, b, h, func2);
	printf("\n");
	return 0;
}

double trapezia_metod(func_t func, double a, double b, double e)
{
	double S = 0, x, h = 0.01;
	x = a;
	while (x < b)
	{
		S = S + (func(x + h) + func(x))*h / 2;
		if (0.5*(func(x + h) + func(x))*h >= e)
			x = x + h;
		else
			break;

	}
	return S;
}

int is_min(double y1, double y2, double y3)
{
	return y2 < y1 && y2 < y3;
}

int is_max(double y1, double y2, double y3)
{
	return y2 > y1 && y2 > y3;
}

void get_mark_extr(double y[], int sz, char* mark)
{
	if (sz < 3)
	{
		perror("Invalid count of points\n");
		exit(-1);
	}

	strcpy(mark, "");
	if (is_min(y[0], y[1], y[2]))
	{
		strcpy(mark, "Min");
	}
	else
	{
		if (is_max(y[0], y[1], y[2]))
		{
			strcpy(mark, "Max");
		}
	}
}

void process_func(
	double a
	, double b
	, double h
	, double(*pf)(double)
)
{
	double x[3], y[3];
	x[0] = a; y[0] = pf(x[0]);

	int j;

	for (j = 0; j < 2; ++j)
	{
		x[j + 1] = x[j] + h;
		y[j + 1] = pf(x[j + 1]);
	}

	{
		char mark[20] = "";
		get_mark_extr(y, 3, mark);
		for (j = 0; j < 3; ++j)
		{
			printf("%.3f %.3f %s\n", x[j], y[j], j == 1 ? mark : "");
		}
	}

	for (; x[2] <= b;)
	{
		for (j = 0; j < 2; ++j)
		{
			x[j] = x[j + 1];
			y[j] = y[j + 1];
		}

		x[2] += h;
		y[2] = pf(x[2]);
		{
			char mark[20] = "";
			get_mark_extr(y, 3, mark);
			printf("%.3f %.3f %s\n", x[j], y[j], mark);
		}
	}

}

double func1(double x)
{
	return log(1 + 2 * x);
}

double func2(double x)
{
	if (x <= -3) {
		return -2 * pow(x, 4) + 3 * x * x - 1;
	}
	if (x < 4 && x > -3) {
		return pow(x, 4) - fabs(x - 1);
	}
	if (x >= 4) {
		return fabs(x - 2) - x + 1;
	}
}
