#pragma once
#include <vector>
using std::vector;

class MergeSort
{
public:
	MergeSort(int);
	void sort();
	void displayElements()const;
private:
	int size;
	vector<int>data;
	void sortSubVector(int, int);
	void merge(int, int, int,int);
	void dispaySubVector(int, int)const;
};
