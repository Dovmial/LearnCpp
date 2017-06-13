#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;

//const int ArrSize = 12; ��� ����������
//void selectionSort(int[], int);
//int main()
//{
//	//�������� ������
//	int arr1[ArrSize] = { 12,13,3,4,0,123,8,9,1,26,6 };
//	//����� �� ������ �������
//	for (int i = 0; i < ArrSize; i++)
//		cout << arr1[i] << " ";
//	cout << endl << "After Sorting:\n";
//	selectionSort(arr1, ArrSize);     //���������� ����������� ��������
//	//������ ������� ����� ����������
//	for (int i = 0; i < ArrSize; i++)
//		cout << arr1[i] << " ";
//	cout << endl;
//	return 0;
//}
////����� ����������
//void selectionSort(int arr2[], int arrSz)
//{
//	int min; 
//	int y; //������ ������������ ��������
//	min = arr2[ArrSize - arrSz];
//	y = ArrSize - arrSz;
//	//����� ������������ �������� � ������� � ��� ��������������
//	for (int i = ArrSize - arrSz + 1; i < ArrSize; i++)
//	{
//		if (min > arr2[i])
//		{
//			min = arr2[i];
//			y = i;
//		}
//	}
//	//���������� ������������ �������� �� ���� �����(����� �������)
//	if (arr2[ArrSize - arrSz] != arr2[y])
//	{
//		min = arr2[ArrSize - arrSz];
//		arr2[ArrSize - arrSz] = arr2[y];
//		arr2[y] = min;
//	}
//	//����������� ����� ������� ��� ����������
//	if (arrSz != 1)   
//		selectionSort(arr2, arrSz - 1);
//} 

//������� ����� ���������

void selectionSort(int * const, const int);
void swap(int * const, int * const);

int main()
{
	const int arraySize = 10;
	int a[arraySize] = { 2,6,4,8,10,12,89,68,45,37 };
	cout << "Data items in orginal order\n";
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];
	selectionSort(a, arraySize); // ����������
	cout << "\nData items in ascending order\n";
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];
	cout << endl;
	return 0;
}
void selectionSort(int *const arr1, const int size)
{
	int smallest;
	for (int i = 0; i < size-1; i++)
	{
		smallest = i;
		for (int index = i + 1; index < size; index++)
			if (arr1[index] < arr1[smallest])
				smallest = index;
		swap(&arr1[i], &arr1[smallest]);
	}
}

void swap(int * const element1Ptr, int * const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}
