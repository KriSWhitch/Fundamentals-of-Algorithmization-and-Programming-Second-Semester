#include <iostream>
using namespace std;


//changeX (int i, x) – функция замены i-го элемента списка элементом с заданным значением x.


struct DoubleList //описание узла списка
{
	int data; //информационное поле
	DoubleList* next; //указатель на следующий элемент
	DoubleList* prev; //указатель на предыдущий элемент
};
DoubleList* head; //указатель на первый элемент списка
//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА В КОНЕЦ СПИСКА**********************
void AddXEnd(int x)
{
	DoubleList* node = new DoubleList; //создание нового элемента
	node->data = x; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		node->next = node; //установка указателя next
		node->prev = node; //установка указателя prev
		head = node; //определяется голова списка
	}
	else
	{
		DoubleList* p = head;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	cout << "\nЭлемент добавлен...\n\n";
}

//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА В НАЧАЛО СПИСКА**********************
void AddXBegin(int x)
{
	DoubleList* node = new DoubleList; //создание нового элемента
	node->data = x; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		node->next = node; //установка указателя next
		node->prev = node; //установка указателя prev
		head = node; //определяется голова списка
	}
	else
	{
			DoubleList* p = head;
			p->prev->next = node;
			node->prev = p->prev->prev;
			node->next = p;
			head = node;
			
			
	}
	cout << "\nЭлемент добавлен...\n\n";
}
//**********************ЗАМЕНА ЭЛЕМЕНТА**********************
int changeX(int x,int i) {
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	else
	{
		DoubleList* a = head;
		for (int i = x; i > 1; i--) a = a->next;
		a->data = i;

	}
	cout << "\nЭлемент заменен...\n\n";
}
//***********************УДАЛЕНИЕ ЭЛЕМЕНТА НА ОПРЕДЕЛЕННОЙ ПОЗИЦИИ***********************
int deleteX(int x)
{
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList* a = head;
		for (int i = x; i > 1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	cout << "\nЭлемент удален...\n\n";
}

//*************************Найти минимальный элемент в списке*************************
int findMin() {

	if (head == NULL) cout << "\nСписок пуст\n\n";
	else {
		DoubleList* temp = head;
		int min = temp->data;
		int first = min;
		temp = temp->next;
		do 
		{
			
			if ((temp->data) < min)
			{
				min = temp->data;
				temp = temp->next;
			}
			else temp = temp->next;
		} while ((temp->data) != first);
		return printf("Минимальный элемент %d", min);
	}
}

//*************************ВЫВОД СПИСКА*************************
void PrintList()
{
	if (head == NULL) cout << "\nСписок пуст\n\n";
	else
	{
		DoubleList* a = head;
		cout << "\nЭлементы списка: ";
		do
		{
			cout << a->data << " ";
			a = a->next;
		} while (a != head); cout << "\n\n";
	}
}
//************************ГЛАВНАЯ ФУНКЦИЯ************************
int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	do
	{
		cout << endl << "1. Добавить элемент в конец списка" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести список" << endl;
		cout << "4. Вывод минимального элемента списка" << endl;
		cout << "5. Добавить элемент в начало списка" << endl;
		cout << "6. Замена элемента" << endl;
		cout << "0. Выйти" << endl;
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			AddXEnd(value); break;
		case 2:
			cout << "Позиция > "; cin >> position;
			deleteX(position); break;
		case 3: PrintList(); break;

		case 4: findMin(); break;
		case 5:
			cout << "Значение > "; cin >> value;
			AddXBegin(value); break;
		case 6:
			cout << "Позиция > "; cin >> position;
			cout << endl;
			cout << "Значение > "; cin >> value;
			changeX(position, value); break;
		}
	} while (x != 0);
	return 0;
}