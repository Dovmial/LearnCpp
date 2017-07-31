// sizeOF(file).cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using std::ofstream;
using std::ios;
using std::cerr;
using std::endl;
using std::exit;
using std::setw;
using std::right;
using std::left;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream fout("Data_types(size).dat", ios::out);
	if (!fout)
	{
		cerr << "ошибка открыти€\n";
		exit(1);
	}
	fout << setw(20) <<left << std::fixed<<std::setprecision(1)
		<< "тип данных" << setw(15) << "размер" << setw(20) << "ћаксимум" << endl

		<< setw(20) << "bool" << setw(15) << sizeof(bool)
		<< setw(20) << pow(2, sizeof(bool) * 8) - 1 << endl

		<< setw(20) << "char" << setw(15) << sizeof(bool)
		<< setw(20) << pow(2, sizeof(char) * 8 - 1)-1 << endl

		<< setw(20) << "unsigned char" << setw(15) << sizeof(unsigned char)
		<< setw(20) << pow(2, sizeof(unsigned char) * 8)-1 << endl

		<< setw(20) << "short int" << setw(15) << sizeof(short int)
		<< setw(20) << pow(2, sizeof(short int) * 8-1) - 1 << endl

		<< setw(20) << "unsigned short int" << setw(15) << sizeof(unsigned short int)
		<< setw(20) << pow(2, sizeof(unsigned short int) * 8) - 1 << endl

		<< setw(20) << "int" << setw(15) << sizeof(int)
		<< setw(20) << pow(2, sizeof(int) * 8-1) - 1 << endl

		<< setw(20) << "unsigned int" << setw(15) << sizeof(unsigned int)
		<< setw(20) << pow(2, sizeof(unsigned int) * 8) - 1 << endl

		<< setw(20) << "long int" << setw(15) << sizeof(long int)
		<< setw(20) << pow(2, sizeof(long int) * 8-1) - 1 << endl

		<< setw(20) << "unsigned long int" << setw(15) << sizeof(unsigned long int)
		<< setw(20) << pow(2, sizeof(unsigned long int) * 8) - 1 << endl

		<< setw(20) << "float" << setw(15) << sizeof(float)
		<< setw(20) << pow(2, sizeof(float) * 8-1) - 1 << endl

		<< setw(20) << "double" << setw(15) << sizeof(double)
		<< setw(20) << pow(2, sizeof(double) * 8-1) - 1 << endl

		<< setw(20) << "long double" << setw(15) << sizeof(long double)
		<< setw(20) << pow(2, sizeof(long double) * 8-1) - 1 << endl;
fout.close();
	std::cout << "данные записаны в \"Data_types(size).dat\"" << endl;
    return 0;
}

