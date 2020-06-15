// Вершина бинарного дерева содержит ключ, строку и два указателя на потомков. 
//Написать функцию, которая подсчитывает число ветвей от корня до ближайшей вершины с заданным ключом и выводит их

#include "stdafx.h"
#include <iostream>
#include "Tree.h"
using namespace std;
Tree *Root = NULL; 	// Указатель корня по умолчанию
int main()
{
	setlocale(LC_ALL, "Russian");
	int key, choice, n;
	Tree *rc; char s[5], letter;
	for (;;)
	{
		cout << "\t\t1 - Создание дерева\n";
		cout << "\t\t2 - Добавление элемента\n";
		cout << "\t\t3 - Поиск по ключу\n";
		cout << "\t\t4 - Удаление элемента\n";
		cout << "\t\t5 - Вывод дерева\n";
		cout << "\t\t6 - Подсчет количества букв\n";
		cout << "\t\t7 - Очистка дерева\n";
		cout << "\t\t8 - Доп задание 1\n";
		cout << "\t\t9 - Написать функцию вывода количества листьев данного дерева.\n"; //Число листьев в данном дереве
		cout << "\t\t10 - Доп задание 2\n"; //Количество с узлов с чётными ключами
		cout << "\t\t11 - Доп задание 3\n"; //Количество узлов правой ветви
		cout << "\t\t0 - Выход\n";
		cout << "Ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите слово: "; cin >> s;
			insertElem(Root, key, s); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			cout << "Найденное слово: ";
			puts(rc->text); break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево!" << endl;
			view(Root, 0);
		}
				 else cout << "Дерево пустое!\n"; break;
		case 6:  cout << "\nВведите букву: "; cin >> letter;
			n = count(Root, letter);
			cout << "Количество слов, начинающихся с буквы " << letter;
			cout << " равно " << n << endl; break;
		case 7:  delAll(Root); break;
		case 8: cout << "Введите ключ искомого звена: "; cin >> key;
			cout << "Число ветвей до такого звена - " << ClosestVetvi(Root, key) << endl;
			cout << "Всего ветвей: " << Vetvi(Root) << endl;
			break;
		case 9: cout << "Число листьев в данном дереве - " << LeafCount(Root) << endl; break;
		case 10: cout << "Количество с узлов с чётными ключами - " << ChetnieYzli(Root) << endl; break;
		case 11: cout << "Количество узлов правой ветви - " << amount_right_side(Root)-1 << endl; break;
		case 0:  exit(0);
		}
	}
}


