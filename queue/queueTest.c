#include "sampletestUtils.h"
#include "queue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue *queue;

void test_create_a_queue_of_size_20(){
	queue = createQueue(queue, 20);
	ASSERT(queue->rear==-1 && queue->front==-1 && queue->max_size == 19);
}

void test_queue_is_empty(){
	ASSERT(isEmpty(queue));
}

void test_queue_is_not_full(){
	ASSERT(isFull(queue)==0);
}

void test_insert_10_in_queue(){
	queue = insertElement(queue, 10);
	ASSERT(queue->array[queue->rear] == 10);
}

void test_insert_20_in_queue(){
	queue = insertElement(queue, 20);
	ASSERT(queue->array[queue->rear] == 20);
}

void test_insert_30_in_queue(){
	queue = insertElement(queue, 30);
	ASSERT(queue->array[queue->rear] == 30);
}

void test_insert_40_in_queue(){
	queue = insertElement(queue, 40);
	ASSERT(queue->array[queue->rear] == 40);
}

void test_insert_50_in_queue(){
	queue = insertElement(queue, 50);
	ASSERT(queue->array[queue->rear] == 50);
}

void test_delete_10_from_queue(){
	int element = deleteElement(queue);
	ASSERT(element == 10);
}

void test_delete_20_from_queue(){
	int element = deleteElement(queue);
	ASSERT(element == 20);
}

void test_delete_30_from_queue(){
	int element = deleteElement(queue);
	ASSERT(element == 30);
}

void test_insert_10_again_in_queue(){
	queue = insertElement(queue, 10);
	ASSERT(queue->array[queue->rear] == 10);
}

void test_print_queue(){
	displayQueue(queue);
	ASSERT(1);
}