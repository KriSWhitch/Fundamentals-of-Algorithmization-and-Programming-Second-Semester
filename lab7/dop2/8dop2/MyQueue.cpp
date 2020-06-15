#include "MyQueue.h"

void create(Number **begin, Number **end, float p) //������������ ��������� �������
{
	Number *t = new Number;
	t->next = NULL;
	if (*begin == NULL)
		*begin = *end = t;
	
	t->info = p;
	(*end)->next = t;
	*end = t;
	
}
void view(Number *begin) //����� ��������� ������� 
{
	Number *t = begin;
	if (t == NULL)
	{
		cout << "������� �����!" << endl;
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
Number *maxElem(Number *begin) //���������� ������������� ��������
{
	Number *t = begin, *mn=NULL;
	float max;
	if (t == NULL)
	{
		cout << "������� �����!" << endl;
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
		cout << "������! �� ���� ��������� ����������� �����." << endl;
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
