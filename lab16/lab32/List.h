#pragma once
namespace listx
{
	struct Element
	{
		Element* Prev;
		Element* Next;
		void* Data;
		Element(Element* prev, void* data, Element* next)
		{
			Prev = prev;
			Data = data;
			Next = next;
		}
		Element* getNext()
		{
			return Next;
		};
		Element* getPrev()
		{
			return Prev;
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
		Element* getFirst()
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
