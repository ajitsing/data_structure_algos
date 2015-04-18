#include <stdio.h>

typedef struct {
	int id;
	char name[20];
	int salary;
}Employee;

typedef struct {
	int size;
	int empCount;
	void * employees;
}Employees;

typedef struct {
	Employees * employees;
	int position;
}EmployeeItrator;

typedef int (*matcher)(Employee* emps);

EmployeeItrator* createItrator(int numberOfEmployees);
void clearEmployees(EmployeeItrator *itrator);

void add(EmployeeItrator *itrator, Employee newEmp);
Employee next(EmployeeItrator *it);

int hasNext(EmployeeItrator *it);
Employee findAllBy(EmployeeItrator* it, matcher match);