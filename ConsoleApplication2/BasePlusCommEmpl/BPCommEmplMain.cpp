#include <iostream>
#include <iomanip>
#include "BasePlusCommEmpl.h"
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
	BasePlusCommEmpl employee(
		"Bob", "Lewis", "333-33-33", 5000, .04, 300);
	cout << fixed << setprecision(2);
	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial security number is "
		<< employee.getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionRate()
		<< "\nBase Salary is " << employee.getBaseSalary() << endl;

	employee.setBaseSalary(1000);
	cout << "\nUpdated empoloyee information "
		<< "output by print function: \n" << endl;
	employee.print();
	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
	return 0;
}