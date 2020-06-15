#include "MyQueue.h"

void create(Number **begin, Number **end, float p) //Формирование элементов очереди
{
	Number *t = new Number;
	t->next = NULL;
	if (*begin == NULL)
		*begin = *end = t;
	
	t->info = p;
	(*end)->next = t;
	*end = t;
	
}
void view(Number *begin) //Вывод элементов очереди 
{
	Number *t = begin;
	if (t == NULL)
	{
		cout << "Очередь пуста!" << endl;
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
Number *maxElem(Number *begin) //Опрделение максимального элемента
{
	Number *t = begin, *mn=NULL;
	float max;
	if (t == NULL)
	{
		cout << "Очередь пуста!" << endl;
		return mn;
	}
	else
	{
		max = t->info;
		while (t != NULL)
		{
			if (t->info >= max)
			{
				max = t->info;
				mn = t;
			}
			t = t->next;
		}
	}
	return mn;
}
void CyclycShift(Number ** begin,Number ** end, Number * newBeginOfQueue) 
{
	if ((begin == NULL) || (newBeginOfQueue == NULL)) 
	{
		cout << "Ошибка! Не могу выполнить циклический сдвиг." << endl;
		return;
	}

	while ((*begin) != newBeginOfQueue) 
	{
		Number * t = (*begin)->next;
		(*begin)->next = NULL;
		(*end)->next = (*begin);
		(*end) = (*end)->next;
		(*begin) = t;
	}

}
