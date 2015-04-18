#include "hashMap.h"

Map* createMap(int buckets, hashGerator genrator, Comparator comparator){
	Map* map = (Map*)malloc(sizeof(Map));
	map->NumberOfbuckets = buckets;
	map->genratorFun = genrator;
	map->comparatorFun = comparator;
	map->list = createArrayOfList(map->NumberOfbuckets);
	return map;
}

void destroyMap(Map* map){
	free(map->list);
	free(map);
}

int getBucketNumber(Map* map,void* key){
	return map->genratorFun(key) % map->NumberOfbuckets;
}

int isPresent(Map* map, void* key){
	int i,flag = 0;
	for (i = 1; i <= map->NumberOfbuckets; i++){
		if(searchDataInLinkList(&map->list[getBucketNumber(map, key)], i)!= NULL && 
		 map->comparatorFun(searchDataInLinkList(&map->list[getBucketNumber(map, key)], i), key)){

			flag = 1; break;
		}
	}
	return flag;
}

void put(Map* map, void* key, void* value){
	void* newPair;
	int i,notAvailable = 0;

	if(isPresent(map, key))return;
	newPair = value;

	insertDataInLinkedList(&map->list[getBucketNumber(map, key)], 1, newPair);
}

void* get(Map* map,void* number){
	int index,i,j=1,found = 0;
	for (i = 0; i < map->NumberOfbuckets; i++){
		if((countNumberOfNodes(&map->list[i])-1) <= 0)continue;
		for (j = 1; j <= (countNumberOfNodes(&map->list[i])-1); j++){
			if(map->comparatorFun(searchDataInLinkList(&map->list[i], j),number)){ 
				found = 1; 
				break;
			} 
		}

		if(found == 1)break;
	}
	if(found == 0)return NULL;
	return searchDataInLinkList(&map->list[i], j);
}

void removeValue(Map* map,void* number){
	int i,j=1,found = 0;
	for (i = 0; i < map->NumberOfbuckets; i++){
		if((countNumberOfNodes(&map->list[i])-1) <= 0)continue;
		for (j = 1; j <= (countNumberOfNodes(&map->list[i])-1); j++){
			if(map->comparatorFun(searchDataInLinkList(&map->list[i], j),number)){
			 	found = 1; 
			 	break;
			} 
		}

		if(found == 1)break;
	}
	deleteDataFromLinkList(&map->list[i], j);
}

int getCount(Map* map){
	int i,sum=0;
	for (i = 0; i < map->NumberOfbuckets; i++){
		sum += countNumberOfNodes(&map->list[i])-1;
	}
	return sum;
}