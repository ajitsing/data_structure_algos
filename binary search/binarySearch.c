#include "binarySearch.h"

void* binarySearch(const void *key, void* values, int elementSize, int totalSize,Comparator comparator){	
	int i = 0,index = 0,count = totalSize/elementSize;
	char *source = (char*)values;

	for (; i < count; i++){
		
		if((count - i) >= 2)index = count/2;
		else index++;

		if(comparator(source + index*elementSize, key) == 0)return source + index*elementSize;
		
		else if(comparator(source + index*elementSize, key) == 1){
			count = index;
			i = 0;
		}

		else if(comparator(source + index*elementSize, key) == -1){
			source += index*elementSize;
			i = index;
		}

	}
	return source;
}