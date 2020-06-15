#include "stdafx.h"
#include "Lists.h"
#include <iostream>


namespace listx
{
	bool Object::insert(void *data)
	{
		bool rc = NULL;
		if (head == NULL)
		{
			head = new Element(NULL, data, head);
		}
		else
		{
			head = (head->Prev = new Element(NULL, data, head));
		}
		return rc;
	}

	//------ Удаление элемента (с учётом цепочки) ------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL; 
		if (rc = (e != NULL))
		{
			if (e->Next != NULL) // Если существует следующий элемент в списке
				e->Next->Prev = e->Prev; //  Перемещаем след. элемент на место предыдущего
			if (e->Prev != NULL) // Если существует предыдущий элемент
				e->Prev->Next = e->Next; // Меняем его местами со следующим
			else
				head = e->Next; // Если таких элементов нет, сдвигаем голову
			delete e; // и удаляем элемент
		}
		std::cout << "Элемент удален" << std::endl;
		return rc;
	}

	//-------------------------------
	bool Object::deleteByData(void* data)
	{
		return deleteByElement(search(data));
	}

	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), 
		*rc = this->getFirst();
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
