#include "Employee.h"
#include "BasePlusCommEmpl.h"
#include "CommissionEmployee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
using std::endl;
using std::cout;
using std::fixed;
using std::setprecision;
using std::vector;


int main()
{
	cout << fixed << setprecision(2);
	vector < Employee *>employees(4);

	employees[0] = new SalariedEmployee(
		"John", "Smith", "111 - 11 - 1111", 800.0);
	employees[1] = new HourlyEmployee(
		"Karen", "Price", "222 - 22 - 2222", 16.75, 40);
	employees[2] = new CommissionEmployee(
		"Sue", "Jones", "333 - 33 - 3333", 10000, .06);
	employees[3] = new BasePlusCommEmpl(
		"Bob", "Lewis", "444 - 44 - 4444", 5000, .04, 300);
	for (size_t i = 0; i < employees.size(); i++)
	{
		employees[i]->print();
		cout << endl;

		BasePlusCommEmpl * derivedPtr =
			dynamic_cast<BasePlusCommEmpl*>(employees[i]);
		if (derivedPtr != 0)
		{
			double oldBaseSalary = derivedPtr->getBaseSalary();
			cout << "old base salary: $" << oldBaseSalary << endl;
			derivedPtr->setBaseSalary(1.10*oldBaseSalary);
			cout << "new base salary with 10 % increase is: $"
				<< derivedPtr->getBaseSalary() << endl;
		}
		cout << "earned $" << employees[i]->earnings() << "\n\n";
	}
	for (size_t j = 0; j < employees.size(); j++)
	{
		cout << "deleting object of "
			<< typeid(*employees[j]).name() << endl;
		delete employees[j];
	}
	return 0;
}