#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Number
{
	float info;
	Number *next;
};

void create(Number **begin, Number **end, float p); //формирование элементов очереди

void view(Number *begin); //функция вывода элементов очереди 

Number * maxElem(Number *begin); //функция определения минимального элемента 
 
void CyclycShift(Number ** begin, Number ** end, Number * newBeginOfQueue);