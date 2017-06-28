#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"Date.h"
class Employee
{
public:
	Employee(const char* const, const char *const);
	~Employee();
	const char *getFirstName()const;
	const char *getLastName()const;
	static int getCount();
private:
	char *firstName;
	char *lastName;
	const Date birthDate; //композиция: элемент объект
	const Date hireDate;
	static int count;
};
#endif // !EMPLOYEE_H
