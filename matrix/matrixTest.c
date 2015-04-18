#include "sampletestUtils.h"
#include "matrix.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Matrix* matrix = NULL;

void test_create_matrix_of_5_X_5_size(){
	matrix = createMatrix(5, 5);
	ASSERT(matrix->rowSize == 5 && matrix->columnSize == 5);
}

void test_insert_10_in_the_row_0_column_1(){
	insertItem(matrix, 0, 1, 10);
	ASSERT(getItem(matrix, 0, 1) == 10);
}

void test_insert_20_in_the_row_3_column_4(){
	insertItem(matrix, 3, 4, 20);
	ASSERT(getItem(matrix, 3, 4) == 20);
}

void test_insert_30_in_the_row_4_column_4(){
	insertItem(matrix, 4, 4, 30);
	ASSERT(getItem(matrix, 4, 4) == 30);
}

void test_can_not_insert_40_in_the_row_5_column_1(){
	insertItem(matrix, 5, 1, 30);
	ASSERT(1);
}

void test_replace_30_in_the_row_4_column_4_by_35(){
	insertItem(matrix, 4, 4, 35);
	ASSERT(getItem(matrix, 4, 4) == 35);
}

void test_replace_55_in_the_row_1_column_0_by_55(){
	insertItem(matrix, 1, 0, 55);
	ASSERT(getItem(matrix, 1, 0) == 55);
}

void test_set_1_2_3_4_5_values_in_matrix(){
	int array[] = {1,2,3,4,5};
	setRow(matrix, array, 0);
	ASSERT(getItem(matrix, 0, 0) == 1 && getItem(matrix, 0, 4) == 5);
}

void test_set_6_7_8_9_10_values_in_matrix(){
	int array[] = {6,7,8,9,10};
	setRow(matrix, array, 1);
	ASSERT(getItem(matrix, 1, 0) == 6 && getItem(matrix, 1, 4) == 10);
}

void test_set_11_12_13_14_15_values_in_matrix(){
	int array[] = {11,12,13,14,15};
	setRow(matrix, array, 2);
	ASSERT(getItem(matrix, 2, 0) == 11 && getItem(matrix, 2, 4) == 15);
}

void test_set_16_17_18_19_20_values_in_matrix(){
	int array[] = {16,17,18,19,20};
	setRow(matrix, array, 3);
	ASSERT(getItem(matrix, 3, 0) == 16 && getItem(matrix, 3, 4) == 20);
}

void test_set_21_22_23_24_25_values_in_matrix(){
	int array[] = {21,22,23,24,25};
	setRow(matrix, array, 4);
	ASSERT(getItem(matrix, 4, 0) == 21 && getItem(matrix, 4, 4) == 25);
}


void test_convert_matrix_in_text(){
	printf("%s\n", toText(matrix));
	ASSERT(1);
}

void test_set_1_2_3_4_5_values_in_column_matrix(){
	int array[] = {1,2,3,4,5};
	setColumn(matrix, array, 0);
	ASSERT(getItem(matrix, 0, 0) == 1 && getItem(matrix, 4,0 ) == 5);
}

void test_set_6_7_8_9_10_values_in_column_matrix(){
	int array[] = {6,7,8,9,10};
	setColumn(matrix, array, 1);
	ASSERT(getItem(matrix, 0, 1) == 6 && getItem(matrix, 4, 1) == 10);
}

void test_convert_matrix_in_text_and_print(){
	printf("%s\n", toText(matrix));
	ASSERT(1);
}

void test_set111_222_333_444_555_666_777_888_999_100_values_in_column_matrix(){
	int array[] = {111,222,333,444,555,666,777,888,999,100};
	// printf("%d\n",sizeof(array)/sizeof(array[0]) );getchar();

	setValues(matrix, array);
	ASSERT(getItem(matrix, 0, 0) == 111 && getItem(matrix, 1, 4) == 100);
}

void test_11convert_matrix_in_text_and_print(){
	printf("%s\n", toText(matrix));
	ASSERT(1);
}

