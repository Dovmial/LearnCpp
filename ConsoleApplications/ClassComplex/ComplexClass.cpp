#include"ComplexClass.h"
#include<iostream>

Complex::Complex(double real, double imagin)
{
	realPart = real;
	imaginaryPart = imagin;
}
Complex Complex::Add(Complex c1, Complex c2)
{
	Complex c3;
	c3.realPart = c1.realPart + c2.realPart;
	c3.imaginaryPart = c1.imaginaryPart + c2.imaginaryPart;
	return c3;
}
Complex Complex::Substruct(Complex c1, Complex c2)
{
	Complex c3;
	c3.realPart = c1.realPart - c2.realPart;
	c3.imaginaryPart = c1.imaginaryPart - c2.imaginaryPart;
	return c3;
}
void Complex::showComplex()
{
	std::cout << '(' << realPart << ", " << imaginaryPart << ')' << std::endl;
}