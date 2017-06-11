// Block_Sorting.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

const int ArrSize = 9;
void bucketSort(int []);

int _tmain(int argc, _TCHAR* argv[])
{
	int exAr[ArrSize]={5,105,125,5,5985,10255,855};
	cout<<"\nMain Array before sort:"<<endl;
	for(int i=0;i<ArrSize;i++)
		cout<<exAr[i]<<" ";
	cout<<endl;
	bucketSort(exAr);
	cout<<"\nMain Array after sort:"<<endl;
	for(int i=0;i<ArrSize;i++)
		cout<<exAr[i]<<" ";
	cout<<endl;
	return 0;
}

void bucketSort(int arr1[])
{
	int blockArr[10][ArrSize+1]={0};
	int razr;//разряд
	int k=0;
	//подсчет количесва нулей в массиве
	for(int i=0;i<ArrSize;i++)
		if(arr1[i]==0)
			k++;
	int countNull=k;
	int R=1;//для вытаскивания разряда
	int max=0; //поиск максимального значения в массиве
	//для определения количесва проходов.
	for(int i=0; i<ArrSize;i++)
		if(max<arr1[i])
			max=arr1[i];
	//заполнение 2d  массива для сортировки поразрядной
	while(true) 
	{
		for(int i=0;i<ArrSize;i++)
		{
			int j=0;
			razr = arr1[i]%(10*R)/R;
			if (blockArr[razr][j] == 0)
				blockArr[razr][j] = arr1[i];
			else
			{
				while (blockArr[razr][j] != 0)
					j++;
				blockArr[razr][j]=arr1[i];
			}
		}
		//Обратная сборка массива
		for(int i=0;i<10;i++)
			for (int j=0;j<ArrSize;j++)
			{
				if(blockArr[i][j] != 0)
					arr1[k++]=blockArr[i][j];
		//обнуление 2D массива
				blockArr[i][j] = 0;
				if (i<countNull)
					arr1[i]=0;
			}
		R*=10;
		if(max<R)
			break;
		k=countNull;
	}

}