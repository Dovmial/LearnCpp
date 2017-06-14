class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle();
	void deal();
private:
	int deck[4][13];
};