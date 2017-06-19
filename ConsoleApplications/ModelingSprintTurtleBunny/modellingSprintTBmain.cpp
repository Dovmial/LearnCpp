
#include<iostream>
#include<random>
#include<ctime>


using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;


int HareStep();
int TurtleStep();

int main()
{
	srand(unsigned(time(0)));
	char path[71]; int count = 1;
	int hareWin = 0; int turtleWin = 0;
	for (int j = 1; j <= 20; j++)
	{
		for (int i = 0; i <= 70; i++)
			path[i] = ' ';
		int turtle = 1; int hare = 1;
		bool flag = true;
		cout << endl << j << "-th BANG!!!!\nAND THR'RE OFF!!!!!\n\n";
		while ((turtle < 70 || hare < 70) && flag)
		{
			turtle += TurtleStep();
			hare += HareStep();
			if (turtle < 1)
				turtle = 1;
			if (hare < 1)
				hare = 1;
			if (turtle >= 70 && hare < 70)
			{
				cout << "TORTOISE WINS!!! YAY!!!\n"; flag = false; turtleWin++;
			}
			else if (hare >= 70 && turtle < 70)
			{
				cout << "Hare wins. Yuch\n"; flag = false; hareWin++;
			}
			else if (hare >= 70 && turtle >= 70)
			{
				cout << "DRAW!!!\n"; flag = false;
			}
			else if (turtle == hare && hare < 70)
			{
				for (int i = 1; i < hare; i++)
					cout << path[i];
				cout << "OUCH!!!";
				for (int i = hare; i < 64; i++)
					cout << path[i];
			}
			else
			{
				*(path + hare) = 'H';
				*(path + turtle) = 'T';
				for (int i = 1; i < 71; i++)
					cout << path[i];
			}
			if (hare < 70 && turtle < 70)
			{
				//cout << "|" << endl;
				*(path + hare) = ' ';
				*(path + turtle) = ' ';
			}
			if (flag)
				cout << '|' << count++ << endl;
		}
	}
	cout << "\n  Hare   Tortoise\n";
	cout  << "   "<<hareWin << "  :  " << turtleWin << endl;
	if (hareWin != turtleWin)
		hareWin > turtleWin ? cout << "Hare our Champion!!\n" : cout << "TORTOISE OUR CHAMPION!!!!!\n";
	else
		cout << "DRAW!!!!!\n";
	
	return 0;
}
int TurtleStep()
{
	int step = rand() % 10 + 1;
	if (step <= 5)
		return 3;
	else if (step <= 7)
		return -6;
	else
		return 1;
}
int HareStep()
{
	int step = rand() % 10 + 1;
	if (step <= 2)
		return 0;
	else if (step <= 4)
		return 9;
	else if (step == 5)
		return -12;
	else if (step <= 8)
		return 1;
	else
		return -2;
}