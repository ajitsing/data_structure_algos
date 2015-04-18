#include "sampletestUtils.h"
#include "priorityQueue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

PriorityQueue* queue = NULL;

void setup(){
	queue = createQueue(5);
}

void tearDown(){
	clearQueue(queue);
}

void test_enQueue(){

	Process newProcess1, newProcess2, newProcess3, newProcess4, newProcess5;
	strcpy(newProcess1.name ,"Git");
	newProcess1.Time = 10;
	newProcess1.priority = 3;

	strcpy(newProcess2.name ,"Sublime");
	newProcess2.Time = 10;
	newProcess2.priority = 2;

	strcpy(newProcess3.name ,"Browser");
	newProcess3.Time = 10;
	newProcess3.priority = 1;

	strcpy(newProcess4.name ,"Vlc");
	newProcess4.Time = 10;
	newProcess4.priority = 5;

	strcpy(newProcess5.name ,"Notepad");
	newProcess5.Time = 10;
	newProcess5.priority = 4;

	enQueue(queue, newProcess1);
	enQueue(queue, newProcess2);
	enQueue(queue, newProcess3);
	enQueue(queue, newProcess4);
	enQueue(queue, newProcess5);

	ASSERT(PROCESS[0].priority == 3  &&  PROCESS[4].priority == 4);
}

void test_deQueue(){
	Process newProcess1, newProcess2, newProcess3, newProcess4, newProcess5;
	strcpy(newProcess1.name ,"Git");
	newProcess1.Time = 10;
	newProcess1.priority = 3;

	strcpy(newProcess2.name ,"Sublime");
	newProcess2.Time = 10;
	newProcess2.priority = 2;

	strcpy(newProcess3.name ,"Browser");
	newProcess3.Time = 10;
	newProcess3.priority = 1;

	strcpy(newProcess4.name ,"Vlc");
	newProcess4.Time = 10;
	newProcess4.priority = 5;

	strcpy(newProcess5.name ,"Notepad");
	newProcess5.Time = 10;
	newProcess5.priority = 4;

	enQueue(queue, newProcess1);
	enQueue(queue, newProcess2);
	enQueue(queue, newProcess3);
	enQueue(queue, newProcess4);
	enQueue(queue, newProcess5);

	ASSERT(deQueue(queue).priority == 1);
}