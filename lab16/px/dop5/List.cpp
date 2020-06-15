#include "List.h"
#include <iostream>
struct AAA     //элемент таблицы
{
	int key;
	char *mas;
};
namespace listx
{ 
	bool Object::insert(void* data)    //вставка
	{
		bool rc = NULL;
		if (head == NULL)
			head = new Element(NULL, data, head);
		else
			head = (head->prev = new Element(NULL, data, head));
		return rc;
	}
	//-------------------------------
	Element* Object::search(void* data)    //поиск
	{
		Element* rc = head;
		while ((rc != NULL) && ((((AAA*)rc->data)->key) != ((AAA*)data)->key))
			rc = rc->next;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByElement(Element* e)    //удаление
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
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
	Element* Object::getLast()        //получить последний
	{
		listx::Element* e = this->getFirst(), //получение первого
			*rc = this->getFirst();
		while (e != NULL)   //пока не null
		{
			rc = e;
			e = e->getNext(); 
		};
		return rc;
	}
	Object create()    //создать
	{
		return *(new Object());
	};
	//-------------------------------
	void Object::scan()    //вывод на экран
	{
		listx::Element* e = this->getFirst();  // получение первого
		while (e != NULL)
		{
			std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
			e = e->getNext();
		};
	}
}