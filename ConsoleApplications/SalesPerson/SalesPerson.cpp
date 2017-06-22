#include"SalesPerson.h"
#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

SalesPerson::SalesPerson()
{
	for (int i = 0; i < 12; i++)
		sales[i] = 0.0;
}

void SalesPerson::getSalesFromUser()
{
	double salesFigure;
	for (int i = 1; i <= 12; i++)
	{
		cout << "Enter sales amount for month "
			 << i <<": ";
		cin >> salesFigure;
		setSales(i, salesFigure);
	}
}

void SalesPerson::setSales(int month, double amount)
{
	if (month >= 1 && month <= 12 && amount > 0)
		sales[month - 1] = amount;
	else
		cout << "Invalid month or sales figure" << endl;
}

void SalesPerson::printAnnualSales()
{
	cout << setprecision(2) << fixed
		<< "\nThe total annual sales are: $"
		<< totalAnnualSales() << endl;
}

double SalesPerson::totalAnnualSales()
{
	double total = 0.0;
	for (int i = 0; i < 12; i++)
		total += sales[i];
	return total;
}