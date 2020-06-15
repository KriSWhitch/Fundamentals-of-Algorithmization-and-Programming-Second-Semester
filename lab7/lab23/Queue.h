#pragma once
//--------------- Описание структуры и прототипы функций
#include "stdafx.h"
struct Queue
{
	char info; // какой-то символ
	Queue* next; // указатель на следующий элемент очереди
};
void createQueue(Queue** begin, Queue** end, char p); // Формирование элементов очереди
void viewQueue(Queue* begin); // Вывод элементов очереди 
void insertInQueue(Queue** begin, Queue** end, char p, int max_size); // Ввод нового элемента в конец очереди
int QueueSize(Queue* begin); // Размер очереди

