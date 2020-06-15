
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>  
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include "transpose.h"
using namespace std;



void transpose(double** mas, int* rows, int* cols);



/*Дан файл вещественных чисел, содержащий элементы квадратной матрицы по строкам,
причем начальный элемент файла содержит значение количества столбцов матрицы.
Создать новый файл той же структуры, содержащий k-ый столбец исходной матрицы.*/

//done
int first()
{
	double** mas;
	char buff;
	int n = 0, m;
	int res;
	int i, j;
	int k;
	FILE* in;
	if ((in = fopen("in.txt", "r")) == NULL)
		return -1;

	while ((buff = fgetc(in)) != EOF)
		if (buff == '\n')
			n++;
	fseek(in, 0, SEEK_SET);
	fscanf_s(in, "%d", &m);
	res = (m > n) ? m : n;
	mas = (double**)malloc(res * sizeof(double*));
	for (i = 0; i < res; i++)
		mas[i] = (double*)malloc(res * sizeof(double));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			fscanf_s(in, "%lf", &mas[i][j]);

	transpose(mas, &n, &m);

	FILE* out;
	if ((out = fopen("out.txt", "w")) == NULL)
		return -1;

	printf("Введите номер столбца для переноса во второй файл: ");
	scanf("%d", &k);

	for (i = k-1; i < k; i++)
	{
		for (j = 0; j < m; j++)
			fprintf(out, "%lf ", mas[i][j]);

		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);

	for (i = 0; i < res; i++)
		free(mas[i]);
	free(mas);
}


/*Создать текстовый файл F1 не менее, чем из 8 строк, и записать в него информацию.
Скопировать из файла F1 в файл F2 строки, начиная с k до k + 3.*/

//done
void second()
{
	srand(time(NULL));
	int mas[8], i;
	/* заполняем массив случайными числами с помощь функции rand()*/
	for (i = 0; i < 8; i++) {
		mas[i] = rand() % 1000 - 500;
	}
	/*создаем объект F1, который создаст файл file.txt
	циклом for заполнеяем файл из массива mas[8]] */
	ofstream F1("file.txt", ios_base::trunc);
	for (int i = 0; i < 8; i++) {
		F1 << mas[i] << endl;
	}
	/* создаем объект,чтобы считать из файла file.txt данные*/
	ifstream F1_1("file.txt");
	int k[8];
	for (i = 0; !F1_1.eof(); i++) {
		F1_1 >> k[i];
	}
	/* создаем объект F2 ,в который записываем 3 чисела из массива k*/
	ofstream F2("file2.txt", ios_base::trunc);
	for (int i = 0; i < 3; i++) {
		F2 << k[i] << endl;
	}
	std::cout << "Done!";
}


/*Компоненты файла file1 –  целые двухзначные (отличные от нуля) числа, причем сначала записа-ны  10 положительных чисел, затем 10 отрицательных, и т. д.
Получить файл file2, в котором запи-саны числа из файла file1, сначала 5 положительных чисел, затем 5 отрицательных и т. д.*/

//done
int dop1(){
	ifstream ifs("file_dop1.txt", std::ios::in);
	ofstream ofs("file2_dop1.txt", std::ios::out);

	int a;
	for (int i = 0; i < 5; ++i) {
		ifs >> a;
		ofs << a << endl;
	}

	for (int i = 0; i < 10; ++i) {
		ifs >> a;
		if (a < 0)
			ofs << a << endl;
	}
	return 0;
}



/*Компоненты файла f – целые двухзначные числа (положительные и отрицательные).
Получить файл g, образованный из f включением только чисел кратных K.*/

//done
void dop2() {
	srand(time(NULL));
	int K = 3;
	int x[8], i;
	/* заполняем массив случайными числами с помощь функции rand()*/
	for (i = 0; i < 8; i++) {
		x[i] = rand() % 99 - 99;
	}
	/*создаем объект F1, который создаст файл file_dop2.txt
	циклом for заполнеяем файл из массива x[8]] */
	ofstream F1("file_dop2.txt", ios_base::trunc);
	for (int i = 0; i < 8; i++) {
		F1 << x[i] << endl;
	}
	/* создаем объект,чтобы считать из файла file_dop2.txt данные*/
	ifstream F1_1("file_dop2.txt");
	int k[8];
	for (i = 0; !F1_1.eof(); i++) {
		F1_1 >> k[i];
	}
	/* создаем объект F2 ,в который записываем числа кратные K*/
	ofstream F2("file2_dop2.txt", ios_base::trunc);
	for (int i = 0; i < 8; i++) {
		if (k[i] % K == 0) {
			F2 << k[i] << endl;
		}
		else continue;
	}
}


//done

/*Создать текстовый файл F1 не менее, чем из 6 строк,и записать в него информацию. 
Скопировать в файл F2 только четные строки из F1.*/
void dop3() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	FILE* F1;
	FILE* F2;
	int k, i = 0;
	char str[255];
	errno_t err;
	err = fopen_s(&F1, "f1_dop3.txt", "w");
	for (int i = 0; i < 8; i++)
	{
		fflush(stdin);
		printf("введите строку %d : \n", i + 1);
		gets_s(str);
		fputs(str, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	fclose(F1);
	err = fopen_s(&F1, "f1_dop3.txt", "r");
	err = fopen_s(&F2, "f2_dop3.txt", "w");

	for (int i = 0; i < 8 && fgets(str, 255, F1) != NULL; i++)
	{
		if (i % 2 == 1)
			fputs(str, F2);
	}
	fclose(F1);
	fclose(F2);
}

int main() {
	setlocale(LC_ALL, "Russian");
	first();
	second();
	dop1();
	dop2();
	dop3();
}
