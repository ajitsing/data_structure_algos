#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef int (*hashGerator)(void* key); 
typedef int (*Comparator)(void* a, void* b);

typedef struct{
	LinkList* list;
	int NumberOfbuckets;
	hashGerator genratorFun;
	Comparator comparatorFun;
} Map;


Map* createMap(int buckets, hashGerator genrator, Comparator comprator);
void destroyMap(Map* map);
void put(Map* map,void* key,void* value);
void removeValue(Map* map,void* key);
void* get(Map* map,void* key);
int getCount(Map* map);