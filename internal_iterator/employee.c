#include <stdlib.h>
#include <string.h>
#include "employee.h"

Employees* createEmployees(int numberOfEmployees){
	Employees *emps = (Employees*) malloc(sizeof(Employees));
	emps->employees = (Employee*) malloc(sizeof(Employee)*numberOfEmployees);
	emps->size = numberOfEmployees;
	emps->empCount = 0;
	return emps;
}

void clearEmployees(Employees *emps){
	free(emps->employees);
	free(emps);
}

void add(Employees *emps, Employee newEmp){
	Employee *emp1;
	emp1 = (Employee*)emps->employees;
	emp1[emps->empCount].salary = newEmp.salary;
	emp1[emps->empCount].id = newEmp.id;
	strcpy(emp1[emps->empCount].name,newEmp.name);
	emps->empCount++;
}

void each(Employees* emps, itrator itrate){
	int i;
	Employee* emp1 = (Employee*)emps->employees;

	for (i = 0; i < emps->empCount; i++)itrate(&emp1[i]);
}

Employee findAllBy(Employees* emps, matcher match){
	int i;
	Employee* emp1 = (Employee*)emps->employees;
	for (i = 0; i < emps->empCount; i++){
		if(match(&emp1[i]))break;
	}
	return emp1[i];
}