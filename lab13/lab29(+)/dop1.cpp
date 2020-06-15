//
///*Ввести массивы А и В. В массив С перенести те элементы массива А, которые больше максимального элемента массива В.
//Массив С отсортировать по убыванию, используя алгоритмы сортировок: «пузырек», в сортировка простой вставкой.*/
//
//
//#include "stdafx.h"
//#include <iostream>
//#include <ctime>
//using namespace std;
//
////------ Пузырьковая сортировка(по убыванию) ------
//
//void BubbleSort(int arr[], int n) // a - массив, n - размер массива
//{
//	int i, j, t;
//	for (i = 1; i < n; i++)
//		for (j = n - 1; j >= i; j--) // начинаем сортировку от конца к началу
//			if (arr[j] > arr[j - 1]) 
//			{
//				// Меняем местами два элемента
//				t = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = t;
//			}
//}
//
////------ Сортировка выбором(по убыванию) ------
//void InsertSort(int *arr, int size) 
//{
//	int temp, 
//		item; // Индекс предыдущего элемента
//	for (int i = 1; i < size; i++)
//	{
//		temp = arr[i]; 
//		item = i - 1; // Запоминаем индекс предыдущего элемента массива
//		while (item >= 0 && arr[item] < temp) // Пока индекс не равен 0 и предыдущий элемент массива меньше текущего
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
//		srand((unsigned)time(NULL));
//	int rmin = 0;
//	int rmax = 100000;
//	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	clock_t t1, t2;
//	const int SIZE = 9999;
//	int A[SIZE], i, sizeB = 0;
//	int test_arr[SIZE];
//	int *B = new int[SIZE];
//
//	for (i = 0; i < SIZE; i++)
//	{
//		A[i] = getRandKey();
//	}
//
//	for (i = 0; i < SIZE; i++)
//	{
//		if (i % 2 == 0)
//		{
//			sizeB = sizeB + 1;
//			B[sizeB] = A[i];
//		}
//	}
//	cout << "Размер B - " << sizeB << endl;
//
//	memcpy(test_arr, B, sizeB * sizeof(int));
//	t1 = clock();
//	InsertSort(test_arr, sizeB);
//	t2 = clock();
//	cout << "\tМассив отсортировался за " << (t2 - t1) << " тактов/такта - Сортировка вставками" << endl;
//
//	memcpy(test_arr, B, sizeB * sizeof(int));
//	t1 = clock();
//	BubbleSort(test_arr, sizeB);
//	t2 = clock();
//	cout << "\tМассив отсортировался за " << (t2 - t1) << " тактов/такта - Пузырьковая сортировка" << endl;
// return 0;
//}