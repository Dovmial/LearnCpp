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

#include<algorithm>

DeckOfCards::DeckOfCards()
{
	for (int row = 0; row <= 3; row++)
		for (int column = 0; column <= 12; column++)
			deck[row][column] = 0;
	srand((unsigned)time(0));
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
	checkCombo comboPlr1, comboPlr2;
	int numberPlyers = 2; //number of Players (<=10)
	//player1
	/*for (int card = 1; card < 10; card+=2)*/
	for (int card = 1; card <= 5 * numberPlyers; card++)
		for (int row = 0; row <= 3; row++)
			for (int column = 0; column <= 12; column++)
			{
				if (card%numberPlyers == 1)
				{
					if (deck[row][column] == card)
					{
						Suit[(card - 1) / 2] = row; Face[(card - 1) / 2] = column;
						cout << "Player:  " << setw(5) << std::right
							<< face[column] << " of " << setw(8)
							<< std::left << suit[row];
					}
				}
				else
					if (deck[row][column] == card)
					{
						Suit2[card / 2 - 1] = row; Face2[card / 2 - 1] = column;
						/*cout << setw(5) << std::right
							<< face[column] << " of " << setw(8)
							<< std::left << suit[row] << endl;*/
						cout << "\tDieler:  Uknown card\n";
					}
			}
	for (int i = 0; i < 5; i++)
		cout << Face[i] << " of " << Suit[i] << endl;
	comboPlr1 = combinations(Face, Suit);
	for (int i = 0; i < 5; i++)
		cout << Face2[i] << " of " << Suit2[i] << endl;
	comboPlr2 = combinations(Face2, Suit2);
	checkResult(comboPlr2, comboPlr1, Face, Face2);
}

