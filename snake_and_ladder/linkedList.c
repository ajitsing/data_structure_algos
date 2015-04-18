#include "linkedList.h"

LinkList* createLinkList(LinkList* linklist){
	linklist = (LinkList*)malloc(sizeof(LinkList));
	linklist->start = (struct Node*)malloc(sizeof(struct Node));
	linklist->start->link = NULL;
	linklist->start->data = 0;
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

struct Node* addTheNodeNextToStart(struct Node* newNode, LinkList* linklist, int data){
	linklist->start->link = newNode;
	newNode->data = data;
	newNode->link = NULL;
	return newNode;
}

struct Node* addTheNextNodeAtTheEnd(struct Node* newNode, LinkList* linklist, int data, struct Node* ptr){
	ptr->link = newNode;
	newNode->data =data;
	newNode->link = NULL;
	return newNode;
}

struct Node* addTheNextNodeInTheMiddle(struct Node* newNode, LinkList* linklist, int data, struct Node* prev_ptr){
	newNode->data = data;
	newNode->link = prev_ptr->link;
	prev_ptr->link = newNode;	
	return newNode;
}

int insertDataInLinkedList(LinkList* linklist, int index, int data){
	int count=0,totalNodes = countNumberOfNodes(linklist);
	struct Node *ptr = linklist->start, *prev_ptr = ptr;
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
	if(index > totalNodes+1 || index == 0){ free(newNode);   return 0; }

	while(ptr != NULL && count != totalNodes){
		
		if(linklist->start->link == NULL)addTheNodeNextToStart(newNode, linklist, data);
		else if((count == index-1) && (ptr->link == NULL))addTheNextNodeAtTheEnd(newNode,linklist,data,ptr);
		else if((count == index-1) && (ptr->link != NULL))addTheNextNodeInTheMiddle(newNode,linklist,data,prev_ptr);
		
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

int searchDataInLinkList(LinkList *linklist, int position){
	struct Node *ptr = linklist->start;
	int index = 1;
	ptr = ptr->link;
	while(ptr != NULL){
		if(position == index)return ptr->data;
		index++;
		ptr = ptr->link;
	}
	return 0;
}

void displayLinkList(LinkList *linklist){
	struct Node *ptr = linklist->start;
	ptr = ptr->link;
	while(ptr != NULL){
		printf("%d\t",ptr->data );
		ptr = ptr->link;
	}
}

int clearTheLinkList(LinkList *linklist){
	free(linklist);
	return 1;
}