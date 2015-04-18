#include "linearSearch.h"

int linearSearch(LinkList* list,int searchElement){
	int i;
	for (i = 1; i <= countNumberOfNodes(list); i++){
		if(searchDataInLinkList(list, i) == searchElement)break;
	}
	return i;
}