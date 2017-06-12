#include<iostream>
using std::cout;
using std::endl;
const int ArrSize = 12;

void selectionSort(int[], int);
int main()
{
	//тестовый массив
	int arr1[ArrSize] = { 12,13,3,4,0,123,8,9,1,26,6 };
	//вывод на печать массива
	for (int i = 0; i < ArrSize; i++)
		cout << arr1[i] << " ";
	cout << endl << "After Sorting:\n";
	selectionSort(arr1, ArrSize);     //сортировка рекурсивная выборкой
	//печать массива после сортировки
	for (int i = 0; i < ArrSize; i++)
		cout << arr1[i] << " ";
	cout << endl;
	return 0;
}
//метод сортировки
void selectionSort(int arr2[], int arrSz)
{
	int min; 
	int y; //индекс минимального значения
	min = arr2[ArrSize - arrSz];
	y = ArrSize - arrSz;
	//поиск минимального значения в массиве и его местоположения
	for (int i = ArrSize - arrSz + 1; i < ArrSize; i++)
	{
		if (min > arr2[i])
		{
			min = arr2[i];
			y = i;
		}
	}
	//постановка минимального значения на свое место(обмен местами)
	if (arr2[ArrSize - arrSz] != arr2[y])
	{
		min = arr2[ArrSize - arrSz];
		arr2[ArrSize - arrSz] = arr2[y];
		arr2[y] = min;
	}
	//рекурсивный вызов функции для подмассива
	if (arrSz != 1)   
		selectionSort(arr2, arrSz - 1);
}