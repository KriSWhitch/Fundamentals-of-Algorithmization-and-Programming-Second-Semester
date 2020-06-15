#include "Hash_Twin_Chain.h"
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
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	}

	// Вывод таблицы на экран
	void Object::Scan()
	{
		// Цикл по всем элементам таблицы
		for (int i = 0; i < size; i++)
		{
			// Вывод цепочки
			Hash[i].scan();
			// Переход на новую строку
			std::cout << '\n';
		}
	}

	// Изменение значения
	void Object::setValue(void* data, void* newData)
	{
		Hash[hashFunction(data)].setValue(data, newData);
	}
}

