#include "sampletestUtils.h"
#include "employee.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

EmployeeItrator* itrator = NULL;

void setup(){
	itrator = createItrator(5);
}

void tearDown(){
	clearEmployees(itrator);
}

void test_add_employee(){
	Employee newEmp1 = {1,"Ajit",5000};
	Employee newEmp2 = {2,"Baljit",6000};
	Employee newEmp3 = {3,"Kamal",7000};
	
	Employee *test = (Employee*)itrator->employees->employees;

	add(itrator, newEmp1);
	add(itrator, newEmp2);
	add(itrator, newEmp3);

	ASSERT(test[0].id == 1 && test[1].id == 2 && test[2].id == 3);
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
	Employee *test = (Employee*)itrator->employees->employees;

	add(itrator, newEmp1);
	add(itrator, newEmp2);
	add(itrator, newEmp3);

	temp = findAllBy(itrator, findWhereSalaryIs6000);

	ASSERT(temp.salary == 6000);
}

void test_itrate_employees_and_the_first_employee_is_Ajit(){
	Employee temp;
	Employee newEmp1 = {1,"Ajit",5000};
	Employee newEmp2 = {2,"Baljit",6000};
	Employee newEmp3 = {3,"Kamal",7000};
	
	add(itrator, newEmp1);
	add(itrator, newEmp2);
	add(itrator, newEmp3);

	temp = next(itrator);

	ASSERT(temp.id == 1);
}