#include<iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
using std::swap;

//void partition(vector <int> &, int, int);
void quickSort(vector <int> &, int, int);

int main()
{
	vector<int> unsortArr { 12,10,8,45,2,2,3,5,7,13 };
	for (auto i : unsortArr)
		cout << i << " ";
	cout << endl;
	quickSort(unsortArr, 0, unsortArr.size() - 1);
	for (auto i : unsortArr)
		cout << i << " ";
	cout << endl;
	return 0;
}
void quickSort(vector<int>&arr1, int b0, int e0)
{
	int b = b0; int e = e0;
	auto d = arr1[e];
	do
	{
		while (arr1[b] < d)
			++b;
		while (arr1[e] > d)
			e--;
		if (b <= e)
		{
			swap(arr1[b], arr1[e]);
			++b; --e;
		}
	} while (b <= e);

	if (e > b0)
		quickSort(arr1, b0, e);
	if (b < e0)
		quickSort(arr1,b, e0);
}