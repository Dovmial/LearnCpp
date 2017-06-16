#pragma once
class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle(); 
	void deal();
	//int player1();
	

private:
	int deck[4][13];
	int Suit[5];
	int Face[5];
	const char * suit[4] =
	{ "Hearts","Diamonds","Clubs","Spades" };
	const char *face[13] =
	{ "Ace","Deuce","Three","Four","Five","Six",
		"Seven","Eight","Nine","Ten","Jack","Queen","King" };
	enum checkCombo {Null,Pair,TwoPair,Three,Full_Haus,Care,Flash,Street};
	checkCombo combo = Null;
	void combinations(int[],int[]);
	void checkFlash(int suit[]);
	void checkStreet(int face[]);
	void checkRepeat(int face[]);
	void showCombo();
};