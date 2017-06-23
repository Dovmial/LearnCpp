#include<iostream>
using std::cout;
using std::endl;
#include "Time.h"


int main()
{
	Time t1(0);
	Time t2(2);
	Time t3(21, 34);
	Time t4(12, 25, 42);
	Time t5(27, 74, 99);
	Time t6;
	cout << "Constructed with:\n\nt1: all arguments defaulted\n";
	t1.printUniversal();
	cout << endl; t1.printStandard();
	cout << "\n\nt2: hour specified; minute and second defaulted\n";
	t2.printUniversal();
	cout << endl; t2.printStandard();
	cout << "\n\nt3: hour and minute specified; second defaulted\n";
	t3.printUniversal();
	cout << endl; t3.printStandard();
	cout << "\n\nt4: hour and minute second specified\n";
	t4.printUniversal();
	cout << endl; t4.printStandard();
	cout << "\n\nt5: all invalid values specified\n";
	t5.printUniversal();
	cout << endl; t5.printStandard();
	cout << endl;
	cout << "\n\nt6: Current Time: "; t6.printStandard();
	cout << endl;
	return 0;
}