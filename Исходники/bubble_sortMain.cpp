// bubble_sortMain.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	const int sizeAr=10;
	int n[sizeAr]={1,3,52,4,8,36,372,38,39,490};
	int midd=0;
	int c=0;
	bool flag;
	for(int i=sizeAr;i>0;i--)
	{		
		flag=true;
		for(int y=1;y<i;y++)
		{
			/*for(int i=0;i<sizeAr;i++)
				cout<<n[i]<<"  ";*/
			
			if(n[y]<n[y-1])
			{
				midd=n[y-1];
				n[y-1]=n[y];
				n[y]=midd;
				flag = false;
			}
		}
		/*cout<<++c<<"th prohod   i="<<i<<endl;*/
		if (flag)
		{/*cout<<"\nExit X\n";*/
		break;}
	}
	cout<<"After bubble_sorting:"<<endl;
	for(int i=0;i<sizeAr;i++)
		cout<<n[i]<<endl;
	return 0;
}

