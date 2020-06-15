#pragma once

#ifndef transpose_h
#define transpose_h


void transpose(double** mas, int* rows, int* cols)
{
	double temp;
	int i, j;

	for (i = 0; i < *rows; i++)
		for (j = 0; j < *cols; j++)
		{
			temp = mas[i][j];
			mas[i][j] = mas[j][i];
			mas[j][i] = temp;
		}

	*rows = *rows + *cols;
	*cols = *rows - *cols;
	*rows = *rows - *cols;
}

#endif