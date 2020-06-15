///*Ввести массив А, в массив В перенести все элементы массива А, имеющие четный индекс, справа от которых расположены элементы с нечетным значением.
//Массив В отсортировать по убыванию, используя алгоритмы сортировок: сортировка выбором, сортировка Хоара.*/
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int SIZE = 8;
//
//void selectionSort(int arr[], int n) {  //сортировка выбором
//	int i, j, min_idx;
//	for (i = 0; i < n - 1; i++) {
//		min_idx = i;  //индекс минимального 
//		for (j = i + 1; j < n; j++) { //цикл поиска минимального
//			if (arr[j] < arr[min_idx]) //в неотсортированной части
//				min_idx = j; //запоминаем минимальный
//		}
//		swap(arr[min_idx], arr[i]);  //меняем местами 
//	}
//}
//
//
//void quickSort(int* array, int low, int high) { //сортировка Хоара 
//	int i = low; // Установка указателей (меток) на границы диапазона 
//	int j = high;
//	int pivot = array[(i + j) / 2]; // Установка опорного элемента 
//
//	while (i <= j) {
//		while (array[i] < pivot) // Поиск в левой части первого элемента, который больше либо равен опорному 
//			i++;
//		while (array[j] > pivot) // Поиск в правой части первого элемента, который меньше либо равен опорному 
//			j--;
//		if (i <= j) { // Если найденные элементы находятся по разные стороны от опорного 
//			swap(array[i], array[j]); //меняем местами  
//			i++;
//			j--;
//		}
//	}
//	if (j > low) // Применение алгоритма к левой и правой части 
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