#include <stdio.h>

typedef struct{
	int id;
	char name[20];
	int salary;
}Employee;

typedef struct{
	int size;
	int empCount;
	void* employees;
}Employees;

typedef void (*itrator)(Employee* emps);
typedef int (*matcher)(Employee* emps);

Employees* createEmployees(int numberOfEmployees);
void clearEmployees(Employees *emps);
void add(Employees* emps, Employee newEmp);
void each(Employees* emps, itrator itrate);
Employee findAllBy(Employees* emps, matcher match);