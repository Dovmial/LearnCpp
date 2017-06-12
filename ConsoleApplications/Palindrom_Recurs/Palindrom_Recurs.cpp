// Palindrom_Recurs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<string>
using std::string;

int testPalindrom(string);
int main()
{
	string str2 = "10563501";
	int c = testPalindrom(str2);
	std::cout << "\n\n"<<c <<"   "<<str2.length()-2<< std::endl;
	return 0;
}
int testPalindrom(string s)
{
	
	if (s.length() == 1)
		return 1;
	else
	{
		std::cout << "\nstr1: " << s.substr(0, 1) << "\nstr2: "<< s.substr(s.length() - 1, 1)<<std::endl;
		if (s.substr(0, 1)==s.substr(s.length() - 1, 1))
		{	
			// Базовый случай 
			if (s.length() == 2)
				return 1;
			// Шаг рекурсии / рекурсивное условие
			return testPalindrom(s.substr(1, s.length() - 2));
		}
		else
			return 0;
	}
}
