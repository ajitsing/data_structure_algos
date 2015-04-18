#include "sampletestUtils.h"
#include "linkedList.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

LinkList *linklist = NULL;

void test_create_LinkList(){
	linklist = createLinkList(linklist);
	ASSERT(linklist->start->data == 0 && (countNumberOfNodes(linklist)==1));
}

void test_add_10_to_LinkList_at_1st_location(){
	ASSERT((insertDataInLinkedList(linklist, 1, 10))==1 && (countNumberOfNodes(linklist)==2)==1 );
}

void test_update_value_10_to_1(){
	updateNode(linklist, 1, 1);
	ASSERT(searchDataInLinkList(linklist, 1) == 1);
}

void test_delete_10_from_linklist(){
	ASSERT(deleteDataFromLinkList(linklist, 1));
}

void test_add_10_again_to_LinkList_at_1st_location(){
	ASSERT((insertDataInLinkedList(linklist, 1, 10))==1 && (countNumberOfNodes(linklist)==2)==1 );
}

void test_add_20_to_linklist_at_2nd_location(){
	ASSERT((insertDataInLinkedList(linklist, 2, 20))==1 && (countNumberOfNodes(linklist)==3)==1 );
}

void test_add_30_to_linklist_at_2nd_location(){
	ASSERT((insertDataInLinkedList(linklist, 2, 30))==1 && (countNumberOfNodes(linklist)==4)==1 );
}

void test_add_40_to_linklistat_2nd_location(){
	ASSERT((insertDataInLinkedList(linklist, 2, 40))==1 && (countNumberOfNodes(linklist)==5)==1 );
}

void test_add_50_to_linklist_at_4th_location(){
	ASSERT((insertDataInLinkedList(linklist, 4, 50))==1 && (countNumberOfNodes(linklist)==6)==1 );
}

void test_add_60_to_linklist_at_the_end(){
	ASSERT((insertDataInLinkedList(linklist, 6, 60))==1 && (countNumberOfNodes(linklist)==7)==1);
}

void test_add_70_to_linklist_at_1st_location(){
	ASSERT((insertDataInLinkedList(linklist, 1, 70))==1 && (countNumberOfNodes(linklist)==8)==1 );
}

void test_delete_60_from_linklist(){
	ASSERT(deleteDataFromLinkList(linklist, 7));
}

void test_70_is_at_1st_position(){
	ASSERT(searchDataInLinkList(linklist, 1) == 70);
}

void test_20_is_at_6th_position(){
	ASSERT(searchDataInLinkList(linklist, 6) == 20);
}

void test_10_is_at_2nd_position(){
	ASSERT(searchDataInLinkList(linklist, 2) == 10);
}

void test_delete_40_from_the_linklist(){	
	ASSERT(deleteDataFromLinkList(linklist, 3));	
}

void test_delete_10_from_the_linklist(){
	ASSERT(deleteDataFromLinkList(linklist, 2));	
}

void test_delete_first_node_from_the_linklist(){
	ASSERT(deleteDataFromLinkList(linklist, 1));	
}

void test_50_is_at_2nd_position(){
	ASSERT(searchDataInLinkList(linklist, 2) == 50);
}

void test_will_not_delete_100_which_is_not_in_the_linklist(){
	ASSERT(deleteDataFromLinkList(linklist, 11) == 0);	
}

void test_will_not_delete_60_which_is_not_in_the_linklist(){
	ASSERT(deleteDataFromLinkList(linklist, 10) == 0);	
}

void test_display_list(){
	displayLinkList(linklist);
	ASSERT(1);
}

void test_clear_the_linklist(){
	ASSERT(clearTheLinkList(linklist));
}