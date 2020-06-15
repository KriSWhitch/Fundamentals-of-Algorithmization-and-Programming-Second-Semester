//Создать очередь с вещественными числами, и заполнить ее с клавиатуры.Выполнить циклический сдвиг элементов в очереди
//так, чтобы в ее начале был расположен наибольший элемент.
#include <iostream> 
#include "MyQueue.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Number *begin = NULL, *end=NULL, *t=NULL;
	
	int size;
	float p;
	
	cout << "Введите размер очереди:" << endl;
	cin >> size;
	
	for (int i = 0; i < size; i++) //создание очереди
	{
		cout << "Введите элемент:" << endl;
		
		cin >> p;
		
		create(&begin, &end, p);
	}

	cout << "Элементы очереди:" << endl;
	
	
	view(begin);

	t = maxElem(begin);    //определение максимального
	cout << "Максмальный элемент: " << t->info << endl;

	CyclycShift(&begin, &end, t);

	cout << "Новая сдвинутая очередь:" << endl;
	view(begin);

	cout << "DONE!" << endl;
	system("pause");
	return 0;
}