#include "sampletestUtils.h"
#include "mergeSort.h"
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_sort_1_3_2_8_9_4_5(){
	int array[7] = {1,3,2,8,9,4,5};
	mergeSort(array, 7);
	ASSERT(array[1] == 2);
}

void test_sort_7_6_5_4_3_2_1(){
	int array[7] = {7,6,5,4,3,2,1};
	mergeSort(array, 7);
	ASSERT(array[0] == 1 && array[1] == 2 && array[2] == 3 && array[3] == 4 && array[6] == 7);
}

void test_sort_1_2_3_4_5_6_7(){
	int array[7] = {1,2,3,4,5,6,7};
	mergeSort(array, 7);
	ASSERT(array[0] == 1 && array[1] == 2 && array[2] == 3 && array[3] == 4 && array[6] == 7);
}

void test_sort_7_1_2_3_4_5_6(){
	int array[7] = {7,1,2,3,4,5,6};
	mergeSort(array, 7);
	ASSERT(array[0] == 1 && array[1] == 2 && array[2] == 3 && array[3] == 4 && array[6] == 7);
}