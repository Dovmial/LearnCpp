#include <iostream>
#include "BasePlusCommEmpl.h"
using std::cout;
BasePlusCommEmpl::BasePlusCommEmpl(
	const string &first, const string &last,
	const string &ssn, 
	double sales,double rate, double salary)
	:CommissionEmployee(first, last, ssn, sales, rate)
{
	setBaseSalary(salary);
}
void BasePlusCommEmpl::setBaseSalary(double salary)
{
	baseSalary = (salary < 0.0) ? 0.0 : salary;
}
double BasePlusCommEmpl::getBaseSalary()const
{
	return baseSalary;
}
double BasePlusCommEmpl::earnings()const
{
	return getBaseSalary() + CommissionEmployee::earnings();
}
void BasePlusCommEmpl::print()const
{
	cout << "base - salaried ";
	CommissionEmployee::print();
	cout<< "\nbase salary: " << getBaseSalary();
}
