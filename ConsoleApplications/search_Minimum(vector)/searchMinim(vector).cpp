#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int recursiveMinimum(vector<int>&);

int main()
{

	vector<int> Arr2{ 12,526,8,9,35,6,56,14,85,36,256 };
	for (size_t i = 0; i < Arr2.size(); i++)
	{
		cout << Arr2[i] << " ";
	}
	cout << endl;
	int minim = recursiveMinimum(Arr2);
	cout << "min = " << minim << endl;
	return 0;
}
int recursiveMinimum(vector<int> &arr1)
{
	static int min = arr1.front();
	if (!arr1.empty())
	{
		if(arr1.back() < min )
			min = arr1.back();
		arr1.pop_back();
		return recursiveMinimum(arr1);
	}
	else
		return min;
}