///*������ ������ �, � ������ � ��������� ��� �������� ������� �, ������� ������ ������, ������ �� ������� ����������� �������� � �������� ���������.
//������ � ������������� �� ��������, ��������� ��������� ����������: ���������� �������, ���������� �����.*/
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int SIZE = 8;
//
//void selectionSort(int arr[], int n) {  //���������� �������
//	int i, j, min_idx;
//	for (i = 0; i < n - 1; i++) {
//		min_idx = i;  //������ ������������ 
//		for (j = i + 1; j < n; j++) { //���� ������ ������������
//			if (arr[j] < arr[min_idx]) //� ����������������� �����
//				min_idx = j; //���������� �����������
//		}
//		swap(arr[min_idx], arr[i]);  //������ ������� 
//	}
//}
//
//
//void quickSort(int* array, int low, int high) { //���������� ����� 
//	int i = low; // ��������� ���������� (�����) �� ������� ��������� 
//	int j = high;
//	int pivot = array[(i + j) / 2]; // ��������� �������� �������� 
//
//	while (i <= j) {
//		while (array[i] < pivot) // ����� � ����� ����� ������� ��������, ������� ������ ���� ����� �������� 
//			i++;
//		while (array[j] > pivot) // ����� � ������ ����� ������� ��������, ������� ������ ���� ����� �������� 
//			j--;
//		if (i <= j) { // ���� ��������� �������� ��������� �� ������ ������� �� �������� 
//			swap(array[i], array[j]); //������ �������  
//			i++;
//			j--;
//		}
//	}
//	if (j > low) // ���������� ��������� � ����� � ������ ����� 
//		quickSort(array, low, j);
//	if (i < high)
//		quickSort(array, i, high);
//}
//
//void task2() {
//	int a[SIZE], b[SIZE], bSize = 0;
//	cout << "Enter " << SIZE << " elements: ";
//	for (int i = 0; i < SIZE; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i < SIZE; i++) {
//		if (!(i % 2) && (a[i] % 2)) b[bSize++] = a[i];
//	}
//	//sort(b, b + bSize);
//	selectionSort(b, bSize);
//	reverse(b, b + bSize);
//	for (int i = 0; i < bSize; i++) {
//		cout << b[i] << ' ';
//	} cout << endl;
//}
//
//int main() {
//	task2();
//	system("pause");
//	return 0;
//}