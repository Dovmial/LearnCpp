#include "ComplexClass.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Complex x;
	Complex y(2.0, 3.0);
	Complex z(-1.0, 1.0);

	cout << "x: "<<x;
	cout << "\ny: "<<y;
	cout << "\nx: "<<z;
	

	x = y + z;
	cout << "\n\nx = y + z: " << endl;
	cout << x << " = " << y << " + " << z << endl;
	
	x = y - z;
	cout << "\n\nx = y - z: " << endl;
	cout << x << " = " << y << " - " << z << endl;
	cout << endl;

	x = y*z;
	cout << "\n\nx = y * z: " << endl;
	cout << x << " = " << y << " * " << z << endl;
	cout << "x = y?  ";
	x == y ? cout << 'y' : cout << 'n';
	cout << endl;
	x = y;
	cout << "x = y?  ";
	x == y ? cout << 'y' : cout << 'n';
	cout << "\nx != y?  ";
	x != y ? cout << 'y' : cout << 'n';
	cout << endl;
	return 0;
}