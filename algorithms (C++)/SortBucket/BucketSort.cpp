#include "BucketSort.h"
#include <iostream>
#include<cstdlib>
#include<ctime>

using std::rand;
using std::srand;
using std::time;

BucketSort::BucketSort(int vectorSize)
{
	int size = (vectorSize > 0 ? vectorSize : 10);
	srand(unsigned int(time(0)));
	for (int i = 0; i < size; ++i)
		data.push_back(rand() % 200);
}

void BucketSort::sort()
{
	
	int max = data.at(0);
	int r=1; // разряд
	int j=0;
	int n=0;
	//search maximum
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (max < data.at(i))
			max = data.at(i);
	}
	while (max >= r)
	{
		vector<vector <int>>bucket(10);
		for (size_t i = 0; i < data.size(); ++i)
		{
			j = (data.at(i) / r) % 10;
			bucket.at(j).push_back(data.at(i));
		}
		data.clear();
		for (int i = 0; i < 10; i++)
			for (size_t j = 0; j < bucket.at(i).size(); j++)
				data.push_back(bucket.at(i).at(j));
		r *= 10;
	}
}

void BucketSort::display()const
{
	for (int i = 0; i < data.size(); i++)
		std::cout << data.at(i) << ' ';
	std::cout << std::endl;
}
