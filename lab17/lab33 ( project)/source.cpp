
//Главная функция OAP_List организует ввод и редактирование информации, демонстрирует способы обращения к функциям для работы со списком, описанным в файле List.cpp.
//В программе создается список с именем L1.Опробуются операции вставки элементов, удаления, поиска.

#include "List.h"
#include <iostream>
using namespace std;

struct Person
{
	char name[20];
	int age;
	Person* next;
};

void print(void* b)       //Функция используется при выводе 
{
	Person* a = (Person*)b;
	cout << a->name << "  " << a->age << endl;
}
int x = 0;
Person inserted_element[30];

void insert()
{

	cout << "Введите имя:\n";
	cin >> inserted_element[x].name;
	cout << "Введите возраст:\n";
	cin >> inserted_element[x].age;
	x++;
}


void menu() {
	std::cout << "1. Добавить элемент" << endl;
	std::cout << "2. Вывести список на экран" << endl;
	std::cout << "3. Очистить список" << endl;
	std::cout << "4. Вывести количество элементов списка" << endl;
	std::cout << "0. Выйти из программы" << endl;
}


int main()
{
	int choose;
	setlocale(LC_ALL, "Russian");
	Person a1 = { "Петров", 20 };
	Person a2 = { "Сидоров", 25 };
	Person a3 = { "Гончаров", 47 };

	bool rc;
	Object L1 = Create();   // создание списка с именем L1
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	L1.PrintList(print);
	Element* e = L1.Search(&a3);
	Person* aa = (Person*)e->Data;
	cout << "Найден элемент= " << aa->name << endl;
	rc = L1.Delete(&a2);
	if (rc == true) cout << "Удален элемент" << endl;
	cout << "Список:" << endl;
	L1.CountList(print);
	L1.PrintList(print);
	L1.DeleteList();
	cout << "Список:" << endl;
	L1.PrintList(print);
	L1.CountList(print);


	while (true)
	{
		
		menu();
		std::cout << "Сделайте выбор: ";
		std::cin >> choose;
		Person tmp;
		switch (choose)
		{
		case 1:
		{
			insert();
			L1.Insert(&inserted_element[x]);
		}
			break;


		case 2:
			L1.PrintList(print);
			break;

		case 3:
			L1.DeleteList();
			break;

		case 4:
			L1.CountList(print);
			break;

		case 0:
			return 0;

		default:
			break;
		}

	}
}
