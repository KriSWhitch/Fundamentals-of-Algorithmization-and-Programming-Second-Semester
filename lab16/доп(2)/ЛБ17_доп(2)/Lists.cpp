#include "Lists.h"
#include <iostream>

// Структура "строка из файла"
struct StrFile
{
	// Первая буква строки
	char character;
	// Строка
	std::string str;
};

namespace listx
{
	// Добавление значения (возвращает значение "найдено"-"не найдено")
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		// Если голова пуста
		if (head == NIL)
			// Создаем голову
			head = new Element(NULL, data, NULL);
		else
			// Иначе добавляем
			head = (head->prev = new Element(NULL, data, head));
		return head;
	}

	// Поиск значения
	Element* Object::search(void* data)
	{
		// Начинаем с головы
		Element* rc = head;
		// Пока не нашли значение или список не закончился
		while ((rc != NIL) && (((((StrFile*)rc->data)->character) != ((StrFile*)data)->character)
			|| ((((StrFile*)rc->data)->str) != ((StrFile*)data)->str)))
			rc = rc->next;
		return rc;
	}

	// Поиск значения
	Element* Object::search(void* data, int& cmp)
	{
		cmp = 0;
		// Начинаем с головы
		Element* rc = head;
		// Пока не нашли значение или список не закончился
		while ((rc != NIL) && ((((StrFile*)rc->data)->character) != ((StrFile*)data)->character))
		{
			rc = rc->next;
			cmp++;
		}
		return rc;
	}

	// Удаление по элементу
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		// Если не пусто
		if (rc = (e != NIL))
		{
			// Проверка возможных случаев
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			// Освобождение памяти
			delete e;
		}
		// Вывод сообщения
		std::cout << "Элемент удален!" << std::endl;
		return rc;
	}

	// Удаление по данным
	bool Object::deleteByData(void* data)
	{
		int cmp;
		// Ищем элемент и удаляем по нему
		return deleteByElement(search(data, cmp));
	}

	// Получение конца
	Element* Object::getLast()
	{
		// Получаем начало
		listx::Element* e = this->getFirst(),
			* rc = this->getFirst();
		// Движемся, пока возможно, к концу
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}

	// Создание объекта
	Object create()
	{
		// Вызов конструктора
		return *(new Object());
	};

	// Вывод на экран
	void Object::scan()
	{

		// Получаем "голову"
		listx::Element* e = this->getFirst();

		if (e == NULL)
			std::cout << "NULL-NULL";
		// Пока есть возможность
		while (e != NULL)
		{
			// Вывод значений
			std::cout << ((StrFile*)e->data)->character << '-' << ((StrFile*)e->data)->str << " / ";
			e = e->getNext();
		};
	}
}

