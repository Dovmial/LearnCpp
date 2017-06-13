#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int linearSearch(int[], int, int);
const int arraySize = 100;
int main()
{
	// размер массива а 
	int a[arraySize]; // создать массив а 
	int searchKey; // значение дл€ поиска в массиве а 

	for (int i = 0; i < arraySize; i++)
		a[i] = 2 * i;// создать некоторые данные 

	cout << "Enter integer search key: ";
	cin >> searchKey;

	// попытка поиска searchKey в массиве а 
	int element = linearSearch(a, arraySize,searchKey);
	for (int i = 0; i < arraySize; i++)
		cout << a[i]<<" ";
	cout << endl;
	// вывести результаты 
	if (element != -1)
		cout << "Found value in element " << element << endl;
	else
		cout << "Value not found" << endl;

	return 0; // успешное 
}

int linearSearch(int arr1[], int arrSz, int key)
{
	if (arrSz == 0)
		return -1;
	else if (arr1[arrSz - 1] != key)
		linearSearch(arr1, arrSz - 1, key);
	// возвратить позицию ключа 
	else
		return arrSz-1;
} // конец функции linearSearch 
