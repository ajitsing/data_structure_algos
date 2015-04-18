#include "insertionSort.h"


void insertionSort(int* array, int size){
	int i,j,key;
	for (i = 1; i <= size; i++){

		j=i-1;
		key = array[i];

		while(j >= 0 && key < array[j]){
			array[j+1] = array[j]; 
			j--;
		}

		array[j+1] = key;
	}

}