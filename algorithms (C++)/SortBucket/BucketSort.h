#pragma once
#include <vector>
using std::vector;

class BucketSort
{
public:
	BucketSort(int);
	void sort();
	void display()const;
private:
	vector<int>data;
};

