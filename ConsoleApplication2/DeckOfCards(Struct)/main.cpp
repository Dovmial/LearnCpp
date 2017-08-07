#include <iostream>
#include "DeckOfCards.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	DeckOfCards deckOfCards;
	deckOfCards.shuffle();
	deckOfCards.deal();
	return 0;
}