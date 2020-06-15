//Библиотека. Создать хеш-таблицу со следующими полями: номер книги, название книги. Ключ – номер книги. Номер книги – случайное число.

#pragma once

namespace listx
{
	struct Element
	{
		Element *Prev; // Указатель на следующий элемент
		Element *Next; // Указатель на предыдущий элемент
		void *Data; // Хранимая информация

		//----- Конструктор -----

		Element(Element *prev, void *data, Element *next)
		{
			Prev = prev;
			Data = data;
			Next = next;
		}

		Element *getNext() // Получаем указатель не след. элемент
		{
			return Next;
		};

		Element *getPrev() // Получаем указатель на предыдущ. элемент
		{
			return Prev;
		};
	};

	static Element *NIL = NULL;
	
	struct Object
	{
		Element *head; // Указатель на первый элемент списка

		//----- Конструктор -----

		Object()
		{
			head = NIL;
		};

		Element *getFirst() // Получаем указатель на первый элемент
		{
			return head;
		};

		Element *getLast();
		Element *search(void* data);
		bool insert(void* data);
		bool deleteByElement(Element* e);
		bool deleteByData(void* data);
		void scan();
	};

	Object create();
}
