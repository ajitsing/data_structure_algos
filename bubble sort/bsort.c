#include "bsort.h"

void bsort(int* array, int size){
	int i,j,temp,flag = 0;
	for (i = 0; i < size; i++){

		flag = 0;

		for (j=0; j < size-i-1; j++){

			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				flag = 1;
			}
		}
		
		if(flag == 0)break;
	}
}
