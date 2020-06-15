///*Ввести массивы А и В. В массив С перенести элементы массива А с четным значением и элементы мас-сива В с нечетным значением.
//Массив С отсортировать по возрастанию, используя алгоритмы сортиро-вок: «пузырек», сортировка выбором.*/
//
//#include "stdafx.h"
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//
////------ Пузырьковая сортировка(по возрастанию) ------
//
//void BubbleSort(int arr[], int n) // a - массив, n - размер массива
//{
//	int i, j, t;
//	for (i = 1; i < n; i++)
//		for (j = n - 1; j >= i; j--) // Начинаем сортировку от конца к началу
//			if (arr[j - 1] > arr[j])
//			{
//				// Меняем местами два элемента
//				t = arr[j - 1];
//				arr[j - 1] = arr[j];
//				arr[j] = t;
//			}
//}
//
////------ Сортировка выбором(по возрастанию) ------
//void InsertSort(int *arr, int size)
//{
//	int temp,
//		item; // Индекс предыдущего элемента
//	for (int i = 1; i < size; i++)
//	{
//		temp = arr[i];
//		item = i - 1; // Запоминаем индекс предыдущего элемента массива
//		while (item >= 0 && arr[item] > temp) // Пока индекс не равен 0 и предыдущий элемент массива больше текущего
//		{
//			arr[item + 1] = arr[item]; // Перестановка элементов массива
//			arr[item] = temp;
//			item--;
//		}
//	}
//}
//
////----- Генерация случайных чисел -----
//int getRandKey(int reg = 0)
//{
//	if (reg > 0)
//	srand((unsigned)time(NULL));
//	int rmin = 0;
//	int rmax = 100000;
//	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	clock_t t1, t2;
//	const int SIZE = 10000;
//	int A[SIZE], B[SIZE], i, sizeC = 0;
//	int *C = new int[SIZE];
//	int test_arr[SIZE];
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
//
//	for (i = 0; i < SIZE; i++)
//	{
//		if (A[i] % 2 == 0)
//		{
//			sizeC = sizeC + 1;
//			C[sizeC] = A[i];
//		}
//		else if (B[i] % 2 == 1)
//		{
//			sizeC = sizeC + 1;
//			C[sizeC] = B[i];
//		}
//	}
//	cout << "Размер массива C - " << sizeC << endl;
//
//	memcpy(test_arr, C, sizeC * sizeof(int));
//	t1 = clock();
//	InsertSort(test_arr, sizeC);
//	t2 = clock();
//	cout << "\tМассив отсортировался за " << (t2 - t1) << " тактов/такта - Сортировка вставками" << endl;
//
//	memcpy(test_arr, C, sizeC * sizeof(int));
//	t1 = clock();
//	BubbleSort(test_arr, sizeC);
//	t2 = clock();
//	cout << "\tМассив отсортировался за " << (t2 - t1) << " тактов/такта - Пузырьковая сортировка" << endl;
//
//	return 0;}
