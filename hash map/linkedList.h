#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char street[20];
	char city[20];
	char state[20];
} Address;

typedef struct{
	char areaCode[5];
	char phoneNumber[20];
} PhoneNumber;

typedef struct{
	char name[20];
	Address address;
	PhoneNumber number;
} Customer;

typedef struct{
	Customer* customer;
	PhoneNumber* number;
} Pair;

struct Node{
	Pair* pair;
	struct Node* link;
};

typedef struct{
	struct Node* start;
}LinkList;

LinkList* createArrayOfList(int numberOfBuckets);
int countNumberOfNodes(LinkList* linklist);
int insertDataInLinkedList(LinkList* linklist, int index, Pair pair);
Pair* searchDataInLinkList(LinkList *linklist, int position);
void displayLinkList(LinkList *linklist);
int deleteDataFromLinkList(LinkList *linklist, int position);
void updateNode(LinkList *linklist,int position,Pair value);
int clearTheLinkList(LinkList *linklist);