#include"ComplexClass.h"
#include<iostream>
using std::cout;

Complex::Complex(double realPart, double imaginaryPart)
	:real(realPart), imaginary(imaginaryPart)
{}

Complex Complex::operator+(const Complex &operand2)const
{
	return Complex(real + operand2.real,
		imaginary + operand2.imaginary);
}
Complex Complex::operator-(const Complex &operand2)const
{
	return Complex(real - operand2.real,
		imaginary - operand2.imaginary);
}
Complex Complex::operator*(const Complex &operand2)const
{
	return Complex(real*operand2.real - imaginary*operand2.imaginary,
		real*operand2.imaginary + operand2.real*imaginary);
}
bool Complex::operator==(const Complex &operand2)const
{
	return real == operand2.real && imaginary == operand2.imaginary;
}
//display
ostream &operator<<(ostream &output,const Complex &c)
{
	output << '(' << c.real << ", " << c.imaginary << ')';
	return output;
}
