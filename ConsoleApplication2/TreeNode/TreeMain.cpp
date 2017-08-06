#include<iostream>
using std::cout;
using std::cin;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Tree.h"
int main()
{
	Tree<int>intTree;
	int intValue;
	cout << "Enter 10 integer values:\n";
	for (int i = 0; i < 10; ++i)
	{
		cin >> intValue;
		intTree.insertNode(intValue);
	}
	cout << "\npreOrder traversal\n";
	intTree.preOrderTraversal();

	cout << "\ninorder traversal\n";
	intTree.inOrderTraversal();

	cout << "\npostorder traversal\n";
	intTree.postOrderTraversal();

	Tree<double>doubleTree;
	double doubleValue;

	cout << fixed << setprecision(1)
		<< "\n\nEnter 10 double values: \n";
	for (int j = 0; j < 10; j++)
	{
		cin >> doubleValue;
		doubleTree.insertNode(doubleValue);
	}
	cout << "\nPreorder traversal\n";
	doubleTree.preOrderTraversal();

	cout << "\ninorder traversal\n";
	doubleTree.inOrderTraversal();

	cout << "\npostorder traversal\n";
	doubleTree.postOrderTraversal();

	cout << endl;
	return 0;
}