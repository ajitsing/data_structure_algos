#include <string.h>
#include "sampletestUtils.h"
#include "employee.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Employees *emps = NULL;

void setup(){
	emps = createEmployees(5);
}

void tearDown(){
	clearEmployees(emps);
}

void test_add_employee(){
	Employee newEmp1 = {1,"Ajit",5000};
	Employee newEmp2 = {2,"Baljit",6000};
	Employee newEmp3 = {3,"Kamal",7000};
	
	Employee *test = (Employee*)emps->employees;

	add(emps, newEmp1);
	add(emps, newEmp2);
	add(emps, newEmp3);

	ASSERT(test[0].id == 1 && test[1].id == 2 && test[2].id == 3);
}

void makeSalaryDouble(Employee *emps){
	emps->salary = emps->salary*2;
}

void test_for_each_employee_make_the_salary_double(){
	Employee newEmp1 = {1,"Ajit",5000};
	Employee newEmp2 = {2,"Baljit",6000};
	Employee newEmp3 = {3,"Kamal",7000};
	Employee *test = (Employee*)emps->employees;

	add(emps, newEmp1);
	add(emps, newEmp2);
	add(emps, newEmp3);	

	each(emps, makeSalaryDouble);

	ASSERT(test[0].salary == 10000);
}

void startIdFrom10(Employee* emps){
	emps->id += 9;
}

void test_for_each_employee_start_the_id_from_10(){
	Employee newEmp1 = {1,"Ajit",5000};
	Employee newEmp2 = {2,"Baljit",6000};
	Employee newEmp3 = {3,"Kamal",7000};
	Employee *test = (Employee*)emps->employees;

	add(emps, newEmp1);
	add(emps, newEmp2);
	add(emps, newEmp3);

	each(emps, startIdFrom10);

	ASSERT(test[0].id == 10 && test[1].id == 11 && test[2].id == 12);
}

int findWhereSalaryIs6000(Employee* emp){
	if(emp->salary == 6000)return 1;
	return 0;
}

void test_find_the_employee_whose_salary_is_6000(){
	Employee temp;
	Employee newEmp1 = {1,"Ajit",5000};
	Employee newEmp2 = {2,"Baljit",6000};
	Employee newEmp3 = {3,"Kamal",7000};
	Employee *test = (Employee*)emps->employees;

	add(emps, newEmp1);
	add(emps, newEmp2);
	add(emps, newEmp3);	

	temp = findAllBy(emps, findWhereSalaryIs6000);

	ASSERT(temp.salary == 6000);
}

int matchWhereIdIs3(Employee* emps){
	if(emps->id == 3)return 1;
	return 0;	
}

void test_find_the_employee_whose_id_is_3(){
	Employee temp;
	Employee newEmp1 = {1,"Ajit",5000};
	Employee newEmp2 = {2,"Baljit",6000};
	Employee newEmp3 = {3,"Kamal",7000};
	Employee *test = (Employee*)emps->employees;

	add(emps, newEmp1);
	add(emps, newEmp2);
	add(emps, newEmp3);	

	temp = findAllBy(emps, matchWhereIdIs3);

	ASSERT(temp.id == 3);
}