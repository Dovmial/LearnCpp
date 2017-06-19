#include "Poker.h"
#include <iostream>
int main()
{
	
	DeckOfCards deckOfCards;
	for (int i = 0; i < 3; i++)
		deckOfCards.shuffle();
	deckOfCards.deal();
	deckOfCards.roundResult();
	return 0;
}