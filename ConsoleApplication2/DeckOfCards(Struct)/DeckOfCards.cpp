#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include"DeckOfCards.h"

using std::cout;
using std::left;
using std::right;
using std::setw;
using std::time;
using std::rand;
using std::srand;

DeckOfCards::DeckOfCards()
{
	static char *suit[4] = { "Черви","Бубны","Трефы", "Пики" };
	static char *face[13] =
	{ "Туз","Двойка","Тройка","Четверка","Пятерка",
	"Шестерка","Семерка","Восьмёрка","Девятка",
	"Десятка","Валет","Дама","Король" };

	for (int i = 0; i < 52; ++i)
	{
		deck[i].face = face[i % 13];
		deck[i].suit = suit[i / 13];
	}

	srand(unsigned int(time(0)));
}

void DeckOfCards::shuffle()
{
	for (int i = 0; i < 52; ++i)
	{
		int j = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

void DeckOfCards::deal()
{
	for (int i = 0; i < 52; ++i)
		cout << right << setw(9) << deck[i].face << ' '
		<< left << setw(5) << deck[i].suit
		<< ((i + 1) % 2 ? '\t' : '\n');
}