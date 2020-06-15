//------------- Описание функций -------------
#include "stdafx.h"
#include "Tree.h"
#include "Math.h"
#include <iostream>
namespace btree // Бинарное дерево, не допускается дублирование ключей
// В дальнейшем придётся прописывать это пространство имён
// Будет как с std::cout , только btree:: ...
{
	Object create(CMP(*f)(void*, void*))
	{
		return *(new Object(f));
	}

	Node* Node::min() // Поиск минимального элемента
	{
		Node* rc = this; // Получаем указатель из функции, т.е получаем введённый аргумент (это будет корень)
		if (rc->left != NULL) // Если существуют элементы в левом поддереве
			rc = rc->left->min(); // то переносим указатель влево до упора, так как там и будет находиться самый малый элемент дерева
		return rc;
	}

	Node* Node::max() // Поиск максимального элемента
		// Максимальынй элемент будет самый правй лист дерева
	{
		Node *rc = this;
		if (rc->right != NULL)
			rc = rc->right->max();
		return rc;
	}

	Node* Node::next() // Определение следующего элемента дерева
	{
		Node* rc = this, *x = this; // Пока что оба указателя указывают на одну область памяти
		if (rc->right != NULL) // Елси существует правое поддерево
			rc = rc->right->min(); // Идём до конца этого дерева
		else
		{
			rc = this->parent; // Иначе переносим указатель на родителя
			while (rc != NULL && x == rc->right) // Пока указатель на родителя существует и рабочий указатель равен указателю на правое поддерево
			{
				x = rc;
				rc = rc->parent;
			}
		}  return rc;
	}



	//------------------- Новые функции -------------------



	//--------------- Подсчёт количества ветвей от корня до вершины с заданным ключом ---------------
	int Object::show_vetvi(void* d, Node* n)
	{
		int vetvi = 0; // Число ветвей
		Node* rc = n;
		if (rc != NULL)
		{
			std::cout << "Ветвь\n";
			if (isLess(d, n->data)) // Если наш искомый ключ меньше, чем ключ корня
			{
				rc = search(d, n->left); // Ищем элемент в левой части дерева
				view_vetvi(n->left);
				vetvi = vetvi + amount_vetvi2(n->left);
			}
			else
				// Если искомый ключ больше, чем ключ корня
				if (isGreat(d, n->data))
				{
					rc = search(d, n->right); // Ищем его в правой части дерева
					view_vetvi(n->right);
					vetvi = vetvi + amount_vetvi2(n->right);
				}
		}
		else
		{
			std::cout << "Такого элемента нет!" << std::endl;
		}
		return vetvi;
	}

	//-------------- Количество ветвей(для себя, в дальшейшем использоваться не будет) -------------- 
	int Node::amount_vetvi(Node *p)
	{
		if (p == NULL)
			return 0;
		else
			return 1 + amount_vetvi(p->left) + amount_vetvi(p->right);
	}

	//---------- Количество ветвей 2(это будет использоваться) ----------
	int Object::amount_vetvi2(Node *p)
	{
		if (p == NULL)
			return 0;
		else
			return 1 + amount_vetvi2(p->left) + amount_vetvi2(p->right);
	}

	//-------- Функция для вывода вершин -------- 
	void Object::view_vetvi(Node *n)
	{
		Node *rc = n;
		if (rc != NULL)
		{
			view_vetvi(rc->right);
			int *key = (int*)rc->data; // Указатели нужны, так как data имеет тип void*, и при выводе мы будем получать адрес ключа, а не его значение
			std::cout << *key << " -> " << std::endl;
			view_vetvi(rc->left);
		}
	}

	//----------- Нисходящий обход -----------
	void Node::scanDown(void(*f)(void* n)) 
	//Суть обхода:
	//1) Выводим корень (Главный элемент дерева)
	//2) Выводим левое поддерево от корня (меньшие элементы дерева)
	//3) Выводим правое поддерево от корня (большие элементы дерева)
	// Итого: Выводим от меньшего элемента дерева к большему (от листьев к корню)
	{
		f(this->data); // Заносим в функцию f хранящийся ключ (Это будет корень)
		std::cout << std::endl; // Выводим корень
		if (this->left != NULL) // Если существует указатель на левое поддерево
			this->left->scanDown(f); // рекурсивно вызываем функцию
		if (this->right != NULL) // Если существует указатель на правае поддерево
			this->right->scanDown(f); // тоже выводим
		// В итоге мы будем выводить дерево от корня к листьям
	}

	//-------------- Восходящий обход --------------
	void Node::scanUp(void(*f)(void* n)) 
	// Суть обхода:
	//1) Выводим левое поддерево, начиная с его конца (с самого малого элемента)
	//2) Выводим правое поддерево, начиная с его конца (с самого малого элемента)
	//3) Выводим корень
	// Итого: Выводим от самого малого звена дерева до самого корня (от листа к корню)
	{
		// Мы вначале доходим до самого малого листа
		if (this->left != NULL)
		this->left->scanUp(f);
		if (this->right != NULL)
		this->right->scanUp(f);
		f(this->data); // Получаем его ключ
		std::cout << std::endl; // И по итогу выводим дерево от листьев к корню
	}

	//------------ Смешанный обход ------------
	void Node::scanMix(void(*f)(void* n)) 
	{
		// Вначале доходим до конца левого поддерева
		if (this->left != NULL)
		this->left->scanMix(f);
		f(this->data); 
		std::cout << std::endl; // Потом его выводим
		// А уже рекурсивно выведем правое поддерево
		if (this->right != NULL)
		this->right->scanMix(f);
		// По итогу получится, что вначале полностью выведется левое поддерево, потом правое, а потом корень
	}

	//------------ Проверка глубины ------------
	int Node::testDepth(int(*f)(int a, int b)) 
	{
		if (!this) 
		{
			return 0;
		}
		else
		{
			return (1 + f(this->left->testDepth(f), this->right->testDepth(f)));
		}
	}

	//----------- Проверка сбалансированности -----------

	// Дерево сбалансированно тогда, когда разница между поддеревьями узла не превышает 1-цу и при этом их значения различаются друг от друга
	bool Node::isBalanced(int(*f1)(int a1, int b1), int(*f2)(int a2, int b2)) 
	{
		if (abs((this->testDepth(f1) - this->testDepth(f2))) <= 1)
			return abs((this->testDepth(f1) - this->testDepth(f2)));
	}

	//-------- Поиск элемента --------
	Node* Object::search(void* d, Node* n)
	{
		Node* rc = n;
		if (rc != NULL)
		{
			if (isLess(d, n->data))
				rc = search(d, n->left);
			else
				if (isGreat(d, n->data))
					rc = search(d, n->right);
		} return rc;
	}

	//-------- Вставка элемента -------- 
	bool Object::insert(void* d)
	{
		Node* x = this->Root, *n = NULL;
		bool rc = true;
		while (rc == true && x != NULL)
		{
			n = x;
			if (isLess(d, x->data))
				x = x->left;          //выбор куда идти - влево или вправо
			else
				if (isGreat(d, x->data))
					x = x->right;
				else
					rc = false;
		}
		if (rc == true && n == NULL)
			this->Root = new  Node(NULL, NULL, NULL, d);
		else
			if (rc == true && isLess(d, n->data))
				n->left = new  Node(n, NULL, NULL, d);
			else
				if (rc == true && isGreat(d, n->data))
					n->right = new  Node(n, NULL, NULL, d);
		return rc;
	};

	//------------- Удаление элемента -------------
	bool  Object::deleteByNode(Node* n)
	{
		bool rc = true;
		if (rc = (n != NULL))
		{
			if (n->left == NULL && n->right == NULL)  //если потомков нет
			{
				if (n->parent == NULL)
					this->Root = NULL;   //обнуление корня
				else
					if (n->parent->left == n)
						n->parent->left = NULL;
					else
						n->parent->right = NULL;
				delete n;
			}
			else
				if (n->left == NULL && n->right != NULL) //только правый потомок
				{
					if (n->parent == NULL)
						this->Root = n->right;
					else
						if (n->parent->left == n)
							n->parent->left = n->right;
						else
							n->parent->right = n->right;
					n->right->parent = n->parent;
					delete n;
				}
				else
					if (n->left != NULL && n->right == NULL) //только левый потомок
					{
						if (n->parent == NULL)
							this->Root = n->left;
						else
							if (n->parent->right == n)
								n->parent->left = n->left;
							else
								n->parent->right = n->left;
						n->left->parent = n->parent;
						delete n;
					}
					else                                  //если есть оба потомка
						if (n->left != NULL && n->right != NULL) {
							Node* x = n->next();
							n->data = x->data;
							rc = deleteByNode(x);
						}
		} return  rc;
	}

	//-------------------------------
	void Node::scanLevel(void(*f)(void* n), int i)  //Вывести вершины уровня
	{
		if (this->left != NULL)
			this->left->scanLevel(f, i);
		if (this->getLevel() == i)
			f(this->data);
		if (this->right != NULL)
			this->right->scanLevel(f, i);
	}

	//-------------------------------
	int Node::getLevel()
	{
		Node *rc = this;
		int q = 0;
		while (rc->parent != NULL)
		{
			rc = rc->parent;
			q++;
		}
		return q;
	}

	//-------------------------------
	void Node::scanByLevel(void(*f)(void* n)) // Вывод дерева на экран по уровням
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << '\t';
			this->scanLevel(f, i);
			std::cout << '\n';
		}
	}
}
