#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#include "Header.h"

using namespace std;


int IsPrime(int *n);

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int  N;
	do
	{
		printf("\t\t----Введите номер задания: ");
		scanf_s("%d", &N);
		cin.get();
		printf("\n");
		switch (N)
		{
		case 1:
			/*1.В динамической матрице с одинаковым количеством элементов в каждой строке есть только единицы и нули.
			Найти количество строк, в которых есть хотя бы один нуль.*/
		{
			int *a = NULL;
			int cnt = 0;
			int len = 0;
			printf("Введите размер матрицы: ");
			scanf_s("%d", &len);
			a = (int*)malloc((len * len) * sizeof(int));
			if (a == NULL)
			{
				printf("Память не выделена");
			}
			else
			{
				printf("Можете продолжать: \n");
				for (int i = 0; i < len; i++)
				{
					for (int j = 0; j < len; j++)
					{
						*(a + i*len + j) = rand() % 2;
						printf("%d\t", *(a + i*len + j));
					}
					printf("\n");
				}
				int tmp = 0;
				for (int i = 0; i < len; i++)
				{
					for (int j = 0; j < len; j++)
					{
						if (*(a + i*len + j) == 0)
						{
							tmp++;
							break;
						}
					}
					cnt += tmp;
					tmp = 0;
				}
				printf("\n");
				printf("Количество строк, в которых есть хотя бы один нуль = %d\n", cnt);

			}
		}
		printf("\n");
		break;

		case 2:
			/*2.В динамической матрице с одинаковым количеством элементов в каждой строке получить номера строк,
			элементы каждой из которых образуют монотонно убывающую последовательность*/
		{
			int *mass = NULL;
			int *NumStr = NULL;
			int Str = 0;
			int Col = 0;

			GenMassTwoDimMalloc(mass, &Str, &Col, 0, 20);

			if (mass == NULL)
			{
				printf("Память не выделена");
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("Номера строк, элементы каждой из которых образуют монотонно убывающую последовательность:\n");
				int Ind = 1;
				int Sum = 0;
				for (int i = 0; i < Str; i++)
				{
					for (int j = 0; j < Col - 1; j++)
					{
						if (*(mass + i*Col + j) <= *(mass + i*Col + j + 1))
							Ind = 0;
					}
					if (Ind == 1)
					{
						NumStr = (int *)realloc(NumStr, (Sum + 1) * sizeof(int));
						*(NumStr + Sum) = i;
						printf("%d\n", *(NumStr + Sum));
						Sum++;
					}
					Ind = 1;
				}
				printf("\n");
			}
			free(mass);
			free(NumStr);
		}
		printf("\n");
		break;

		case 3:
			/*3.Рассортировать строки динамической матрицы с одинаковым количеством элементов в каждой строке по количеству
			простых чисел*/
		{
			int *mass = NULL;
			int *ProstCh = NULL;
			int Str = 0;
			int Col = 0;

			GenMassTwoDimMalloc(mass, &Str, &Col, 0, 20);

			if (mass == NULL)
			{
				printf("Память не выделена");
				exit(EXIT_FAILURE);
			}
			else
			{
				int Ind = 0;
				int Sum = 0;
				printf("\nПростые числа в матрице:\n");
				for (int i = 0; i < Str; i++)
				{
					for (int j = 0; j < Col; j++)
					{
						for (int z = 2; z < *(mass + i*Col + j); z++)
						{
							if (*(mass + i*Col + j) % z == 0) Ind = 1;
						}
						if (Ind == 0 && *(mass + i*Col + j) > 1)
						{
							ProstCh = (int *)realloc(ProstCh, (Sum + 1) * sizeof(int));
							*(ProstCh + Sum) = *(mass + i*Col + j);
							printf("%d\t", *(ProstCh + Sum));
							Sum++;
						}
						Ind = 0;
					}
					printf("\n");
				}
				printf("\n");
			}
		}
		printf("\n");
		break;

		case 4:
			/*4.Дан двумерный массив размером N x M, заполненный целыми числами
			a.	Все его элементы, кратные трем, записать в одномерный массив.
			b.	Все его положительные элементы записать в один одномерный массив, а остальные — в другой
			*/
		{
			int *mass = NULL;
			int *RazlCh = NULL;
			int Str = 0;
			int Col = 0;

			GenMassTwoDimMalloc(mass, &Str, &Col, 0, 20);

			if (mass == NULL)
			{
				printf("Память не выделена");
				exit(EXIT_FAILURE);
			}
			else
			{
				RazlCh = (int *)malloc(sizeof(int));

				*RazlCh = 0;

				int Ind = 0;
				int Sum = 0;
				printf("\nРазличные чисела в матрице:\n");

				for (int i = 0; i < Str; i++)
				{
					for (int j = 0; j < Col; j++)
					{
						for (int z = 0; z <= Sum; z++)
						{
							if (*(RazlCh + z) == *(mass + i*Col + j))
							{
								Ind = 1;
							}
						}
						if (Ind == 0)
						{
							RazlCh = (int *)realloc(RazlCh, (Sum + 1) * sizeof(int));
							*(RazlCh + Sum) = *(mass + i*Col + j);
							Sum++;
						}
						Ind = 0;
					}
				}

				bubbleSortInc(RazlCh, Sum);

				for (int i = 0; i < Sum; i++)
					printf("%d\t", *(RazlCh + i));

				printf("\nКоличество различных чисел в матрице N = %d\n", Sum);
				printf("\n");
			}
		}
		printf("\n");
		break;

		case 5:
			/*5.Ввести целые числа. Создать из них массив. Вычислить сумму чётных элементов массива*/
		{
			int *mass = NULL;
			int *Chis = NULL;
			int *Indic = NULL;
			int *RazlCh = NULL;
			int Str = 0;
			int Col = 0;

			GenMassTwoDimMalloc(mass, &Str, &Col, 1, 4);

			if (mass == NULL)
			{
				printf("Память не выделена");
				exit(EXIT_FAILURE);
			}
			else
			{
				for (int i = 0; i < Str; i++)
				{
					for (int j = 0; j < Col; j++)
					{
						bubbleSortInc(&(*(mass + i*Col)), Col);
					}
				}
				printf("\n");

				printf("\nОтсортированный построчно массив:\n");
				for (int i = 0; i < Str; i++)
				{
					for (int j = 0; j < Col; j++)
						printf("%d\t", *(mass + i*Col + j));
					printf("\n");
				}
				printf("\n");

				RazlCh = (int *)malloc(sizeof(int));

				*RazlCh = 0;

				int Ind = 0;
				int Sum = 0;
				printf("\nРазличные чисела в матрице:\n");

				for (int i = 0; i < Str; i++)
				{
					for (int j = 0; j < Col; j++)
					{
						for (int z = 0; z <= Sum; z++)
						{
							if (*(RazlCh + z) == *(mass + i*Col + j))
							{
								Ind = 1;
							}
						}
						if (Ind == 0)
						{
							RazlCh = (int *)realloc(RazlCh, (Sum + 1) * sizeof(int));
							*(RazlCh + Sum) = *(mass + i*Col + j);
							Sum++;
						}
						Ind = 0;
					}
				}

				bubbleSortInc(RazlCh, Sum);

				for (int i = 0; i < Sum; i++)
					printf("%d\t", *(RazlCh + i));

				printf("\nКоличество различных чисел в матрице N = %d\n", Sum);

				printf("\nЧисла встречающиеся во всех строках\n");

				Indic = (int *)malloc(Str * sizeof(int));

				Ind = 1;
				for (int z = 0; z < Sum; z++)
				{
					for (int i = 0; i < Str; i++)
					{
						*(Indic + i) = 0;
						for (int j = 0; j < Col; j++)
						{
							if (*(RazlCh + z) == *(mass + i*Col + j))
								*(Indic + i) = 1;
						}
						//printf("%d\t", *(Indic + i));
						if (*(Indic + i) == 0) Ind = 0;
					}
					//printf("\n");
					if (Ind == 1) printf("%d\t", *(RazlCh + z));
				}
				printf("\n");
			}
		}
		printf("\n");
		break;

		default: {printf("Задания с таким номером не существует\n"); }
		}
	} while (N > 0 && N < 16);
	printf("\t\t\t\t\tКОНЕЦ.\n");
	system("pause");
}

int IsPrime(int *n)
{
	for (int i = 2; i < *n / 2; i++)
	{
		if (*n%i == 0)
			return 0;
	}
	return 1;
}