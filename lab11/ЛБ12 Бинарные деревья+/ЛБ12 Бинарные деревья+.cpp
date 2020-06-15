// ЛБ12 Бинарные деревья+.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"
#include <fstream>
using namespace std;
struct NodeTree
{
	int key;
};

//-------------------------------
btree::CMP cmpfnc(void* x, void* y) // Сравнение ключей
{
	btree::CMP rc = btree::EQUAL; // по умолчанию наш предмет имеет значение "Равен"
	if ( ((NodeTree*)x)->key  <  ((NodeTree*)y)->key ) // Если ключ первого элемента меньше второго
		rc = btree::LESS; // то присваиваем нашему элементу значение "Меньше"
	else
		if (((NodeTree*)x)->key > ((NodeTree*)y)->key)
			rc = btree::GREAT; // Иначе присваиваем значение "больше"
	return rc; // Возвращаем его
}

//-------------------------------
void printNode(void* x) // Вывод ключей при обходе
{
	cout << ((NodeTree*)x)->key << ends; // Выводим ключ элемента
}

//-------------------------------
bool buildTree(char *FileName, btree::Object& tree) //Построение дерева из файла
{
	bool rc = true;
	FILE *inFile;
	fopen_s(&inFile, FileName, "r");
	if (inFile == NULL)
	{
		cout << "Ошибка открытия входного файла" << endl;
		rc = false; return rc;
	}
	while (!feof(inFile)) // Заполнение дерева 
	{
		int num;
		fscanf_s(inFile, "%d", &num, 1);
		NodeTree *a = new NodeTree();
		a->key = num;
		tree.insert(a);
	}
	fclose(inFile);
	return rc;
}

//-------------- Максимальное из двух --------------
int Max(int a, int b) 
{
	if (a > b)
		return a;
	else
		return b;
}
//------------ Минимальное из двух ------------
int Min(int a, int b) 
{
	if (a < b)
		return a;
	else
		return b;
}

FILE * outFile;

void saveToFile(void *x) // Запись одного элемента в файл
{
	NodeTree *a = (NodeTree*)x;
	int q = a->key;
	fprintf(outFile, "%d\n", q);
}

void saveTree(btree::Object &tree, char *FileName) //Сохранение дерева в файл 
{
	fopen_s(&outFile, FileName, "w");
	if (outFile == NULL)
	{
		cout << "Ошибка открытия выходного файла" << endl;
		return;
	}
	tree.Root->scanDown(saveToFile);
	fclose(outFile);
}


//------------- ОСНОВНАЯ ФУНКЦИЯ -------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");

	btree::Object demoTree = btree::create(cmpfnc);

	int k, choice;
	NodeTree a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 }, a5 = { 5 }, a6 = { 6 };
	bool rc = demoTree.insert(&a4);   //           4  
	rc = demoTree.insert(&a1);        //   1             
	rc = demoTree.insert(&a6);        //                   6
	rc = demoTree.insert(&a2);        //      2     
	rc = demoTree.insert(&a3);        //         3
	rc = demoTree.insert(&a5);        //                 5	
	for (;;)
	{
		NodeTree *a = new NodeTree;
		cout << "1 - Вывод дерева на экран" << endl;
		cout << "2 - Добавление элемента" << endl;
		cout << "3 - Удаление элемента" << endl;
		cout << "4 - Сохранить в файл" << endl;
		cout << "5 - Загрузить из файла" << endl;
		cout << "6 - Очистить дерево" << endl;
		cout << "7 - Нисходящий обход дерева" << endl;
		cout << "8 - Восходящий обход дерева" << endl;
		cout << "9 - Смешанный обход дерева" << endl;
		cout << "10 - Проверить дерево на сбалансированность" << endl;
		cout << "11 - Функция из ЛБ11" << endl;
		cout << "0 - Выход" << endl;
		cout << "Сделайте выбор: "; cin >> choice; cout << endl;
		switch (choice)
		{
		case 0:   	exit(0);
		case 1:  	if (demoTree.Root) // Если дерево существует
			demoTree.Root->scanByLevel(printNode); // То выводим его на экран по уровням
					else
						cout << "Дерево пустое" << endl;
			break;
		case 2: 	cout << "Введите ключ: ";  cin >> k;
			a->key = k;
			demoTree.insert(a);
			break;
		case 3:  	cout << "Введите ключ: ";  cin >> k;
			a->key = k;
			demoTree.deleteByData(a);
			break;
			//case 4:   	saveTree(demoTree, "G.txt");
				//break;
			//case 5:  	buildTree("G.txt", demoTree);
				//break;
		case 6:	while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);
			break;

			//---------- Обходы ----------
		case 7: if (demoTree.Root)
			demoTree.Root->scanDown(printNode);
			break;
		case 8: if (demoTree.Root)
			demoTree.Root->scanUp(printNode);
			break;
		case 9: if (demoTree.Root)
			demoTree.Root->scanMix(printNode);
			break;

			//-------- Проверка на сбалансиров. --------
		case 10: 
			if (demoTree.Root)
			{
				if (demoTree.Root->isBalanced(Min, Max))
				{
					cout << "Дерево сбалансированно!" << endl;
				}
				else
				{
					cout << "Дерево НЕсбалансированно!" << endl;
				}
			}
			else
			{
				cout << "Дерево пустое! О балансе не может быть и речи!\n";
			}
			break;

			//------------ Функция из ЛБ 11 ------------
		case 11: 

			//cout << "Всего ветвей в дереве - " << demoTree.Root->amount_vetvi(demoTree.Root) << endl;
			//cout << "Проверка amount_vetvi2 - " << demoTree.amount_vetvi2(demoTree.Root) << endl;

			int k;
			cout << "Введите ключ искомой вершины: "; cin >> k;
			a->key = k;
			cout << "Ветвей до вершины - " << demoTree.show_vetvi(a, demoTree.Root) << endl;
			break;
		}
	}

	return 0;
}
