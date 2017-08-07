#include <iostream>
#include <iomanip>
#include "DeckOfCards(bits).h"

using std::cout;
using std::setw;
using std::endl;

DeckOfCards::DeckOfCards()
{
	for (int i = 0; i <= 51; ++i)
	{
		deck[i].face = i % 13;
		deck[i].suit = i / 13;
		deck[i].color = i / 26;
	}
}

void DeckOfCards::deal()
{
	for (int k1 = 0, k2 = k1 + 26; k1 <= 25; ++k1, ++k2)
		cout << "Card:" << setw(3) << deck[k1].face
		<< "  Suit:" << setw(2) << deck[k1].suit
		<< "  Color:" << setw(2) << deck[k1].color
		<< "  " << "Card:" << setw(3) << deck[k2].face
		<< "  Suit:" << setw(2) << deck[k2].suit
		<< "  Color:" << setw(2) << deck[k2].color << endl;
}
