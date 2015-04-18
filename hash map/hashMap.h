#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct{
	LinkList* list;
	int NumberOfbuckets;
	int lastBucket;
} Map;

Map* createMap(int buckets);
void destroyMap(Map* map);
void put(Map* map,PhoneNumber key,Customer value);
void removeCustomer(Map* map,PhoneNumber key);
Customer get(Map* map,PhoneNumber key);
int getCount(Map* map);
void getKeys(Map* map);