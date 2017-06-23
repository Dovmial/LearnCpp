#pragma once

class Complex
{
public:
	Complex(double =0.0, double=0.0);
	Complex Add(Complex,Complex);
	Complex Substruct(Complex, Complex);
	void showComplex();
private:
	double realPart;
	double imaginaryPart;
};