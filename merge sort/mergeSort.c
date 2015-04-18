#include "mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *values, int *temp, int left, int middle, int right){
    int i, left_end, numberOfElements, temp_position;
 
  	left_end = middle - 1;
  	temp_position = left;
  	numberOfElements = right - left + 1;
 
  	while((left <= left_end) && (middle <= right)){

    	if(values[left] <= values[middle]){
      		temp[temp_position] = values[left];
      		temp_position++;
      		left++;
    	}
    	else{
      		temp[temp_position] = values[middle];
      		temp_position++;
      		middle++;
    	}
 	}
 
  	while(left <= left_end){
    	temp[temp_position] = values[left];
    	left++;
    	temp_position++;
  	}

  	while(middle <= right){
    	temp[temp_position] = values[middle];
    	middle = middle++;
   	 	temp_position++;
  	}
 
  	for(i=0; i <= numberOfElements; i++){
    	values[right] = temp[right];
    	right--;
  	}
}

void split(int *values, int *temp, int left, int right){
  	int middle;
 
  	if(right > left){
    	middle = (right + left) / 2;

    	split(values, temp, left, middle);
    	split(values, temp, middle+1, right);
 
    	merge(values, temp, left, middle+1, right);
  	}
}

void mergeSort(int* values, int numberOfElements){
	int* temp = (int*)malloc(sizeof(int)*numberOfElements);
  split(values, temp, 0, numberOfElements - 1);
}