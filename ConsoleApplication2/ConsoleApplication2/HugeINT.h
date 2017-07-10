#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
using std::ostream;

class HugeInt
{
	friend ostream &operator<<(ostream&, const HugeInt &);
public:
	HugeInt(long = 0);//преобразования/по умолчанию
	HugeInt(const char *); //конструктор преобразования

	HugeInt operator+(const HugeInt &)const;
	HugeInt operator+(int)const;
	//HugeInt + string
	HugeInt operator+(const char *)const;
private:
	short integer[30];
};
#endif // !HUGEINT_H
