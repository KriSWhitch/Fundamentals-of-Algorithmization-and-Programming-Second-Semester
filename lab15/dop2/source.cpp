// Использовать в проекте функции универсального хеширования  и модульного. Сравнить время поиска информации. 

#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include "Hash.h"
#include <iostream>
#include <ctime>
using namespace std;

void menu() {
	cout << "1 - Вывод хеш-таблиц" << endl;
	cout << "2 - Добавление элемента" << endl;
	cout << "3 - Удаление элемента" << endl;
	cout << "4 - Поиск элемента" << endl;
	cout << "0 - Выход" << endl;
	cout << "\nСделайте выбор: ";
}

//-------- Хеш-таблица --------
struct AAA
{
	int key; // Ключ
	char* mas; // Хранимое в ключе значение
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};


//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}

//---------- Вывод ключа и значения хеш-таблицы ----------
void AAA_print(void* d)
{
	cout << " Ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

//---------- Основная функция ----------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	clock_t t1, t2; // Используется для подсчёта времени поиска
	//AAA a1(1, (char*)"one"), a2(2, (char*)"two"), a3(4, (char*)"three"), a4(2, (char*)"four");
	AAA a1(8881234, (char*)"one"), a2(8882345, (char*)"two"), a3(8886543, (char*)"three"), a4(8884567, (char*)"four"),
		a5(8885678, (char*)"five"), a6(8888765, (char*)"six"), a7(8889876, (char*)"seven"), a8(8888901, (char*)"eight"),
		a9(8884321, (char*)"nine"), a10(8885432, (char*)"ten"), a11(8886543, (char*)"eleven"), a12(8887654, (char*)"twelve"),
		a13(8888765, (char*)"thirteen"), a14(8889876, (char*)"fourteen"), a15(8880987, (char*)"fifteen"), a16(8886543, (char*)"sixteen");
	int siz = 16, choice, k;
	// Создаём таблицу значений ключ-значение
	Object H = create(siz, key);

	H.insert(&a1); H.insert(&a2); H.insert(&a3); H.insert(&a4);
	H.insert(&a5); H.insert(&a6); H.insert(&a7); H.insert(&a8);
	H.insert(&a9); H.insert(&a10); H.insert(&a11); H.insert(&a12);
	H.insert(&a13); H.insert(&a14); H.insert(&a15); H.insert(&a16);

	siz = 32;
	// Это вторая таблица
	Object H1 = create(siz, key);

	H1.insert(&a1); H1.insert(&a2); H1.insert(&a3); H1.insert(&a4);
	H1.insert(&a5); H1.insert(&a6); H1.insert(&a7); H1.insert(&a8);
	H1.insert(&a9); H1.insert(&a10); H1.insert(&a11); H1.insert(&a12);
	H1.insert(&a13); H1.insert(&a14); H1.insert(&a15); H1.insert(&a16);

	// Измеряем время поиска в 1-ой таблице
	H.search(8887654);
	t1 = clock();
	cout << "Прошло " << ((float)(t1) / CLOCKS_PER_SEC) << " секунд, чтобы найти элемент с ключом 8887654 в H" << endl;

	// Измеряем время поиска во второй таблице
	H1.search(8887654);
	t2 = clock();
	cout << "Прошло " << ((float)(t2) / CLOCKS_PER_SEC) << " секунд, чтобы найти элемент с ключом 8887654 в H1" << endl;
	for (;;)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:
			cout << "\nПервая хеш таблица\n" << endl;
			H.scan(AAA_print);
			cout << "\nВторая хеш-таблица\n" << endl;
			H1.scan(AAA_print); break;
		case 2:
		{
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "Введите ключ" << endl;	cin >> k;
			a->key = k;
			cout << "Введите строку" << endl; cin >> str;
			a->mas = str;
			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else
				H.insert(a);
		} break;
		case 3:
		{
			cout << "Введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4:
		{
			cout << "Введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден!" << endl;
			else
				AAA_print(H.search(k));
		}  break;
		default: cout << "Введено неверное значение! Выберите ещё раз, только внимательно!" << endl;
		}
	}
	return 0;
}


