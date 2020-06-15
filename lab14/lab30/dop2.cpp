//#include <cstdlib>
//#include <iostream>
//#include <time.h>
//using namespace std;
//
//
//int main()
//{
//	int arr_size, max, min;
//	srand(time(NULL));
//	cout << "Enter the size of Array: " << endl;
//	cin >> arr_size;
//
//	int* mass = new int[arr_size];
//
//	cout << "Elements: |";
//	for (int r = 0; r < arr_size; r++)
//	{
//		mass[r] = rand() % 1000;
//		cout << mass[r] << "|";
//	}
//	cout << endl;
//
//	max = mass[0];
//	min = mass[0];
//	for (int r = 1; r < arr_size; r++)
//	{
//		if (max < mass[r]) max = mass[r];
//		if (min > mass[r]) min = mass[r];
//	}
//	cout << "Min: " << min << endl;
//	cout << "Max: " << max << endl;
//
//	return 0;
//}