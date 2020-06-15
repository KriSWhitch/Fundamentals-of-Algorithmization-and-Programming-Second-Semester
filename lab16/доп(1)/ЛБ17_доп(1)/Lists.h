#pragma once
#include <cstdlib>

#define LISTNIL (Element*)-1
namespace listx
{
	// Элемент списка
	struct Element
	{
		// Предыдущий элемент
		Element* prev;
		// Следующий элемент
		Element* next;
		// Данные элемента
		void* data;

		// Конструктор элемента
		Element(Element* prev, void* data, Element* next)
		{
			this->prev = prev;
			this->data = data;
			this->next = next;
		}

		// Получение следующего
		Element* getNext()
		{
			return next;
		}

		// Получение предыдущего
		Element* getPrev()
		{
			return prev;
		}
	};
	static Element* NIL = NULL;

	// Список
	struct Object
	{
		// "Голова" списка
		Element* head;

		// Конструктор без параметров
		Object()
		{
			// Голова получает нулевое значение
			head = NIL;
		}

		// Получение головы
		Element* getFirst()
		{
			return head;
		}

		// Получение конца
		Element* getLast();
		// Поиск значения
		Element* search(void* data);
		// Изменение значения
		void setValue(void* data, void* newData);
		// Добавление значения (возвращает значение "найдено"-"не найдено")
		bool insert(void* data);
		// Удаление по элементу
		bool deleteByElement(Element* e);
		// Удаление по данным
		bool deleteByData(void* data);
		// Вывод на экран
		void scan();
	};
	// Создание объекта
	Object create();
}
#undef LISTNIL

