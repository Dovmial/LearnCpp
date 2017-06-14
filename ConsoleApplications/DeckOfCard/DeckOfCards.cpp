#include <iostream>
using std::cout;
using std::left;
using std::right;

#include<iomanip>
using std::setw;

#include<cstdlib>
using std::rand;
using std::srand;

#include<ctime>
using std::time;

#include"DeckOfCards.h"
DeckOfCards::DeckOfCards()
{
	for (int row = 0; row <= 3; row++)
	{
		for (int column = 0; column <= 12; column++)
			deck[row][column] = 0;
	}
	srand(time(0));
}
//перетасовка
void DeckOfCards::shuffle()
{
	int row; int column;
	for (int card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (deck[row][column] != 0);
		deck[row][column] = card;
	}
}
void DeckOfCards::deal()
{
	//массив мастей
	static const char*suit[4] =
	{ "Hearts","Diamonds","Clubs","Spades" };
	//массив номиналов
	static const char *face[13] =
	{ "Ace","Deuce","Three","Four","Five","Six","Seven",
	"Eight","Nine","Ten","Jack","Queen","King" };
	//для каждой карты
	for (int card = 1; card <= 52; card++)
		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
				if (deck[row][column] == card)
					cout << setw(5) << right << face[column]
					<< " of " << setw(8) << left << suit[row]
					<< (card % 2 == 0 ? '\n' : '\t');

}