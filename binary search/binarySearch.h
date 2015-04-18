#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Comparator)(const void* a, const void* b);

void* binarySearch(const void *key, void *array, int elementSize, int totalSize, Comparator comparator);