//Вершина бинарного дерева содержит ключ, строку и два указателя на потомков. Написать функ-цию, которая подсчитывает число ветвей от корня до ближайшей вершины с заданным ключом, и вы-водит их. 

//------------------------------- Функции -------------------------------
#include "stdafx.h"
#include "Tree.h"
#include <iostream>
using namespace std;
int c = 0;  // Количество слов
//----------------- Создание дерева ----------------- 
Tree* makeTree(Tree *Root)  
{
	int key; char s[5];
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// Если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите слово корня: "; cin >> s;
		Root = list(key, s); // Установка указателя на корень
	}
	while (1) // Добавление элементов, пока не введём отриц. число
	{
		cout << "\nВведите ключ: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Введите слово: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}
//-------------------- Создание нового элемента -------------------- 
Tree* list(int i, char *s)     
{
	Tree *t = new Tree[sizeof(Tree)]; // Делаем указатель на пустое звено
	t->key = i; // В поле key вносим введённый ключ
	for (i = 0; i < 5; i++) // Цикл использутся для ввода текста не посимвольно, а целиком
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL; // Указатели у нового элемента указывают в пустоту
	return t;
}
//---------------------- Добавление нового элемента ----------------------
Tree* insertElem(Tree *t, int key, char *s)  
{
	Tree *Prev = new Tree[sizeof(Tree)]; // Prev - элемент перед текущим
	int find = 0;  // Признак поиска
	while (t && !find)
	{
		Prev = t; 
		if (key == t->key)
			find = 1; // Ключи должны быть уникальны!
		else
			if (key < t->key) t = t->Left; // Если ключ меньше, чем текущий, то переносимся на левое звено, т.к оно больше
			else t = t->Right; // Иначе переносимся на правое звено
	}
	if (!find) // Найдено место с адресом Prev и при этом ключи не совпали
	{
		t = list(key, s);   // Создается новый узел 
		if (key < Prev->key)  // и присоединяется, а дальше 
			Prev->Left = t;    // либо переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}
//---------------- Удаление элемента по ключу ----------------
Tree* delet(Tree *Root, int key)  
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree *Del, *Prev_Del, *R, *Prev_R;
	Del = Root; // За текущий элемент возьмём корень
	Prev_Del = NULL; // А удаляемого тогда, пока что, нет
	while (Del != NULL && Del->key != key)// Поиск элемента и его родителя 
	{
		Prev_Del = Del; // Предыдущий переносим к главному
		if (Del->key > key) // Если ключ главного больше
			Del = Del->Left; // то идём влево
		else
			Del = Del->Right; // иначе вправо
	}
	if (Del == NULL)  // Элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	// Поиск элемента R для замены
	if (Del->Right == NULL) // Если в удаляемом нет указателя на правое звено
		R = Del->Left; // То элемент для замены переносим на левое звено
	else
		// Если наоборот, то на правое
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; // Поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // Найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	// Удаление корня и замена его на R
	else
		// Поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // На левую ветвь 
		else
			Prev_Del->Right = R;	// На правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}
//--------------------- Поиск элемента по ключу --------------------- 
Tree* search(Tree* n, int key)  
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key >(key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}
//----------------------- Подсчет количества букв -----------------------
int count(Tree *t, char letter) 
{
	if (t) // Если наш указатель не NULL
	{
		count(t->Right, letter); // Считаем в правых ветвях и поддеревьях
		if (*(t->text) == letter) // если введённая буква совпадает с найденной
			c++; // то увеличиваем счётчик
		count(t->Left, letter); // Считаем в левых ветвях и поддеревьях
	}
	return c; 
}
//----------------------- Вывод дерева (всего)----------------------- 
void view(Tree *t, int level) 
{
	if (t)
	{
		view(t->Right, level + 1);	// Вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	// Вывод левого поддерева
	}
}
//--------------- Очистка дерева ---------------
void delAll(Tree *t) 
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

//--------- Основное задание ---------
//Написать функцию вывода количества листьев данного дерева. 
int LeafCount(Tree *t) // Считаем количество листьев
{
	if (t == NULL) // Если указываем в пустоту
		return 0; // возвращаем ноль
	else
	{
		if ((t->Left == 0) && (t->Right == 0)) // Если нет указателей на левое и правое звено
			return 1; // Возвращаем 1
		else // Если что-то есть
			return LeafCount(t->Left) + LeafCount(t->Right); // Возвращаем количество найденных листьев
	}
}

//------------------- Доп задание 2 -------------------
// Написать функцию определения количества узлов с четными ключами.
int ChetnieYzli(Tree *t)
{
	int amount = 0;
	if (t == NULL)
		return 0;
	else
	{
		if (t->key % 2 == 0)
		{
			amount++;
		}
		return amount + ChetnieYzli(t->Left) + ChetnieYzli(t->Right);
	}
}
//---------------- Доп задание 3 ----------------
//Написать функцию определения количества узлов правой ветви дерева.
int amount_right_side(Tree *t)
{
	//Tree *t = Root;
	int amount = 0;
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if ((t->Right != NULL))
		{
			amount++;
		}
		return amount + amount_right_side(t->Right);
	}
}

//---------------------- Доп задание 1 ----------------------
//---------------------- Вывод числа ветвей и самих ветвей от корня до ближайшей вершины по заданному ключу ----------------------
int ClosestVetvi(Tree* Root, int find_key)
{
	int vetvi = 0; // Число ветвей
	int level = 0; // Число уровней (необходимо для вывода)
	Tree* closest = Root; // Указатель на наш корень
	if (closest != NULL) // если указываем не на пустоту
	{
		cout << "\tВетвь\n";
		if (find_key < (find_key, Root->key))
		{
			closest = search(Root->Left, find_key);
			view(Root->Left, level + 1); // Вывод левого поддерева
			vetvi = vetvi + Vetvi(Root->Left);
			for (int i = 0; i < level; i++)
			{
				cout << "   ";
			}
		}
		else
		{
			if (find_key > (find_key, Root->key))
			{
				closest = search(Root->Right, find_key);
				view(Root->Right, level + 1);	// Вывод правого поддерева
				vetvi = vetvi + Vetvi(Root->Right);
			}
		}
	}
	else
		cout << "Нет такого элемента\n";
	return vetvi;
}

// Количество ветвей
int Vetvi(Tree* t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + Vetvi(t->Left) + Vetvi(t->Right);
}

