#pragma once
//-------------- Дерево ------------
struct Tree          
{
	int key;  //Ключ
	char text[5]; //Текст - не более 4 букв
	Tree *Left, *Right; // Указатели на левое и правое звено
};

Tree* makeTree(Tree *Root);       //Создание дерева
Tree* list(int i, char *s);       //Создание нового элемента
Tree* insertElem(Tree *Root, int key, char *s);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree *Root, int key); //Удаление элемента по ключу
void view(Tree *t, int level);    //Вывод дерева 
int count(Tree *t, char letter);  //Подсчет количества слов
void delAll(Tree *t);             //Очистка дерева
int ClosestVetvi(Tree *t, int find_key); // Вывод числа ветвей и самых ветвей от корня до ближайшей вершины
int Vetvi(Tree *t); // Число ветвей
// Доп задание 1
int LeafCount(Tree *t); // Количество листьев на дереве
// Доп задание 2
int ChetnieYzli(Tree *t); // Определение узлов с чётными ключами
// Доп задание 3
int amount_right_side(Tree *t); // Количество узлов правой части

