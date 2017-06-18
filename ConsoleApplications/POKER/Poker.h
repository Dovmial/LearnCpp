#pragma once
#include <vector>
using std::vector;
class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle(); 
	void deal();
	//int player1();
	

private:
	int deck[4][13];
	int Suit[5]; int Suit2[5];
	int Face[5]; int Face2[5];
	const char * suit[4] =
	{ "Hearts","Diamonds","Clubs","Spades" };
	const char *face[13] =
	{ "Ace","Deuce","Three","Four","Five","Six",
		"Seven","Eight","Nine","Ten","Jack","Queen","King" };
	enum checkCombo {Null,Pair,TwoPair,Three,Street,Flash,Full_Haus,Care,Street_Flash, Flash_Royal};
	checkCombo combo = Null;
	checkCombo combinations(const int[],const int[]);
	void checkFlash(const int suit[]);
	void checkStreet(vector<int> );
	void checkRepeat(vector<int> );
	void showCombo();
	void roundResult(checkCombo, checkCombo, const int[], const int[]);
};