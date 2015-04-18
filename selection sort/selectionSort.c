#include "selectionSort.h"
#include <stdio.h>

void selectionSort(int* array, int size){
	int i,j,minIndex,temp;
	for (i = 0; i < size; i++){
		minIndex = array[i];

		for (j = i+1; j < size; j++)if(array[j] < array[minIndex])minIndex = j;	
			
		if(array[i] > array[minIndex]){
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}