DeckOfCards::checkCombo DeckOfCards::combinations(const int face[], const int suit[])
{		//sorting arrays
	vector<int> faceSorted(face, face + 5); combo = Null;
	std::sort(faceSorted.begin(), faceSorted.end());
	//Pointer at function? 550 стр
	checkFlash(suit);
	if (combo == Null || combo == Flash)
		checkStreet(faceSorted);
	if (combo == Null)
		checkRepeat(faceSorted);
	showCombo();
	return combo;
}
void DeckOfCards::checkFlash(const int suit[])
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
void DeckOfCards::checkStreet(vector<int>  face)
{
	if (face[0] < 9)
	{
		if (face[0] == 0 && face[1] == 9)
		{
			int j = 1;
			for (int i = 9; j <= 4; i++)
			{
				if (face[j] == i)
					j++;
				else
					break;
			}
			if (combo == Flash && j == 5)
				combo = Flash_Royal;
			else if (j == 5)
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
			if (combo == Flash && i == 5)
				combo = Street_Flash;
			else if (i == 5)
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
void DeckOfCards::checkRepeat(vector<int> face)
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
	case Pair: {cout << "You have Pair!\n\n"; break; }
	case TwoPair: {cout << "You have TwoPairs!\n\n"; break; }
	case Three: {cout << "You have Three!\n\n"; break; }
	case Care: {cout << "You have Care!\n\n"; break; }
	case Flash: { cout << "You have Flash!\n\n"; break; }
	case Street: {cout << "You have Street!\n\n"; break; }
	case Full_Haus: {cout << "You have Full-Haus!\n\n"; break; }
	case Street_Flash: {cout << "You have Street-Flash!\n\n"; break; }
	case Flash_Royal: {cout << "You have Flash Royal!!!\n\n"; break; }
	default: {cout << "Not combinations\n\n"; break; }
	}
}

void DeckOfCards::checkResult(checkCombo comboPlayer2, checkCombo comboPlayer1, const int faceVec[], const int faceVec2[])
{
	if (comboPlayer2 < comboPlayer1)
		result[1] = 1;
	else if (comboPlayer1 < comboPlayer2)
		result[2] = 1;
	else if (comboPlayer1 == comboPlayer2)
	{
		vector<int>faceSorted(faceVec, faceVec + 5);
		vector<int>faceSorted2(faceVec2, faceVec2 + 5);
		std::sort(faceSorted.begin(), faceSorted.end());
		std::sort(faceSorted2.begin(), faceSorted2.end());
		if (comboPlayer1 == Null || comboPlayer1 == Flash)
		{
		SearchMaxCard: //goto
			bool flag = true;
			for (int y = 0; y < 5 && flag; y++)
				for (int x = 4; x >= 0; x--)
				{
					if (faceSorted[y] != 0 && faceSorted2[y] != 0)
					{
						if (faceSorted[x] > faceSorted2[x])
						{
							result[1] = 1; flag = false; break;
						}
						else if (faceSorted[x] < faceSorted2[x])
						{
							result[2] = 1; flag = false; break;
						}
					}
					else if (faceSorted[y] == 0 && faceSorted2[y] != 0)
					{
						result[1] = 1; flag = false; break;
					}
					else if (faceSorted2[y] == 0 && faceSorted[y] != 0)
					{
						result[2] = 1; flag = false; break;
					}
				}
			if (flag == true)
				result[0] = 1;
			cout << "Round Over\n" << endl;
		}
		switch (comboPlayer1)
		{
		case Pair:
		case Three:
		case Care:
		{
			int max1, max2;
			for (int i = 1; i < 5; i++)
			{
				if (faceSorted[i - 1] == faceSorted[i])
					max1 = faceSorted[i];
				if (faceSorted2[i - 1] == faceSorted2[i])
					max2 = faceSorted2[i];
			}
			if (max1 == 0)
				max1 = 13;
			if (max2 == 0)
				max2 = 13;
			if (max1 != max2)
				max1 > max2 ? result[1]=1 : result[2] = 1;
			else
				goto SearchMaxCard;
			break;
		}
		case TwoPair:
		{
			int max1, max2, max11, max22; //For save repeat numbers
			for (int i = 1, j = 4; i < j; i++, j--)
			{
				if (faceSorted[i - 1] == faceSorted[i])
					max1 = faceSorted[i];
				if (faceSorted[j - 1] == faceSorted[j])
					max11 = faceSorted[j];
				if (faceSorted2[i - 1] == faceSorted2[i])
					max2 = faceSorted2[i];
				if (faceSorted2[j - 1] == faceSorted2[j])
					max22 = faceSorted2[j];
			}

			if (max1 == 0)
			{
				max1 = max11;
				max11 = 13;
			}
			if (max2 == 0)
			{
				max2 = max22;
				max22 = 13;
			}
			if (max11 != max22)
				max11 < max22 ? result[2]=1 : result[1] = 1;

			else if (max1 != max2)
				max1 < max2 ? result[2] = 1 : result[1] = 1;
			else
				goto SearchMaxCard;
			break;
		}/*{0,0,1,1,1}{2,2,2,4,4}*/
		case Street:
		{
			int max1 = faceSorted[4];
			int max2 = faceSorted2[4];

			if (faceSorted[0] == 0 && faceSorted[1] == 9)
				max1 = 13;
			if (faceSorted2[0] == 0 && faceSorted2[1] == 9)
				max2 = 13;
			if (max1 != max2)
				max1 > max2 ? cout << "Player 1 win!" : cout << "Player 2 win!";
			else
				cout << "Draw!\n";
			break;
		}
		case Full_Haus:
		{
			int max1; int max13;
			int max2; int max23;
			if (faceSorted[2] == faceSorted[0]) //search Three in Full_Haus
			{
				faceSorted[0] == 0 ? max13 = 13 : max13 = faceSorted[0];
				max1 = faceSorted[4];
			}
			else
			{
				max13 = faceSorted[4];
				faceSorted[0] == 0 ? max1 = 13 : max1 = faceSorted[0];
			}
			if (faceSorted2[2] == faceSorted2[0]) //search Three in Full_Haus for 2player
			{
				faceSorted2[0] == 0 ? max23 = 13 : max23 = faceSorted2[0];
				max2 = faceSorted2[4];
			}
			else
			{
				max23 = faceSorted2[4];
				faceSorted2[0] == 0 ? max2 = 13 : max2 = faceSorted2[0];
			}
			if (max13 != max23)
				max13 < max23 ? result[2] = 1 : result[1] = 1;

			else if (max1 != max2)
				max1 < max2 ? result[2] = 1 : result[1] = 1;
			else
				result[0] = 1;
		}
		}
	}
}
void DeckOfCards::roundResult()
{
	if (result[2] == 1)
		cout << endl << "Dieler win!\n";
	else if (result[1] == 1)
		cout << endl << "Player 1 win!\n";
	else
		cout << "Draw!\n";
}

