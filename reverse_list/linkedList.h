#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

typedef struct{
	struct Node* start;
}LinkList;

LinkList* createLinkList();
int countNumberOfNodes(LinkList* linklist);
int insertDataInLinkedList(LinkList* linklist, int index, int data);
int searchDataInLinkList(LinkList *linklist, int position);
void displayLinkList(LinkList *linklist);
int deleteDataFromLinkList(LinkList *linklist, int position);
void updateNode(LinkList *linklist,int position,int value);
int clearTheLinkList(LinkList *linklist);