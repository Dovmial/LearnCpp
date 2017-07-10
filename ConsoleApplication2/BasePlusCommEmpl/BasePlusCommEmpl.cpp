#include <iostream>
#include "BasePlusCommEmpl.h"
using std::cout;

BasePlusCommEmpl::BasePlusCommEmpl(
	const string &first, const string &last,
	const string &ssn, double sales, double rate,
	double salary)
{
	firstName = first;
	lastName = last;
	socialSecurityNumber = ssn;
	setGrossSales(sales);
	setBaseSalary(salary);
	setCommissionRate(rate);
}

void  BasePlusCommEmpl::setFirstName(const string &first)
{
	firstName = first;
}
string BasePlusCommEmpl::getFirstName()const
{
	return firstName;
}
void  BasePlusCommEmpl::setLastName(const string &last)
{
	lastName = last;
}
string BasePlusCommEmpl::getLastName()const
{
	return lastName;
}
void BasePlusCommEmpl::setSocialSecurityNumber(
	const string &ssn)
{
	socialSecurityNumber = ssn;
}
string BasePlusCommEmpl::getSocialSecurityNumber()const
{
	return socialSecurityNumber;
}
void BasePlusCommEmpl::setCommissionRate(double rate)
{
	comissionRate = (rate > 0.0 &&rate < 1.0 ? rate : 0.0);
}
double BasePlusCommEmpl::getCommissionRate()const
{
	return comissionRate;
}
void BasePlusCommEmpl::setGrossSales(double sales)
{
	grossSales = (sales < 0.0) ? 0.0 : sales;
}
double BasePlusCommEmpl::getGrossSales()const
{
	return grossSales;
}
void BasePlusCommEmpl::setBaseSalary(double salary)
{
	basesalary = (salary < 0.0) ? 0.0 : salary;
}
double BasePlusCommEmpl::getBaseSalary()const
{
	return basesalary;
}
double BasePlusCommEmpl::earnings()const
{
	return basesalary + (comissionRate*grossSales);
}
void BasePlusCommEmpl::print()const
{
	cout << "base - salaried commission employee: "
		<< firstName << ' ' << lastName
		<< "\nsocial security number: "
		<< socialSecurityNumber << "\ngross sales: "
		<< grossSales << "\ncommission rate: " << comissionRate
		<< "\nbase salary: " << basesalary;
}
