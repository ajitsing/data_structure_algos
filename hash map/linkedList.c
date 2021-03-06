#include "linkedList.h"
#include <string.h>

LinkList* createArrayOfList(int numberOfBuckets){
	int i;
	LinkList* linklist = (LinkList*)malloc(sizeof(LinkList)*numberOfBuckets);

	for (i = 0; i < numberOfBuckets; i++){
		linklist[i].start = (struct Node*) malloc(sizeof(struct Node));
		linklist[i].start->pair = (Pair*) malloc(sizeof(Pair));
		linklist[i].start->pair->number = (PhoneNumber*) malloc(sizeof(PhoneNumber));
		linklist[i].start->link = NULL;
	}
	return linklist;
}

int countNumberOfNodes(LinkList* linklist){
	int count = 0;
	struct Node *ptr = linklist->start;
	while(ptr != NULL){
		ptr = ptr->link;
		count++;
	}
	return count;
}

void copyFields(struct Node* newNode,Pair newPairs){
	strcpy(newNode->pair->customer->name,newPairs.customer->name);
	strcpy(newNode->pair->customer->address.city ,newPairs.customer->address.city);
	strcpy(newNode->pair->customer->address.street ,newPairs.customer->address.street);
	strcpy(newNode->pair->customer->address.state ,newPairs.customer->address.state);

	strcpy(newNode->pair->number->phoneNumber ,newPairs.customer->number.phoneNumber);
	strcpy(newNode->pair->number->areaCode ,newPairs.customer->number.areaCode);
}

struct Node* addTheNodeNextToStart(struct Node* newNode, LinkList* linklist, Pair newPairs){
	linklist->start->link = newNode;
	copyFields(newNode,newPairs);
	newNode->link = NULL;
	return newNode;
}

struct Node* addTheNextNodeAtTheEnd(struct Node* newNode, LinkList* linklist, Pair newPairs, struct Node* ptr){
	ptr->link = newNode;
	copyFields(newNode,newPairs);
	newNode->link = NULL;
	return newNode;
}

struct Node* addTheNextNodeInTheMiddle(struct Node* newNode, LinkList* linklist, Pair newPairs, struct Node* prev_ptr){
	copyFields(newNode,newPairs);
	newNode->link = prev_ptr->link;
	prev_ptr->link = newNode;	
	return newNode;
}

struct Node* createNode(){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->pair = (Pair*)malloc(sizeof(Pair));
	newNode->pair->customer = (Customer*)malloc(sizeof(Customer));
	newNode->pair->number = (PhoneNumber*)malloc(sizeof(PhoneNumber));
	
	return newNode;
} 

int insertDataInLinkedList(LinkList* linklist, int index, Pair newPairs){
	int count=0,totalNodes = countNumberOfNodes(linklist);
	struct Node *ptr = linklist->start, *prev_ptr = ptr;	
	struct Node* newNode = createNode(); 

	if(index > totalNodes+1 || index == 0){ free(newNode);   return 0; }
	while(ptr!= NULL && count != totalNodes){
		if(linklist->start->link == NULL)addTheNodeNextToStart(newNode, linklist, newPairs);
		else if((count == index-1) && (ptr->link == NULL))addTheNextNodeAtTheEnd(newNode,linklist,newPairs,ptr);
		else if((count == index-1) && (ptr->link != NULL))addTheNextNodeInTheMiddle(newNode,linklist,newPairs,prev_ptr);
		ptr = ptr->link;
		count++;
		prev_ptr = ptr;
	}
	return 1;
}

int deleteDataFromLinkList(LinkList *linklist, int position){
	struct Node *prev_ptr, *ptr = linklist->start;
	int index = 1, flag=0;

	if(linklist->start->link == NULL)return 0;
	ptr = ptr->link; 
					                          			
	while(ptr != NULL){

		if(position == index){                 			
			
			flag = 1;
			                          					
			if(index==1)linklist->start->link = ptr->link;  
			else if(index == countNumberOfNodes(linklist)-1)prev_ptr->link = NULL;
			else prev_ptr->link = ptr->link;           			

			free(ptr);
			break; 
		}

		index++;
		prev_ptr = ptr;
		ptr = ptr->link;
	}

	if(flag != 1)return 0;

	return 1;
}

Pair* searchDataInLinkList(LinkList *linklist, int position){
	struct Node *ptr = linklist->start;
	int index = 1;
	ptr = ptr->link;
	while(ptr != NULL){
		if(position == index)return ptr->pair;
		index++;
		ptr = ptr->link;
	}
	return NULL;
}

void updateNode(LinkList *linklist,int position,Pair value){
	struct Node *ptr = linklist->start;
	int index = 1;
	ptr = ptr->link;
	while(ptr != NULL){
		if(position == index){
			copyFields(ptr, value);
			break;
		}
		index++;
	}	
}

void displayLinkList(LinkList *linklist){
	struct Node *ptr = linklist->start;
	ptr = ptr->link;
	while(ptr != NULL){
		printf("\t\t\t%-10s   %-s\n",ptr->pair->customer->name, ptr->pair->number->phoneNumber );
		ptr = ptr->link;
	}
}

int clearTheLinkList(LinkList *linklist){
	free(linklist);
	return 1;
}