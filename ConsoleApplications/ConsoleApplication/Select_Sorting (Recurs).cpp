#include<iostream>
using std::cout;
using std::endl;
const int ArrSize = 12;
void selectionSort(int[], int);
int main()
{

	int arr1[ArrSize] = { 12,13,3,4,0,123,8,9,1,26,6 };

	for (int i = 0; i < ArrSize; i++)
		cout << arr1[i] << " ";
	cout << endl << "After Sorting:\n";
	selectionSort(arr1, ArrSize);
	for (int i = 0; i < ArrSize; i++)
		cout << arr1[i] << " ";
	cout << endl;
	return 0;
}
void selectionSort(int arr2[], int arrSz)
{
	int min; int y;
	min = arr2[ArrSize - arrSz];
	y = ArrSize - arrSz;
	for (int i = ArrSize - arrSz + 1; i < ArrSize; i++)
	{
		if (min > arr2[i])
		{
			min = arr2[i];
			y = i;
		}
	}
	if (arr2[ArrSize - arrSz] != arr2[y])
	{
		min = arr2[ArrSize - arrSz];
		arr2[ArrSize - arrSz] = arr2[y];
		arr2[y] = min;
	}
	if (arrSz!=1)
		selectionSort(arr2, arrSz - 1);
}