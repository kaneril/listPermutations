// lab5.2_0.cpp: определяет точку входа для консольного приложения.
//
/*5. Перечислить   перестановки   из   N   элементов  путем
транспозиции смежных элементов с рекурсией и без нее.*/
#include "stdafx.h"

void recurs_listPermutations();
void recurs(int *, int, int, bool);
void iterat_listPermutations();
void swap(int *, int *);
void print_Permutations(int *);

int main()
{
	//Подключаем русский язык
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char i = ' ';
	while (i != '3')
	{
		printf_s("\n**************************");
		printf_s("\nПеречислить перестановки из N элементов путем транспозиции смежных элементов");
		printf("\nВыберите действие:\n1 с использованием рекурсии \n2 без использования рекурсии\n3 Завершить сеанс\n");
		printf_s("Укажите код выбранного действия: ");
		i = _getche();
		switch (i)
		{
		case '1':
			recurs_listPermutations();
			break;
		case '2':
			iterat_listPermutations();
			break;
		case '3':
			exit(0);
		default:
			printf_s("\nВведен неверный код действия\n");
			break;
		}
	}
    return 0;
}

void recurs_listPermutations()
{
	int n = 0;
	int p[20];
	printf_s("\nВведите порядок перестановок: ");
	scanf_s("%d", &n);
	p[0] = 1;
	recurs(p, n, 1, 0);
}

void recurs(int *p, int n, int step, bool flag)
{
	int pp[20];
	int i = 0;
	while (*p > 0)
	{
		pp[i] = *p;
		p++;
		i++;
	}
	if (n == step)
	{
		print_Permutations(pp);
	}
	else
	{
		if (step == n-1)
		{
			printf_s("**************************\n");
		}
		step++;
		*(pp + step-1) = step;
		if (flag == 0)
		{
			recurs(pp, n, step,0);
			for (int j = 1; j < step; j++)
			{
				swap(pp + step - j, pp + step - 1 - j);
				recurs(pp, n, step,j%2);
			}
		}
		else
		{
			for (int j = 1; j < step; j++)
			{
				swap(pp + step - j, pp + step - 1 - j);
			}
			recurs(pp, n, step, 1);
			for (int j = 1; j < step; j++)
			{
				swap(pp + j, pp + j - 1);
				recurs(pp, n, step,(j-1)%2);
			}
		}

	}
}

void iterat_listPermutations()
{
	int n = 0;
	int p[20];
	printf_s("\nВведите порядок перестановок: ");
	scanf_s("%d", &n);
	int N = 1;
	for (int i = 1; i <= n; i++)
	{
		p[i-1] = i;
		N = N * i;
	}
	swap(p, p+1);
	for (int i = 0; i < N; i = i + n)
	{
		printf_s("**************************\n");
		if (i / n % 2 == 0)
		{
			swap(p, p + 1);
			print_Permutations(p);
			for (int j = 1; j < n; j++)
			{
				swap(p + n - j, p + n - 1 - j);
				print_Permutations(p);
			}
		}
		else
		{
			swap(p + n - 1, p + n - 2);
			print_Permutations(p);
			for (int j = 1; j < n; j++)
			{
				swap(p + j, p + j - 1);
				print_Permutations(p);
			}
		}
	}
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void print_Permutations(int *p)
{
	while (*p > 0)
	{
		printf_s("%d ", *p);
		p++;
	}
	printf_s("\n");
}