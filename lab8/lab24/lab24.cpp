

//Задан прямоугольник со сторо-нами а и b (a, b − натуральные числа).
//Разбить его на части с по-мощью квадратов и определить, сколько квадратов получится, ес-ли каждый раз выбирается самый большой квадрат.

//#include <iostream>
//#include <math.h>
//using namespace std;
//float numsq(int a, int b);
//int main()
//{
//	int a, b;
//	setlocale(LC_ALL, "Russian");
//	cout << "Введите стороны прямоугольника, и функция посчитает, \nСколько квадратов получится, если каждый раз выбирается самый большой квадрат" << endl;
//	cout << "Введите длину: "; cin >> a;
//	cout << "Введите ширину: "; cin >> b;
//	cout << "Таких квадратов будет " << numsq(a, b) << endl;
//	return 0;
//}
//float numsq(int a, int b)
//{
//	if (b == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return (floor(a / b) + numsq(b, (a % b)));
//	}
//}





//Разработать программу, реализующую рекурсивный алгоритм вычисления A(m, n) для любых целых не отрицательных m и n.

//#include <iostream>
//#include <math.h>
//using namespace std;
//int A(int m, int n);
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int a, b;
//	cout << "Данный алгоритм реализует странные вычисления с целыми числами a и b\n";
//	cout << "Введите a: "; cin >> a;
//	if (a < 0)
//	{
//		cout << "Вы ввели отрицательное число! Так нельзя! Нам нужны только не отрицательные\nВводите заново!: ";
//		cin >> a;
//	}
//	cout << "Введите b: "; cin >> b;
//	if (b < 0)
//	{
//		cout << "Вы ввели отрицательное число! Так нельзя! Нам нужны только не отрицательные\nВводите заново!: ";
//		cin >> b;
//	}
//	cout << "Результат работы: " << A(a, b) << endl;
//}
//int A(int m, int n)
//{
//	if (m == 0)
//		return n + 1;
//	else if (m > 0 && n != 0)
//		return A(m, 0) + A(m - 1, 1);
//	else if (m > 0 && n > 0)
//		return A(m, n) + A(m - 1, A(m, n - 1));
//}





//Вычислить выражение в правой части, используя рекурсию. y = sinx + sin2x + ... + sin(nx)

//#include <iostream>
//#include <math.h>
//using namespace std;
//float sinuses(float x, int n);
//int main()
//{
//	int n;
//	float x;
//	setlocale(LC_ALL, "Russian");
//	cout << "Данная функция реализует такой алгоритм:\ny = sinx + sin2x + ... + sin(nx)" << endl;
//	cout << "Введите x: "; cin >> x;
//	cout << "Введите n: "; cin >> n;
//	cout << "Результат работы: " << sinuses(x, n) << endl;
//	return 0;
//}
//float sinuses(float x, int n)
//{
//	if (n == 0)
//		return sin(x * n);
//	else
//	return sin(x * n) + sinuses(x, n - 1);
//}





//Разработать программу, реализующую рекурсивный алгоритм вычисления значений F(m, n) для любых целых не отрицательных аргументов m и n.

#include <iostream>
#include <math.h>
using namespace std;
int F(int m, int n);
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "Введите целое неотрицательное a: "; cin >> a;
	cout << "Введите целое неотрицательное b: "; cin >> b;
	cout << "Результат работы функции: " << F(a, b) << endl;
	return 0;
}
int F(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return n + 1;
	}
	else
	{
		return F(m - 1, F(m, n - 1));
	}
}





//Вычислить выражение в правой части, используя рекурсию. y = cosx + cos2x + ... + cos(nx)

//#include <iostream>
//#include <math.h>
//using namespace std;
//float cosinuses(float x, int n);
//int main()
//{
//	int n;
//	float x;
//	setlocale(LC_ALL, "Russian");
//	cout << "Данная функция реализует такой алгоритм:\ny = cosx + cos2x + ... + cos(nx)" << endl;
//	cout << "Введите x: "; cin >> x;
//	cout << "Введите n: "; cin >> n;
//	cout << "Результат работы: " << cosinuses(x, n) << endl;
//	return 0;
//}
//float cosinuses(float x, int n)
//{
//	if (n == 0)
//		return cos(x * n);
//	else
//	return cos(x * n) + cosinuses(x, n - 1);
//}