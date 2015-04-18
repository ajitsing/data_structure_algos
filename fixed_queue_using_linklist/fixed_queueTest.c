#include "sampletestUtils.h"
#include "fixed_queue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue *queue = NULL;

void test_create_queue_for_5_elements(){
	queue = createQueue(5);
	ASSERT(queue->max_size == 5 && queue->front == 0);
}

void test_insert_10_at_the_rear_end(){
	insertItem(queue, 10);
	ASSERT( searchDataInLinkList(queue->linklist, 1) == 10);
}

void test_insert_20_at_the_rear_end(){
	insertItem(queue, 20);
	ASSERT( searchDataInLinkList(queue->linklist, 2) == 20);
}


void test_insert_30_at_the_rear_end(){
	insertItem(queue, 30);
	ASSERT( searchDataInLinkList(queue->linklist, 3) == 30);
}


void test_insert_40_at_the_rear_end(){
	insertItem(queue, 40);
	ASSERT( searchDataInLinkList(queue->linklist, 4) == 40);
}


void test_insert_50_at_the_rear_end(){
	insertItem(queue, 50);
	ASSERT( searchDataInLinkList(queue->linklist, 5) == 50);
}

void test_insert_60_at_the_rear_end(){
	insertItem(queue, 60);
	ASSERT( searchDataInLinkList(queue->linklist, 6) != 60);
}

void test_delete_10_from_the_list(){
	removeItem(queue);
	ASSERT(searchDataInLinkList(queue->linklist, 1) == 20);
}

void test_delete_40_from_the_list(){
	removeItem(queue);
	ASSERT(searchDataInLinkList(queue->linklist, 3) == 50);
}

void test_insert_10_again_at_the_rear_end(){
	insertItem(queue, 10);
	ASSERT( searchDataInLinkList(queue->linklist, queue->rear) == 10);
}

void test_insert_40_again_at_the_rear_end(){
	insertItem(queue, 40);
	ASSERT( searchDataInLinkList(queue->linklist, queue->rear) == 40);
}