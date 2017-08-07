#pragma once
struct BitCard
{
	unsigned face : 4;// 4 бита 0-15
	unsigned suit : 2;//2 бита; 0-3
	unsigned color : 1;//1 бит; 0-1
};

class DeckOfCards
{
public:
	DeckOfCards();
	void deal();
private:
	BitCard deck[52];
};