#include "Poker.h"
#include <iostream>
using std::cout;
using std::endl;

#include <ctime>
using std::time;

#include<cstdlib>
using std::srand;
using std::rand;
#include<iomanip>
using std::setw;

DeckOfCards::DeckOfCards()
{
	for (int row = 0; row <= 3; row++)
		for (int column = 0; column <= 12; column++)
			deck[row][column] = 0;
	srand(time(0));
}

void DeckOfCards::shuffle()
{
	int row, column;
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

	for (int card = 1; card <= 5; card++)
		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
				if (deck[row][column] == card)
				{
					Suit[card - 1] = row; Face[card - 1] = column;
					cout << setw(5) << std::right
						<< face[column] << " of " << setw(8)
						<< std::left << suit[row] << endl;
				}
	for (int i = 0; i < 5; i++)
		cout << Face[i] << " of " << Suit[i] << endl;
	combinations(Face, Suit);
}

void DeckOfCards::combinations(int face[], int suit[])
{		//sorting arrays
	int faceSorted[5];
	//int suitSorted[5];
	for (int i = 0; i < 5; i++)
	{
		faceSorted[i] = face[i];
//		suitSorted[i] = suit[i];
	}
	for (int i = 4; i != 0; i--)
		for (int j = 0; j < i; j++)
		{
			if (faceSorted[j] > faceSorted[j + 1])
			{
				int swap = faceSorted[j];
				faceSorted[j] = faceSorted[j + 1];
				faceSorted[j + 1] = swap;
			}
/*			if (suitSorted[j] > suitSorted[j + 1])
			{
				int swap = suitSorted[j];
				suitSorted[j] = suitSorted[j + 1];
				suitSorted[j + 1] = swap;
			}*/
		}
	//Pointer at function? 550 стр
	checkFlash(suit);
	if (combo == Null)
		checkStreet(faceSorted);
	if (combo == Null)
		checkRepeat(faceSorted);
	showCombo();
}
void DeckOfCards::checkFlash(int suit[])
{
	int i = 1;
	while (i < 5)
	{
		if (suit[i - 1] == suit[i])
			i++;
		else
			break;
	}
	if (i == 5)
		combo = Flash;
}
void DeckOfCards::checkStreet(int face[])
{
	if (face[0] <= 9)
	{
		if (face[0] == 0)
		{
			int j = 1;
			for (int i = 10; j <= 4; i++)
			{
				if (face[j] == i)
					j++;
				else
					break;
			}
			if (j == 5)
				combo = Street;
		}
		else
		{
			int i = 1;
			while (i <= 4)
			{
				if (face[i - 1] == face[i] - 1)
					i++;
				else
					break;
			}
			if (i == 5)
				combo = Street;
		}
	}
}
/*  {{0,0},
	{1,0},{1,1},  pair/2pairs
	{1,2},{2,1},  full-haus
	{2,0},		  three
	{3,0}}		  care
	*/
void DeckOfCards::checkRepeat(int face[])
{
	int key = 0; //index of key
	int k; // step on deck
	int PairOrThree[2] = { 0 }; //key: 1 - pair; 2- Three; 3 - Four;
	for (k = 1; k < 5; k++)
	{
		for (int i = k; i < 5; i++)
		{
			if (face[i] == face[i - 1])
				PairOrThree[key]++; //count of repeat
			else
				break;
		}
		if (PairOrThree[key] > 0)
		{
			if (PairOrThree[key] == 3)  //If found four - exit
				break;
			else
			{
				k += PairOrThree[key];
				key++;
			}
		}
	}

	if (PairOrThree[0] == 3)
		combo = Care;

	else if (PairOrThree[1] == 0)
	{
		if (PairOrThree[0] == 2)
			combo = Three;
		else if (PairOrThree[0] == 1)
			combo = Pair;
	}

	else
	{
		for (int j = 0; j < 2; j++)
			if (PairOrThree[j] == 2)
			{
				combo = Full_Haus; break;
			}
		if (PairOrThree[0] == PairOrThree[1])
			combo = TwoPair;
	}
}

void DeckOfCards::showCombo()
{
	switch (combo)
	{
	case Pair: {cout << "\nYou have Pair!\n"; break; }
	case TwoPair: {cout << "\nYou have TwoPairs!\n"; break; }
	case Three: {cout << "\nYou have Three!\n"; break; }
	case Care: {cout << "\nYou have Care!\n"; break; }
	case Flash: { cout << "\nYou have Flash!\n"; break; }
	case Street: {cout << "\nYou have Street!\n"; break; }
	default: {cout << "\nNot combinations\n"; break; }
	}
}