#include "reverse_list.h"

void transferValuesToStack(LinkList* list, Stack* stack){
	int i,nodes = countNumberOfNodes(list);
	for (i = 1; i <= nodes; i++){
		insertItem(stack, searchDataInLinkList(list, i));
	}
}

void popOutFromStackAndInsertIntoList(LinkList* list, Stack* stack){
	int i;
	for (i = 0; i < 5; i++)deleteDataFromLinkList(list, 1);

	for (i = 1; i < 6; i++)insertDataInLinkedList(list, i, removeItem(stack));
}