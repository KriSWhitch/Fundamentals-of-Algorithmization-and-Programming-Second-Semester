
//----------------- Описание функций по их прототипам --------------------------
#include "stdafx.h"
#include "Queue.h"
#include <iostream>
using namespace std;


//------------------ Формирование элементов очереди (Ввод) ----------------------

void createQueue(Queue** begin, Queue** end, char p)
{
	Queue* t = new Queue; // Выделили память
	t->next = NULL; // Задали значение по умолчанию

	if (*begin == NULL)
		*begin = *end = t;
	else
	{
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}

//---------------------- Ввод нового элемента (в конец очереди) -----------------------
void insertInQueue(Queue** begin, Queue** end, char e, int max_size)
{
	// Выделили память
	Queue* t = new Queue;
	Queue* el_new = new Queue;

	// Значения по умолчанию
	el_new->next = NULL;
	el_new->info = e;

	int current_size = QueueSize(*begin); // Текущий размер очереди

	if ((current_size < max_size) && ((*begin) != NULL)) // Если размер очереди не превышает максимальный
	{
		// то заполняем очередь без удаления первого элемента
		el_new->info = e;
		(*end)->next = el_new;
		*end = el_new;
	}
	else if (e == (*end)->info) // Условие задачи моего варианта
	{
		cout << "Ваш введённый элемент совпал с последним в очереди!\nПервые три элемента будут удалены!\n";
		*end = el_new;
		for (int i = 0; i < 3; i++)
		{
			Queue* del_elem = new Queue;
			del_elem = *begin;
			(*begin) = (*begin)->next;
			delete del_elem;
		}
	}

	else if (*begin == NULL) // если очередь пуста
	{
		// переуказвыаем начало и конец очереди на новый элемент
		*begin = *end = el_new;
	}

	else // Если же размер очереди равен максимальному
	{	// То заполняем очередь как обычно
		el_new->info = e;
		(*end)->next = el_new;
		*end = el_new;
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
}


//-------------------- Вывод элементов очереди ------------------------- 
void viewQueue(Queue* begin)
{
	Queue* t = begin;
	if (t == NULL)
	{
		cout << "Очередь пуста!\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << " <-- " << endl;;
			t = t->next;
		}
}


//--------------------------- Размер очереди ----------------------
int QueueSize(Queue* begin)
{
	int Qsize = 0;
	Queue* t = begin;
	if (t == NULL)
	{
		cout << "Очередь пуста!";
	}
	else
	{
		for (t; t != NULL; t = t->next)
		{
			Qsize++;
		}
	}
	return Qsize;
}