#include "sampletestUtils.h"
#include "hashMap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Map* map = NULL;
Map* map2 = NULL;

typedef struct{
	char street[20];
	char city[20];
	char state[20];
} Address;

typedef struct{
	char areaCode[5];
	char phoneNumber[20];
} PhoneNumber;

typedef struct{
	char name[20];
	Address address;
	PhoneNumber number;
} Customer;

// structure for integer key

typedef struct{
	int areaCode;
	int phoneNumber;
} PhoneNumberInteger;

typedef struct{
	char name[20];
	Address address;
	PhoneNumberInteger number;
} CustomerInteger;

int getHashCode(void* number){
	int i=0,sum = 0;
	PhoneNumber* key = (PhoneNumber*)number;
	while(key->phoneNumber[i] != '\0'){
		sum += key->phoneNumber[i];
		i++;
	}
	return sum;
}

int getHashCode2(void* number){
	int i=0,sum = 0;
	PhoneNumberInteger* key = (PhoneNumberInteger*)number;
	return key->phoneNumber;
}


int comparator(void* contact, void* key){
	PhoneNumber* number = (PhoneNumber*)key;
	Customer* customer = (Customer*)contact;
	if(strcmp(customer->number.phoneNumber,number->phoneNumber)==0)return 1;

	return 0;
}

int comparator2(void* contact, void* key){
	PhoneNumberInteger* number = (PhoneNumberInteger*)key;
	CustomerInteger* customer = (CustomerInteger*)contact;
	if(customer->number.phoneNumber == number->phoneNumber)return 1;

	return 0;
}

void setup(){
	map = createMap(4, getHashCode, comparator);
	map2 = createMap(4, getHashCode2, comparator2);
}

void tearDown(){
	destroyMap(map);
	destroyMap(map2);
}

void test_add_the_customers(){

	Customer *checkout1,*checkout2,*checkout3;
 	Customer newCustomer1 = {"Ajit",{"Ascendas Road","Chennai","Tamil Nadu"},{"+91","9991250770"}};
 	Customer newCustomer2 = {"Baljit",{"Barwala Road","Hisar", "Haryana"},{"+92","9294856534"}};
 	Customer newCustomer3 = {"Kuldeep",{"Barwala Road","Hisar", "Haryana"},{"+91","8294856534"}};
 	Customer newCustomer4 = {"Mohan",{"Hansi Road","Hansi", "Haryana"},{"+93","7294124343"}};
 	PhoneNumber number1 = {"+91","9991250770"};
 	PhoneNumber number2 = {"+92","9294856534"};
 	PhoneNumber number3 = {"+91","8294856534"};
 	PhoneNumber number4 = {"+93","7294124343"};

	put(map, &number1, &newCustomer1);
	put(map, &number2, &newCustomer2);
	put(map, &number3, &newCustomer3);
	put(map, &number4, &newCustomer4);
	checkout1 =  (Customer*)get(map, &number1);
	checkout2 =  (Customer*)get(map, &number2);
	checkout3 =  (Customer*)get(map, &number3);


	ASSERT(strcmp(checkout1->name,"Ajit")==0 && strcmp(checkout2->name,"Baljit")==0
		&& strcmp(checkout3->name,"Kuldeep")==0);

}

void test_remove_key(){
	Customer *checkout;
 	Customer newCustomer1 = {"Ajit",{"Ascendas Road","Chennai","Tamil Nadu"},{"+91","9991250770"}};
 	Customer newCustomer2 = {"Baljit",{"Barwala Road","Hisar", "Haryana"},{"+92","9294856534"}};
 	Customer newCustomer3 = {"Kuldeep",{"Barwala Road","Hisar", "Haryana"},{"+91","8294856534"}};
 	Customer newCustomer4 = {"Mohan",{"Hansi Road","Hansi", "Haryana"},{"+93","7294124343"}};
 	PhoneNumber number1 = {"+91","9991250770"};
 	PhoneNumber number2 = {"+92","9294856534"};
 	PhoneNumber number3 = {"+91","8294856534"};
 	PhoneNumber number4 = {"+93","7294124343"};
 	PhoneNumber key1 = {"+93","7294124343"};

	put(map, &number1, &newCustomer1);
	put(map, &number2, &newCustomer2);
	put(map, &number3, &newCustomer3);
	put(map, &number4, &newCustomer4);

	removeValue(map, &key1);

	checkout = get(map, &key1);

	ASSERT(checkout == NULL);
}

void test_add_the_customers_using_integer_key(){

	CustomerInteger *checkout1,*checkout2,*checkout3;
 	CustomerInteger newCustomerInteger1 = {"Ajit",{"Ascendas Road","Chennai","Tamil Nadu"},{91,999125}};
 	CustomerInteger newCustomerInteger2 = {"Baljit",{"Barwala Road","Hisar", "Haryana"},{92,92948}};
 	CustomerInteger newCustomerInteger3 = {"Kuldeep",{"Barwala Road","Hisar", "Haryana"},{91,82948}};
 	CustomerInteger newCustomerInteger4 = {"Mohan",{"Hansi Road","Hansi", "Haryana"},{93,72941}};
 	PhoneNumberInteger number1 = {91,999125};
 	PhoneNumberInteger number2 = {92,92948};
 	PhoneNumberInteger number3 = {91,82948};
 	PhoneNumberInteger number4 = {93,72941};

	put(map2, &number1, &newCustomerInteger1);
	put(map2, &number2, &newCustomerInteger2);
	put(map2, &number3, &newCustomerInteger3);
	put(map2, &number4, &newCustomerInteger4);

	checkout1 =  (CustomerInteger*)get(map2, &number1);
	checkout2 =  (CustomerInteger*)get(map2, &number2);
	checkout3 =  (CustomerInteger*)get(map2, &number3);


	ASSERT(strcmp(checkout1->name,"Ajit")==0 && strcmp(checkout2->name,"Baljit")==0
		&& strcmp(checkout3->name,"Kuldeep")==0);

}

void test_remove_using_integer_key(){
	CustomerInteger *checkout;
 	CustomerInteger newCustomerInteger1 = {"Ajit",{"Ascendas Road","Chennai","Tamil Nadu"},{91,999125}};
 	CustomerInteger newCustomerInteger2 = {"Baljit",{"Barwala Road","Hisar", "Haryana"},{92,92948}};
 	CustomerInteger newCustomerInteger3 = {"Kuldeep",{"Barwala Road","Hisar", "Haryana"},{91,82948}};
 	CustomerInteger newCustomerInteger4 = {"Mohan",{"Hansi Road","Hansi", "Haryana"},{93,72941}};
 	PhoneNumberInteger number1 = {91,999125};
 	PhoneNumberInteger number2 = {92,92948};
 	PhoneNumberInteger number3 = {91,82948};
 	PhoneNumberInteger number4 = {93,72941};
 	PhoneNumberInteger key1 = {93,72941};

	put(map2, &number1, &newCustomerInteger1);
	put(map2, &number2, &newCustomerInteger2);
	put(map2, &number3, &newCustomerInteger3);
	put(map2, &number4, &newCustomerInteger4);

	removeValue(map2, &key1);

	checkout = get(map2, &key1);

	ASSERT(checkout == NULL);
}