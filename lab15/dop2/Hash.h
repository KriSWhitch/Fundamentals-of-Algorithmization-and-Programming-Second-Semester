#pragma once
#define HASHDEL (void*) -1

struct Object
{
	void** data; // Хранимое в ключе значение(текст)
	Object(int, int(*)(void*));
	int size; // МАКСИМАЛЬНЫЙ размер хеш-таблицы 
	int N; // Текущий размер хеш-таблицы
	int(*getKey)(void*);
	bool insert(void*);
	int searchInd(int key);
	void* search(int key);
	void* deleteByKey(int key);
	bool deleteByValue(void*);
	void scan(void(*f)(void*)); // Вывод хеш-таблицы
};

static void* DEL = (void*)HASHDEL; // Маркер "Ячейка удалена"

// Конструктор для создания таблицы значений ключ-значение
Object create(int size, int(*getkey)(void*));

#undef HASHDEL
