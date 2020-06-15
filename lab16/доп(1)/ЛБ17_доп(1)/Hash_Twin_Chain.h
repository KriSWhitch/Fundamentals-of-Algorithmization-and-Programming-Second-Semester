#pragma once
#include "Lists.h"
namespace hashTC
{
	// Хеш-таблица
	struct Object
	{
		// Размер таблицы
		int size;
		int(*FunKey)(void*);
		// Хеш
		listx::Object* Hash;
		// Конструктор
		Object(int size, int(*f)(void*))
		{
			this->size = size;
			FunKey = f;
			Hash = new listx::Object[size];
		};

		// Хеш-функция
		int hashFunction(void* data);
		// Добавление (возвращает значение "вставлено"-"не вставлено")
		bool insert(void* data);
		// Изменение значения
		void setValue(void* data, void* newData);
		// Поиск
		listx::Element* search(void* data);
		// Удаление по данным
		bool deleteByData(void* data);
		// Вывод таблицы на экран
		void Scan();
	};
	// Создание таблицы
	Object create(int size, int(*f)(void*));
}