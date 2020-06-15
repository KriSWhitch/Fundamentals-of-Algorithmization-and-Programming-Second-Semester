#pragma once
#include "Lists.h"


namespace hashTC
{
	struct Object
	{
		int size; // Размер
		int(*FunKey)(void*);

		listx::Object *Hash; // Указатель на элемент хеш-таблицы

		Object(int siz, int(*f)(void*)) // Конструктор
		{
			size = siz;
			FunKey = f;
			Hash = new listx::Object[size];
		};

		int hashFunction(void *data); // Наша хеш-функция
		bool insert(void *data); // Вставка элемента
		listx::Element *search(void *data); // Поиск элемента
		bool deleteByData(void *data); // Удаление элемента
		void Scan(); // Отображение хеш-таблицы
	};

	Object create(int size, int(*f)(void*)); // Создаём нашу хеш-таблицу
}
