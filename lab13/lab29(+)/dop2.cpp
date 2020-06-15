///*������ ������� � � �. � ������ � ��������� �������� ������� � � ������ ��������� � �������� ���-���� � � �������� ���������.
//������ � ������������� �� �����������, ��������� ��������� �������-���: ��������, ���������� �������.*/
//
//#include "stdafx.h"
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//
////------ ����������� ����������(�� �����������) ------
//
//void BubbleSort(int arr[], int n) // a - ������, n - ������ �������
//{
//	int i, j, t;
//	for (i = 1; i < n; i++)
//		for (j = n - 1; j >= i; j--) // �������� ���������� �� ����� � ������
//			if (arr[j - 1] > arr[j])
//			{
//				// ������ ������� ��� ��������
//				t = arr[j - 1];
//				arr[j - 1] = arr[j];
//				arr[j] = t;
//			}
//}
//
////------ ���������� �������(�� �����������) ------
//void InsertSort(int *arr, int size)
//{
//	int temp,
//		item; // ������ ����������� ��������
//	for (int i = 1; i < size; i++)
//	{
//		temp = arr[i];
//		item = i - 1; // ���������� ������ ����������� �������� �������
//		while (item >= 0 && arr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
//		{
//			arr[item + 1] = arr[item]; // ������������ ��������� �������
//			arr[item] = temp;
//			item--;
//		}
//	}
//}
//
////----- ��������� ��������� ����� -----
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
//	cout << "������ ������� C - " << sizeC << endl;
//
//	memcpy(test_arr, C, sizeC * sizeof(int));
//	t1 = clock();
//	InsertSort(test_arr, sizeC);
//	t2 = clock();
//	cout << "\t������ �������������� �� " << (t2 - t1) << " ������/����� - ���������� ���������" << endl;
//
//	memcpy(test_arr, C, sizeC * sizeof(int));
//	t1 = clock();
//	BubbleSort(test_arr, sizeC);
//	t2 = clock();
//	cout << "\t������ �������������� �� " << (t2 - t1) << " ������/����� - ����������� ����������" << endl;
//
//	return 0;}
