#include "Poker.h"
int main()
{
	
	DeckOfCards deckOfCards;
	deckOfCards.shuffle();
	deckOfCards.deal();
	deckOfCards.roundResult();
	return 0;
}