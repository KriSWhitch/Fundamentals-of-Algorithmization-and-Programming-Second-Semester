
#include <fstream>
#include <ctime>
#include <array>
#include <algorithm>

using namespace std;

ofstream cout("output.txt");

const int SIZE = 20001;

void bubbleSort(int arr[], int n) {    //сортировка пузырьком
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {   //процесс всплытия
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);   //меняем местами элементы arr[j] и arr[j + 1]
				swapped = true;
			}
		}
		if (swapped == false) break;
	}
}

void countingSort(int arr[], int sz) {   //сортировка подсчетом
	int i, j, k;
	int idx = 0;
	int min, max;  // минимальный и максимальный элементы из входного массива

	min = max = arr[0];
	for (i = 1; i < sz; i++) {     //находим макс и мин элементы
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	k = max - min + 1;

	int* B = new int[k];
	for (i = 0; i < k; i++) B[i] = 0;   //Заполняем вспомогательный массив нулями

	for (i = 0; i < sz; i++) B[arr[i] - min]++;   //Заполняем вспомогательный массив частотами(повторениями)
	for (i = min; i <= max; i++)
		for (j = 0; j < B[i - min]; j++) arr[idx++] = i;  //помещаем элементы в их соответсвующие индексы

	delete[] B;
}


void quickSort(int* array, int low, int high) {   //сортировка Хоара
	int i = low; // Установка указателей (меток) на границы диапазона
	int j = high;
	int pivot = array[(i + j) / 2]; // Установка опорного элемента

	while (i <= j) {
		while (array[i] < pivot) // Поиск в левой части первого элемента, который больше либо равен опорному
			i++;
		while (array[j] > pivot) // Поиск в правой части первого элемента, который меньше либо равен опорному
			j--;
		if (i <= j) { // Если найденные элементы находятся по разные стороны от опорного
			swap(array[i], array[j]);  //меняем местами
			i++;
			j--;
		}
	}
	if (j > low) // Применение алгоритма к левой и правой части
		quickSort(array, low, j);
	if (i < high)
		quickSort(array, i, high);
}

void fillArrays(int a[], int b[], int c[]) {
	srand(time(0));   //формирование рандомных чисел
	for (int i = 0; i < SIZE; i++) {
		a[i] = b[i] = c[i] = rand();
	}
}


// 1 - bubble 2 - quick 3 - counting
void testSort(int arr[], const int sortType, const int size) {
	time_t start = clock();
	switch (sortType) {
	case 1:
		bubbleSort(arr, size);
		break;
	case 2:
		sort(arr, arr + size);
		break;
	case 3:
		countingSort(arr, size);
		break;
	default:
		break;
	}
	time_t end = clock();
	cout << "Time: " << end - start << " ticks" << endl;
}

int main() {
	for (int mult = 10; mult <= 20; mult++) {
		const int TMPSIZE = 1000 * mult;
		int a[SIZE], b[SIZE], c[SIZE];
		fillArrays(a, b, c);
		cout << "Size: " << TMPSIZE << endl;
		cout << "---Selection sort---" << endl;
		testSort(a, 1, TMPSIZE);
		cout << "---Quick sort---" << endl;
		testSort(b, 2, TMPSIZE);
		cout << "---Heap sort---" << endl;
		testSort(c, 3, TMPSIZE);
		cout << "\n-----------\n" << endl;
	}
	return 0;
}