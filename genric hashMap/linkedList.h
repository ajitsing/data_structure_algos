#include <stdio.h>
#include <stdlib.h>

struct Node{
	void* pair;
	struct Node* link;
};

typedef struct{
	struct Node* start;
}LinkList;

LinkList* createArrayOfList(int numberOfBuckets);
int countNumberOfNodes(LinkList* linklist);
int insertDataInLinkedList(LinkList* linklist, int index, void* pair);
void* searchDataInLinkList(LinkList *linklist, int position);
void displayLinkList(LinkList *linklist);
int deleteDataFromLinkList(LinkList *linklist, int position);
void updateNode(LinkList *linklist,int position,void* value);
int clearTheLinkList(LinkList *linklist);