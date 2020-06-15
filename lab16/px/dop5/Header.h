#pragma once
#include "List.h"
namespace hashTC    //хэш-таблица
{
	struct Object
	{
		int size;                //размер таблицы
		int(*FunKey)(void*);    //вычисление ключа
		listx::Object* Hash;    //указатель на элемент хеш-таблицы
		Object(int size, int(*f)(void*))   //конструктор
		{
			this->size = size;
			FunKey = f; 
			Hash = new listx::Object[size];
		};
		int hashFunction(void* data);  //хэш-функция
		bool insert(void* data);   //вставить
		listx::Element* search(void* data);   //найти
		bool deleteByData(void* data);   //удаление
		void Scan();   //обход таблицы
	};
	Object create(int size, int(*f)(void*));   //создание хеш-таблицы
}
