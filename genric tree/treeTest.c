#include "sampletestUtils.h"
#include "tree.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Tree* tree = NULL;

typedef struct{
	int id;
	char name[20];
	int salary;
}Employee;

int comparator(void *a, void* b){
	Employee emp = *(Employee*)a;
	if(emp.id == *(int*)b)return 1;
	return 0;
}

void setup(){
	tree = createTree(comparator);
}

void tearDown(){
	destroyTree(tree);
}

void test_add_data(){
	int key1 = 1,key2 = 2,key3 = 3,key4 = 4,key5 = 5,key6 = 6,key7 = 7, key8 = 8;
	Employee *checkout1,*checkout2,*checkout3,*checkout4,*checkout5,*checkout6,*checkout7,*checkout8;

	Employee newEmp1 = {1,"Ajit",8000};
	Employee newEmp2 = {2,"Baljit",10000};
	Employee newEmp3 = {3,"Kuldeep",7000};
	Employee newEmp4 = {4,"Kiran",9000};
	Employee newEmp5 = {5,"Anil",11000};
	Employee newEmp6 = {6,"Kumar",9000};
	Employee newEmp7 = {7,"Rana",9000};
	Employee newEmp8 = {8,"Kishan",1000};

	Employee boss;
	insertNode(tree, &newEmp1, &boss);
	boss.id = 1;
	insertNode(tree, &newEmp2, &boss);
	insertNode(tree, &newEmp3, &boss);
	insertNode(tree, &newEmp4, &boss);
	boss.id = 2;
	insertNode(tree, &newEmp5, &boss);
	boss.id = 5;
	insertNode(tree, &newEmp6, &boss);
	boss.id = 6;
	insertNode(tree, &newEmp7, &boss);
	boss.id = 3;
	insertNode(tree, &newEmp8, &boss);

	checkout1 = (Employee*)findNode(tree, &key1)->employee;
	checkout2 = (Employee*)findNode(tree, &key2)->employee;
	checkout3 = (Employee*)findNode(tree, &key3)->employee;
	checkout4 = (Employee*)findNode(tree, &key4)->employee;
	checkout5 = (Employee*)findNode(tree, &key5)->employee;
	checkout6 = (Employee*)findNode(tree, &key6)->employee;
	checkout7 = (Employee*)findNode(tree, &key7)->employee;
	checkout8 = (Employee*)findNode(tree, &key8)->employee;


	ASSERT(checkout1->id == 1 && checkout2->id == 2 &&
		checkout3->id == 3 && checkout4->id == 4 &&
		checkout5->id == 5 && checkout6->id == 6 &&
		checkout7->id == 7 && checkout8->id == 8);
}

void test_remove_data(){
	int key7 = 7;
	Employee *checkout7;

	Employee newEmp1 = {1,"Ajit",8000};
	Employee newEmp2 = {2,"Baljit",10000};
	Employee newEmp3 = {3,"Kuldeep",7000};
	Employee newEmp4 = {4,"Kiran",9000};
	Employee newEmp5 = {5,"Anil",11000};
	Employee newEmp6 = {6,"Kumar",9000};
	Employee newEmp7 = {7,"Rana",9000};
	Employee newEmp8 = {8,"Kishan",1000};

	Employee boss;
	insertNode(tree, &newEmp1, &boss);
	boss.id = 1;
	insertNode(tree, &newEmp2, &boss);
	insertNode(tree, &newEmp3, &boss);
	insertNode(tree, &newEmp4, &boss);
	boss.id = 2;
	insertNode(tree, &newEmp5, &boss);
	boss.id = 5;
	insertNode(tree, &newEmp6, &boss);
	boss.id = 6;
	insertNode(tree, &newEmp7, &boss);
	boss.id = 3;
	insertNode(tree, &newEmp8, &boss);

	removeNode(tree, &newEmp6);
	removeNode(tree, &newEmp8);

	checkout7 = (Employee*)findNode(tree, &key7)->parent->employee;

	ASSERT(checkout7->id == 5);
}