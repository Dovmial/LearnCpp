#include<iostream>
#include "StringClass.h"

using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
	String s1("happy");
	String s2(" birthday");
	String s3;

	cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
		<< "\"; s3 is \"" << s3 << '\"'
		<< boolalpha << "\n\nThe results of comparing s2 and s1:"
		<< "\ns2 == s1 yields " << (s2 == s1)
		<< "\ns2 != s1 yields " << (s2 != s1)
		<< "\ns2 > s1 yields " << (s2 > s1)
		<< "\ns2 < s1 yields " << (s2 < s1)
		<< "\ns2 >= s1 yields " << (s2 >= s1)
		<< "\ns2 <= s1 yields " << (s2 <= s1);

	cout << "\n\nTesting !s3:" << endl;

	if (!s3)
	{
		cout << "s3 is empty; assigning s1 to s3;" << endl;
		s3 = s1;
		cout << "s3 is \"" << s3 << "\"";
	}
	cout << "\n\ns1 += \" to you\" yields s1 = " << endl;
	s1 += s2;
	cout << s1;
	cout << "\n\ns1 += \" to you yields" << endl;
	s1 += " to you";
	cout << "s1 = " << s1 << "\n\n";

	cout << "The substring of s1 starting at\n"
		<< "location 15, s1(15), is: "
		<< s1(15) << "\n\n";
	String *s4Ptr = new String(s1);
	cout << "\n*s4Ptr = " << *s4Ptr << "\n\n";

	cout << "assigning *s4Ptr to *s4Ptr" << endl;
	*s4Ptr = *s4Ptr;
	cout << "*s4Ptr = " << *s4Ptr << endl;

	delete s4Ptr;

	s1[0] = 'H';
	s1[6] = 'B';
	cout << "\ns1 after s1[0] = 'H' and s1[6] = "
		<< "'B' is: " << s1 << "\n\n";
	cout << "Attempt to assign 'd' to s1[30] yields:\n";
	s1[30] = 'd';
	return 0;
}