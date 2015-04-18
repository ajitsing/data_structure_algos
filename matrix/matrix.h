#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int* Int;

typedef struct{
	Int* array;
	int rowSize;
	int columnSize;
} Matrix;

Matrix* createMatrix(int row, int column);
void insertItem(Matrix* matrix, int row, int column, int value);
int getItem(Matrix* matrix, int row, int column);
void setRow(Matrix* matrix, int* array, int row);
void setColumn(Matrix* matrix, int *array, int row);
void setValues(Matrix* matrix, int array[]);
char* toText(Matrix* matrix);