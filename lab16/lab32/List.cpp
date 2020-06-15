#include "stdafx.h"
#include "List.h"
#include <iostream>

namespace listx
{
	bool Object::insert(void* Data)
	{
		bool rc = NULL;
		if (head == NULL)
			head = new Element(NULL, Data, head);
		else
			head = (head->Prev = new Element(NULL, Data, head));
		return rc;
	}
	//-------------------------------

	//-------------------------------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->Next != NULL)
				e->Next->Prev = e->Prev;
			if (e->Prev != NULL)
				e->Prev->Next = e->Next;
			else
				head = e->Next;
			delete e;
		}
		std::cout << "Ёлемент удален" << std::endl;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByData(void* Data)
	{
		return deleteByElement(search(Data));
	}
	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(),
			* rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}
	Object create()
	{
		return *(new Object());
	};
	//-------------------------------
}
