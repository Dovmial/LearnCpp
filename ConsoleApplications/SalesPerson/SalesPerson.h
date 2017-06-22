
#ifndef SALESP_H
#define SALESP_H

class SalesPerson
{
public:
	SalesPerson();
	void getSalesFromUser();   //ввести суммы продаж
	void setSales(int, double);//установить сумму дл€ # мес€ца
	void printAnnualSales();
private:
	double totalAnnualSales();
	double sales[12];
};
#endif