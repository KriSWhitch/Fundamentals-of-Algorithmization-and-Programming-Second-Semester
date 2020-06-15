///*Ввести массивы А и В. В массив С перенести те элементы массива А, которые больше минимального элемента массива В.
//Массив С отсортировать по убыванию, используя алгоритмы сортировок: шейкерная сортировка,  сортировка Шелла. */
//
//#include "stdafx.h"
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//
////------- Шейкерная сортировка(по убыванию) -------
//void ShakerSort(int arr[], int n)
//{
//	// first - Первый элемент массива
//	// last - Последний элемент массива
//	int buf, first = 0, mode = 1, // Используется для смены направления
//		last = n - 1;
//	for (; first < last; mode > 0 ? ++first : --last)
//	{
//		for (int i = mode > 0 ? first : last;
//			mode > 0 ? (i < last) : (i > first); mode > 0 ? ++i : --i)
//		{
//			if ((arr[i + 1] > arr[i]) && (mode > 0))
//			{
//				buf = arr[i + 1];
//				arr[i + 1] = arr[i];
//				arr[i] = buf;
//			}
//			if ((arr[i - 1] < arr[i]) && (mode < 0))
//			{
//				buf = arr[i - 1];
//				arr[i - 1] = arr[i];
//				arr[i] = buf;
//			}
//		}
//		mode = -mode;
//	}
//}
//
////----- Сортировка Шелла(по убыванию)
//void ShellSort(int A[], int n)
//{
//	int buf;
//	bool sort;
//	for (int g = n / 2; g > 0; g /= 2)
//		do
//		{
//			sort = false;
//			for (int i = 0, j = g; j < n; i++, j++)
//				if (A[i] > A[j])
//				{
//					sort = true;
//					buf = A[i];
//					A[i] = A[j];
//					A[j] = buf;
//				}
//		} while (sort);
//}
//
////------- Поиск минимального элемента массива -------
//int min(int arr[], int size)
//{
//	int min = arr[0], i;
//	for (i = 0; i < size; i++)
//	{
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//	return min;
//}
//
//
////----- Генерация случайных чисел -----
//int getRandKey(int reg = 0)
//{
//	if (reg > 0)
//		srand((unsigned)time(NULL));
//	int rmin = 0;
//	int rmax = 10000;
//	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
//}
//
//////--------- Основная функция ---------
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	const int SIZE = 10000; // Размеры массивов
//	int  test_arr[SIZE]; // Будет использоваться для проверки выполнения сортировок
//	clock_t t1, t2;
//	int A[SIZE];
//	int B[SIZE];
//	int sizeC = 0, i;
//	int* C = new int[SIZE];
//
//	for (i = 0; i < SIZE; i++)
//	{
//		A[i] = getRandKey();
//	}
//
//	for (i = 0; i < SIZE; i++)
//	{
//		B[i] = getRandKey();
//	}
//	int minB = min(B, SIZE);
//
//	cout << "\tМинимальный элемент массива B = " << minB << endl;
//	cout << "\tНажмите что-нибудь для продолжения" << endl;
//	getchar();
//
//	for (i = 0; i < SIZE; i++)
//	{
//		if (A[i] > minB)
//		{
//			sizeC++;
//			C[sizeC] = A[i];
//		}
//	}
//
//	cout << "\tРазмер массива C - " << sizeC << endl;
//	cout << "\tНажмите что-нибудь для продолжения" << endl;
//	getchar();
//
//	// Проверяем время выполнения
//
//	memcpy(test_arr, C, sizeC * sizeof(int));
//	t1 = clock();
//	ShakerSort(test_arr, sizeC);
//	t2 = clock();
//	cout << "\tМассив отсортировался за " << (t2 - t1) << " тактов/такта - Шейкерная сортировка" << endl;
//	cout << "\tНажмите что-нибудь для продолжения" << endl;
//	getchar();
//
//	memcpy(test_arr, C, sizeC * sizeof(int));
//	t1 = clock();
//	ShellSort(test_arr, sizeC);
//	t2 = clock();
//	cout << "\tМассив отсортировался за " << (t2 - t1) << " тактов/такта - сортировка Шелла" << endl;
//
//	return 0;
//}