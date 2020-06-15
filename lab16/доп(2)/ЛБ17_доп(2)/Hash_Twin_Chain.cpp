#include "Hash_Twin_Chain.h"
#include "Lists.h"
#include <iostream>
#include <string>

namespace hashTC
{
	// Создание таблицы
	Object create(int size, int(*f)(void*))
	{
		// Вызов конструктора
		return *(new Object(size, f));
	}

	// Хеш-функция
	int Object::hashFunction(void* data)
	{
		// Вычисляем модуль
		return (FunKey(data) % size);
	}

	// Добавление (возвращает значение "вставлено"-"не вставлено")
	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	}

	// Удаление по данным
	bool Object::deleteByData(void* data)
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	}

	// Поиск
	listx::Element* Object::search(void* data, int& index)
	{
		index = hashFunction(data);
		return Hash[index].search(data);
	}

	// Поиск
	listx::Element* Object::search(void* data, int& index, int& cmp)
	{
		return Hash[hashFunction(data)].search(data, cmp);
	}

	// Вывод таблицы на экран
	void Object::Scan()
	{
		// Цикл по всем элементам таблицы
		for (int i = 0; i < size; i++)
		{
			std::cout << "[Ячейка " << i << "]     ";
			// Вывод цепочки
			Hash[i].scan();
			// Переход на новую строку
			std::cout << '\n';
		}
	}

}

