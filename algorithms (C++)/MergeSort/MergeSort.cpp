#include<iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib>
using std::rand;
using std::srand;

#include<ctime>
using std::time;

#include "mergeSort.h"

MergeSort::MergeSort(int vectorSize)
{
	size = (vectorSize > 0?vectorSize:10);
	srand(time(0));
	for (int i = 0; i < size; i++)
		data.push_back(10 + rand() % 90);
}
void MergeSort::sort()
{
	sortSubVector(0,size - 1);
}
void MergeSort::sortSubVector(int low, int high)
{
	if ((high - low) >= 1)
	{
		int middle1 = (low + high) / 2;
		int middle2 = middle1 + 1;

		cout << "split:   ";
		dispaySubVector(low, high);
		cout << endl << "         ";
		dispaySubVector(low, middle1);
		cout << endl << "         ";
		dispaySubVector(middle2, high);
		cout << endl<<endl;

		//recurs
		sortSubVector(low, middle1);
		sortSubVector(middle2, high);

		merge(low, middle1, middle2, high);
	}
}

void MergeSort::merge(int left, int middle1, int middle2, int right)
{
	int leftIndex = left;
	int rightIndex = middle2;
	int combinedIndex = left;
	vector<int>combined(size);

	cout << "merge:   ";
	dispaySubVector(left, middle1);
	cout << endl << "         ";
	dispaySubVector(middle2, right);
	cout << endl;
	while (leftIndex <= middle1 && rightIndex <= right)
	{
		if (data[leftIndex] <= data[rightIndex])
			combined[combinedIndex++] = data[leftIndex++];
		else
			combined[combinedIndex++] = data[rightIndex++];
	}
	if (leftIndex == middle2)
	{
		while (rightIndex <= right)
			combined[combinedIndex++] = data[rightIndex++];
	}
	else
	{
		while (leftIndex <= middle1)
			combined[combinedIndex++] = data[leftIndex++];
	}
	for (int i = left; i <= right; i++)
		data[i] = combined[i];
	cout << "         ";
	dispaySubVector(left, right);
	cout << endl << endl;
}

void MergeSort::displayElements()const
{
	dispaySubVector(0, size - 1);
}

void MergeSort::dispaySubVector(int low, int high)const
{
	for (int i = 0; i < low; i++)
		cout << "   ";
	for (int i = low; i <= high; i++)
		cout << " " << data[i];
}