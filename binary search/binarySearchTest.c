#include "sampletestUtils.h"
#include "binarySearch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef char* string;

int comparator(const void* a, const void* b){
	if(*(int*)a == *(int*)b)return 0;
	else if(*(int*)a > *(int*)b)return 1;
	else return -1;
}

int floatcomparator(const void* a, const void* b){
	if(*(float*)a == *(float*)b)return 0;
	else if(*(float*)a > *(float*)b)return 1;
	else return -1;
}

int charComparator(const void* a, const void* b){
	if(*(char*)a == *(char*)b)return 0;
	else if(*(char*)a > *(char*)b)return 1;
	else return -1;
}

int stringComparator(const void* a, const void* b){
	return strcmp((string)a,(string)b);
}

void test_search_item_1(){
	int array[7] = {10,20,30,40,50,60,70};
	int i,key = 20;
	i = *(int*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), comparator);
	ASSERT(i == 20);
}

void test_search_item_2(){
	int array[7] = {10,20,30,40,50,60,70};
	int i,key = 70;
	i = *(int*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), comparator);
	ASSERT(i == 70);
}

void test_search_item_3(){
	int array[7] = {10,20,30,40,50,60,70};
	int i,key = 30;
	i = *(int*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), comparator);
	ASSERT(i == 30);
}

void test_search_item_4(){
	int array[7] = {10,20,30,40,50,60,70};
	int i,key = 50;
	i = *(int*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), comparator);
	ASSERT(i == 50);
}

void test_search_item_5(){
	int array[7] = {10,20,30,40,50,60,70};
	int i,key = 10;
	i = *(int*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), comparator);
	ASSERT(i == 10);
}

void test_search_item_6(){
	int array[7] = {10,20,30,40,50,60,70};
	int i,key = 40;
	i = *(int*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), comparator);
	ASSERT(i == 40);
}

void test_search_item_7(){
	int array[7] = {10,20,30,40,50,60,70};
	int i,key = 60;
	i = *(int*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), comparator);
	ASSERT(i == 60);
}

void test_search_item_8(){
	char array[7] = {'a','b','c','d','e','f','g'};
	char i,key = 'c';
	i = *(string)binarySearch(&key, array, sizeof(array[0]), sizeof(array), charComparator);
	ASSERT(i == 'c');
}

void test_search_item_9(){
	char array[7] = {'a','b','c','d','e','f','g'};
	char i,key = 'e';
	i = *(string)binarySearch(&key, array, sizeof(array[0]), sizeof(array), charComparator);
	ASSERT(i == 'e');
}

void test_search_item_10(){
	char array[7] = {'a','b','c','d','e','f','g'};
	char i,key = 'b';
	i = *(string)binarySearch(&key, array, sizeof(array[0]), sizeof(array), charComparator);
	ASSERT(i == 'b');
}

void test_search_item_11(){
	float array[7] = {10.0,20.0,30.0,40.0,50.0,60.0,70.0};
	float i,key = 20.0;
	i = *(float*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), floatcomparator);
	ASSERT(i == 20.0);
}

void test_search_item_12(){
	float array[7] = {10.0,20.0,30.0,40.0,50.0,60.0,70.0};
	float i,key = 50.0;
	i = *(float*)binarySearch(&key, array, sizeof(array[0]), sizeof(array), floatcomparator);
	ASSERT(i == 50.0);
}

void test_search_item_13(){
	char array[7][6] = {"aaaaa","bbbbb","ccccc","ddddd","eeeee","fffff","ggggg"};
	string i;
	char key[10] = "ccccc";
	i = (string)binarySearch(&key, array, sizeof(array[0]), sizeof(array), charComparator);
	ASSERT(strcmp(i,"ccccc")==0);
}