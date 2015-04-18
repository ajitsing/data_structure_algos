#include "hashMap.h"

Map* createMap(int buckets){
	Map* map = (Map*)malloc(sizeof(Map));
	map->NumberOfbuckets = buckets;
	map->lastBucket = -1;
	map->list = createArrayOfList(map->NumberOfbuckets);
	return map;
}

void destroyMap(Map* map){
	free(map->list);
	free(map);
}

Pair* createPair(){
	Pair *newPair = (Pair*)malloc(sizeof(Pair));
	newPair->customer = (Customer*)malloc(sizeof(Customer));
	newPair->number = (PhoneNumber*)malloc(sizeof(PhoneNumber));
	return newPair;
}

int getHashCode(Map* map, PhoneNumber number){
	int i=0,sum = 0;
	while(number.phoneNumber[i] != '\0'){
		sum += number.phoneNumber[i];
		i++;
	}
	return sum % map->NumberOfbuckets;
}

int isPresent(Map* map, PhoneNumber key){
	int i,flag = 0;
	for (i = 1; i <= map->NumberOfbuckets; i++){
		if(searchDataInLinkList(&map->list[getHashCode(map, key)], i)!= NULL && 
			strcmp(searchDataInLinkList(&map->list[getHashCode(map, key)], i)->number->phoneNumber,
			key.phoneNumber) == 0){

			flag = 1; break;
		}
	}
	return flag;
}

void put(Map* map, PhoneNumber key, Customer value){
	int i,notAvailable = 0;
	Pair *newPair = createPair();

	if(isPresent(map, key))return;

	strcpy(newPair->customer->name, value.name);
	strcpy(newPair->customer->address.city, value.address.city);
	strcpy(newPair->customer->address.street, value.address.street);
	strcpy(newPair->customer->address.state, value.address.state);
	strcpy(newPair->customer->number.areaCode, key.areaCode);
	strcpy(newPair->customer->number.phoneNumber, key.phoneNumber);

	insertDataInLinkedList(&map->list[getHashCode(map, key)], 1, *newPair);
}

int getIndex(LinkList list, PhoneNumber key){
	int j;
	if(list.start->link == NULL){ printf("==>list is empty\n");getchar();  return 0; }

	for (j = 1; j <= countNumberOfNodes(&list); j++){
		if(strcmp(searchDataInLinkList(&list, j)->number->phoneNumber,key.phoneNumber)==0)return j;
	}
	return j;
}

Customer get(Map* map,PhoneNumber key){
	int index;
	if(!isPresent(map, key))printf("customer is not present\n");  
	index = getIndex(map->list[getHashCode(map, key)], key);
	return *searchDataInLinkList(&map->list[getHashCode(map, key)], index)->customer;
}

void removeCustomer(Map* map,PhoneNumber key){
	int position = getIndex(map->list[getHashCode(map, key)], key);
	deleteDataFromLinkList(&map->list[getHashCode(map, key)], position);
}

int getCount(Map* map){
	int i,sum=0;
	for (i = 0; i < map->NumberOfbuckets; i++){
		sum += countNumberOfNodes(&map->list[i])-1;
	}
	return sum;
}

void getKeys(Map* map){
	int i;
	for (i = 0; i < map->NumberOfbuckets; i++){
		printf("\t\t\tBucket No. = %d\n\t\t\t______________\n\n",i+1 );
		displayLinkList(&map->list[i]);
		printf("\n\n");
	}
}