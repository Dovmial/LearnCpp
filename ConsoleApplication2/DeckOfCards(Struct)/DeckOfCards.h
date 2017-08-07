#pragma once
struct Card
{
	char *face;
	char *suit;
};

class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle();
	void deal();
private:
	Card deck[52];
};