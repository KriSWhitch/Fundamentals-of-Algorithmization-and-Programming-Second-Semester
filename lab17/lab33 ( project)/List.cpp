#include "List.h"
#include <iostream>

bool Object::Insert(void* data)           // ������� � ������
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(void* data)    // ����� �������� �������
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*))     // �����
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*), Element* e)
{
	f(e->Data);
}

//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // ������� �� ������
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(void* data)      // ������� �� ��������
{
	return Delete(Search(data));
};


bool Object::DeleteList()
{
	bool r = false;
	Element* t = GetLast();
	if (t)
	{
		if (t->Prev != NULL)
			t->Prev->Next = t->Next;
		else
			Head = t->Next;
		delete t;
		DeleteList();
	}
	return r = true;
}

int Object::CountList(void(*f)(void*))
{
	int n = 0;
	Element* e = Head;
	while (e != NULL)
	{
		n++;
		e = e->GetNext();
	};

	std::cout << "���������� ��������� � ������: " << n << std::endl;
	return n;
}


//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object());
}
