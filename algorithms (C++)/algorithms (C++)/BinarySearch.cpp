#include <iostream>
using std::cout;
using std::endl;

#include<cstdlib>
using std::rand;
using std::srand;
#include <ctime>
using std::time;

#include<algorithm>
#include "BinarySearch.h"

BinarySearch::BinarySearch(int vectorSize)
{
	size = (vectorSize > 0 ? vectorSize : 10);
	srand(unsigned int(time(0)));

	for (int i = 0; i < size; i++)
		data.push_back(10 + rand() % 90); //10-99
	std::sort(data.begin(), data.end());
}

int BinarySearch::binarySearch(int searchElement)const
{
	int low = 0;
	int high = size - 1;
	int middle = (low + high + 1) / 2;
	int location = -1;//если не найдено
	do
	{
		dispaySubElements(low, high);
		for (int i = 0; i < middle; i++)
			cout << "   ";
		cout << " * " << endl;//current middle
		if (searchElement == data[middle])
			location = middle;
		else if (searchElement < data[middle])
			high = middle - 1;
		else
			low = middle + 1;
		middle = (low + high + 1) / 2;
	} while ((low <= high) && (location == -1));
	return location;
}

void BinarySearch::displayElements()const
{
	dispaySubElements(0, size - 1);
}

void BinarySearch::dispaySubElements(int low, int high)const
{
	for (int i = 0; i < low; i++)
		cout << "   ";
	for (int i = low; i <= high; i++)
		cout << data[i]<<" ";
	cout << endl;
}