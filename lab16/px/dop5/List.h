#pragma once             
#include<iostream>
#define LISTNIL (Element*)-1
namespace listx    //пространство имен
{
	struct Element
	{
		Element* prev;   
		Element* next;
		void* data;
		Element(Element* prev, void* data, Element* next)
		{
			this->prev = prev;
			this->data = data;
			this->next = next;

		}
		Element* getNext()
		{
			return next;
		};
		Element* getPrev()
		{
			return prev;
		};
	};
	static Element* NIL = NULL;
	struct Object
	{
		Element* head;
		Object()
		{
			head = NIL;
		};
		Element* getFirst()    //получение первого
		{
			return head;
		};
		Element* getLast();
		Element* search(void* data);
		bool insert(void* data);
		bool deleteByElement(Element* e);
		bool deleteByData(void* data);
		void scan();
	};
	Object create();
}
#undef LISTNIL 
#pragma once

