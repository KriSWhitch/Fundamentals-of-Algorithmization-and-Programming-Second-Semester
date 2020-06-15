#include "Header.h"
#include <iostream>

using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		//key = 0; конструктор по умолчанию здесь не обязателен
		//mas = "";  тем более допущена ошибка

	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)   //вывод
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Ведите размер хэш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод электронного адреса" << endl;
		cout << "2 - добавить сведения" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
		case 2:
		{
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "Год выпуска(ключ): " << endl;
			cin >> k;
			a->key = k;
			cout << "Название продукта: " << endl;
			cin >> str;
			a->mas = str;
			H.insert(a);
		}
		break;
		case 1:
			H.Scan();
			break;
		case 3:
		{
			AAA* b = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
		break;
		case 4:
			AAA * c = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else {
				cout << "Первый элемент с данным клю-чом" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
