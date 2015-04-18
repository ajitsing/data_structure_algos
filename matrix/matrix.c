#include "matrix.h"

Matrix* createMatrix(int row, int column){
	int i;
	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
	matrix->array = (Int*)malloc(sizeof(int)*row);
	matrix->columnSize = column;
	matrix->rowSize = row;
	for (i = 0; i < row; i++) matrix->array[i] = malloc(sizeof(int)*column);

	return matrix;
}

void insertItem(Matrix* matrix, int row, int column, int value){
	if((row >= matrix->rowSize) || (column >= matrix->columnSize))return;
	matrix->array[row][column] = value;
}

int getItem(Matrix* matrix, int row, int column){
	if((row >= matrix->rowSize) || (column >= matrix->columnSize))return 0;
	return matrix->array[row][column];
}

void setRow(Matrix* matrix, int *array, int row){
	int i,k = 0;
	for (i = 0; i < matrix->columnSize; i++){

		if(k > matrix->columnSize)break;
		matrix->array[row][i] = array[k];
		k++;
	}
}

void setColumn(Matrix* matrix, int *array, int column){
	int i,k = 0;
	for (i = 0; i < matrix->rowSize; i++){

		if(k > matrix->rowSize)break;
		matrix->array[i][column] = array[k];
		k++;
	}
}


char* toText(Matrix* matrix){
	int i,j,k=0;
	char value[10];
	char* string = (char*)malloc(100);
	strcpy(string,"");
	for (i = 0; i < matrix->rowSize; i++){

		for (j = 0; j < matrix->columnSize; j++){ 
			sprintf(value,"%d",matrix->array[i][j]);
			strcat(value,", ");
			strcat(string,value);
			k++;
		}
		strcat(string,"\n");
	}
	return string;
}

int arraySize(int array[]){
	int i;
	char value[10];
	char* string = (char*)malloc(100);
	for (i = 0; ; i++)
	{
		sprintf(string, "%d", array[i]);
		strcat(string,value);
	}
	*string = '\0';
	printf("%d\n",i );getchar();
	return i;
}

void setValues(Matrix* matrix, int array[]){
	int i,j,k=0;
	int length = arraySize(array);
	for (i = 0; i < matrix->rowSize ; i++)
	{
		for (j = 0; j < matrix->rowSize; j++)
		{
			if(k == 10)break;
			matrix->array[i][j] = array[k];
			k++;
		}
	}
}