#include "Lists.h"
#include <iostream>

// Структура "вхождение буквы"
struct Letter
{
	// Буква
	char character;
	// Количество вхождений
	int number;
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
		while ((rc != NIL) && ((((Letter*)rc->data)->character) != ((Letter*)data)->character))
			rc = rc->next;
		int k = -1;
		if (rc != NULL)
			k = ((Letter*)rc->data)->number;
		return rc;
	}

	// Изменение значения
	void Object::setValue(void* data, void* newData)
	{
		// Начинаем с головы
		Element* rc = head;
		// Пока не нашли значение или список не закончился
		while ((rc != NIL) && ((((Letter*)rc->data)->character) != ((Letter*)data)->character))
			rc = rc->next;
		((Letter*)rc->data)->number = ((Letter*)newData)->number;
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
		// Ищем элемент и удаляем по нему
		return deleteByElement(search(data));
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
			std::cout << ((Letter*)e->data)->character << '-' << ((Letter*)e->data)->number << " / ";
			e = e->getNext();
		};
	}
}

