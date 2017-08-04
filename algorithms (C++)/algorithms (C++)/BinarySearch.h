#pragma once
#include <vector>;
using std::vector;

class BinarySearch
{
public:
	BinarySearch(int);
	int  binarySearch(int) const;
	void displayElements()const;
private:
	int size;
	vector<int> data;
	void dispaySubElements(int,int)const; //вывести диапазон
};