#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::vector;
using std::rand;
using std::srand;
using std::time;

void bubbleSort(vector <int>&);
void display(vector<int>&);

int main()
{
	const int Size=10;
	vector <int> vectX;
	srand(unsigned int(time(0)));
	
	for (size_t i = 0; i < Size; i++)
		vectX.push_back(30 + rand() % 50);
	cout << "\tBefore sorting: ";
	display(vectX);
	bubbleSort(vectX);
	cout << "After sorting: ";
	display(vectX);
	return 0;
}
void bubbleSort(vector <int>&arr1)
{
	int swapSort; int n = 0;
	for (size_t i = arr1.size() - 1; i > 0; i--)
	{
		swapSort = -1;
		for (size_t j = 0; j < i; j++)
		{
			if (arr1[j + 1] < arr1[j])
			{
				swapSort = arr1[j + 1];
				arr1[j + 1] = arr1[j];
				arr1[j] = swapSort;
			}
		}
		if (swapSort == -1)
			break;
	}
}
void display(vector<int>& array1)
{
	for (size_t i = 0; i < array1.size();i++)
		cout << array1.at(i) << " ";
	cout << endl;
}