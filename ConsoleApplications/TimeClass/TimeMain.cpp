#include<iostream>
using std::cout;
using std::endl;
#include "Time.h"


int main()
{
	Time t;
	//каскадные вызовы
	t.setHour(18).setMinute(30).setSecond(22);
	cout << "Universal time: ";
	t.printUniversal();
	cout << "\nStandart time: ";
	t.printStandard();
	cout << endl;
	t.setTime(20, 20, 20).printStandard();
	cout << endl;
	return 0;
}