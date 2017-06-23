#include "ComplexClass.h"
int main()
{
	Complex z1(15, 26);
	Complex z2(11, 35);
	Complex z3;
	z3 = z3.Add(z1, z2);
	Complex z4 = z4.Substruct(z1, z2);
	z3.showComplex();
	z4.showComplex();
	return 0;
}