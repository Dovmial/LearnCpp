// Resheto-Eratosphena.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include<iostream>
using std::cout;
using std::endl;
const int arrSize = 1000;

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	int arrayErat[arrSize];
	//���������� ���������(1- ������)
	for (int i=1; i<arrSize; i++)
		arrayErat[i]=1;
	//����� ������� �������� (0 - ����)
	for(int i=2; i<arrSize; i++)
		if(arrayErat[i]==1)
			for(int j=i*2;j<arrSize;j+=i)
				arrayErat[j]=0;
	//������
	for(int i=1;i<arrSize;i++)
	{
		if(arrayErat[i]==1)
		{
			cout<<i<<" ";
			count++;
			if (count%10==0)
				cout<<endl;
		}
		
	}
	cout<<endl;
	return 0;
}

