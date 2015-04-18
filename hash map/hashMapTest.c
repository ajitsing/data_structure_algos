#include "sampletestUtils.h"
#include "hashMap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Map* map = NULL;

void setup(){
	map = createMap(4);
}

void tearDown(){
	destroyMap(map);
}

void test_add_the_customers(){

 	Customer newCustomer1 = {"Ajit",{"Ascendas Road","Chennai","Tamil Nadu"},{"+91","9991250770"}};
 	Customer newCustomer2 = {"Baljit",{"Barwala Road","Hisar", "Haryana"},{"+92","9294856534"}};
 	Customer newCustomer3 = {"Kuldeep",{"Barwala Road","Hisar", "Haryana"},{"+91","8294856534"}};
 	Customer newCustomer4 = {"Mohan",{"Hansi Road","Hansi", "Haryana"},{"+93","7294124343"}};
 	PhoneNumber number1 = {"+91","9991250770"};
 	PhoneNumber number2 = {"+92","9294856534"};
 	PhoneNumber number3 = {"+91","8294856534"};
 	PhoneNumber number4 = {"+93","7294124343"};

	put(map, number1, newCustomer1);
	put(map, number2, newCustomer2);
	put(map, number3, newCustomer3);
	put(map, number4, newCustomer4);
	getKeys(map);

	ASSERT(strcmp(searchDataInLinkList(&map->list[3], 2)->customer->name,"Baljit")==0 &&
		strcmp(searchDataInLinkList(&map->list[1], 1)->customer->name,"Ajit")==0 &&
		getCount(map) == 4);

}

void test_get_customer_using_key(){
	Customer result1,result2,result3,result4;
 	Customer newCustomer1 = {"Ajit",{"Ascendas Road","Chennai","Tamil Nadu"},{"+91","9991250770"}};
 	Customer newCustomer2 = {"Baljit",{"Barwala Road","Hisar", "Haryana"},{"+92","9294856534"}};
 	Customer newCustomer3 = {"Kuldeep",{"Barwala Road","Hisar", "Haryana"},{"+91","8294856534"}};
 	Customer newCustomer4 = {"Mohan",{"Hansi Road","Hansi", "Haryana"},{"+93","7294124343"}};
 	PhoneNumber number1 = {"+91","9991250770"};
 	PhoneNumber number2 = {"+92","9294856534"};
 	PhoneNumber number3 = {"+91","8294856534"};
 	PhoneNumber number4 = {"+93","7294124343"};
 	PhoneNumber key1 = {"+91","9991250770"};
 	PhoneNumber key2 = {"+92","9294856534"};
 	PhoneNumber key3 = {"+91","8294856534"};
 	PhoneNumber key4 = {"+93","7294124343"};


	put(map, number1, newCustomer1);
	put(map, number2, newCustomer2);
	put(map, number3, newCustomer3);
	put(map, number4, newCustomer4);

	result1 = get(map, key1);
	result2 = get(map, key2);
	result4 = get(map, key4);
	result3 = get(map, key3);

	ASSERT(strcmp(result1.name,"Ajit")==0  && strcmp(result2.name,"Baljit")==0
		&& strcmp(result3.name,"Kuldeep")==0  && strcmp(result4.name,"Mohan")==0);

}

void test_remove_key(){
 	Customer newCustomer1 = {"Ajit",{"Ascendas Road","Chennai","Tamil Nadu"},{"+91","9991250770"}};
 	Customer newCustomer2 = {"Baljit",{"Barwala Road","Hisar", "Haryana"},{"+92","9294856534"}};
 	Customer newCustomer3 = {"Kuldeep",{"Barwala Road","Hisar", "Haryana"},{"+91","8294856534"}};
 	Customer newCustomer4 = {"Mohan",{"Hansi Road","Hansi", "Haryana"},{"+93","7294124343"}};
 	PhoneNumber number1 = {"+91","9991250770"};
 	PhoneNumber number2 = {"+92","9294856534"};
 	PhoneNumber number3 = {"+91","8294856534"};
 	PhoneNumber number4 = {"+93","7294124343"};
 	PhoneNumber key1 = {"+91","7294124343"};

	put(map, number1, newCustomer1);
	put(map, number2, newCustomer2);
	put(map, number3, newCustomer3);
	put(map, number4, newCustomer4);

	removeCustomer(map, key1);
	ASSERT(strcmp(searchDataInLinkList(&map->list[3], 1)->customer->name,"Baljit")==0);
}