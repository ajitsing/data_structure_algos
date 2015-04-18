#include "employee.h"
#include <stdlib.h>
#include <string.h>


EmployeeItrator* createItrator(int numberOfEmployees){
	EmployeeItrator *itrator = (EmployeeItrator*) malloc(sizeof(EmployeeItrator));
	itrator->employees = (Employees*) malloc(sizeof(Employees));
	itrator->employees->employees = (Employee*) malloc(sizeof(Employee)*numberOfEmployees);
	itrator->employees->size = numberOfEmployees;
	itrator->employees->empCount = 0;
	itrator->position = 0;
	return itrator;
}

void clearEmployees(EmployeeItrator *itrator){
	free(itrator->employees->employees);
	free(itrator->employees);
	free(itrator);
}

void add(EmployeeItrator *itrator, Employee newEmp){
	Employee *emp1;
	emp1 = (Employee*)itrator->employees->employees;
	emp1[itrator->employees->empCount].salary = newEmp.salary;
	emp1[itrator->employees->empCount].id = newEmp.id;
	strcpy(emp1[itrator->employees->empCount].name,newEmp.name);
	itrator->employees->empCount++;
}

Employee next(EmployeeItrator* it){
	Employee *emp1 = (Employee*)it->employees->employees;	
	if(!hasNext(it))it->position = 0;
	it->position++;
	return emp1[it->position-1];
}

int hasNext(EmployeeItrator *it){
	if(it->position == it->employees->size)return 1;
	return 0;
}

Employee findAllBy(EmployeeItrator* it, matcher match){
	int i;
	Employee* emp1 = (Employee*)it->employees->employees;
	for (i = 0; i < it->employees->empCount; i++){
		if(match(&emp1[i]))break;
	}
	return emp1[i];
}