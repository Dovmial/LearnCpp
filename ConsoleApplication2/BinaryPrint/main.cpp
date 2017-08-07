//#include<iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//#include <iomanip>
//using std::setw;
//
//void displayBits(unsigned);
//
//int main()
//{
//	unsigned number1;
//	unsigned number2;
//	unsigned number3;
//	unsigned mask;
//	unsigned setBits;
//
//	//  &
//	number1 = 2179876355;
//	mask = 1;
//	cout << "The result of combining the following\n";
//	displayBits(number1);
//	displayBits(mask);
//	cout << "using the bitwise AND operator & is\n";
//	displayBits(number1 & mask);
//
//	//  |
//	number1 = 15;
//	setBits = 241;
//	cout << "\nThe result of combining the following\n";
//	displayBits(number1);
//	displayBits(setBits);
//	cout << "using the inclusive OR operator | is\n";
//	displayBits(number1 | setBits);
//
//	//  ^
//	number1 = 139;
//	number2 = 199;
//	cout << "\nThe result of combining the following\n";
//	displayBits(number1);
//	displayBits(number2);
//	cout << "using the exclusive OR operator ^ is\n";
//	displayBits(number1 ^ number2);
//
//	//поразрядное дополнение
//	number1 = 21845;
//	cout << "\nThe one's complement of\n";
//	displayBits(number1);
//	cout << "is" << endl;
//	displayBits(~number1);
//
//	//  <<
//	number1 = 960;
//	cout << "The result of left shifting\n";
//	displayBits(number1);
//	cout << "8 bit positions using the left-shift operator is\n";
//	displayBits(number1 << 8);
//
//	cout << "\nThe result of right shifting\n";
//	displayBits(number1);
//	cout << "8 bit positions using right shifting\n";
//	displayBits(number1 >> 8);
//	return 0;
//}
//
//void displayBits(unsigned value)
//{
//	const int SHIFT = 8 * sizeof(unsigned) - 1;
//	const unsigned MASK = 1 << SHIFT;
//	cout << setw(10) << value << " = ";
//	for (unsigned i = 1; i <= SHIFT + 1; i++)
//	{
//		cout << (value & MASK ? '1' : '0');
//		value <<= 1;
//		if (i % 8 == 0)
//			cout << ' ';
//	}
//	cout << endl;
//}
#include"DeckOfCards(bits).h"
int main()
{
	DeckOfCards deckOfCards;
	deckOfCards.deal();
	return 0;
}