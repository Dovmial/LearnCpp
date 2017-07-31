#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
using std::cin;

#include<string>
using std::string;

void printStatistics(const string &stringref);
int main()
{
	string string1("cat");
	string string2;
	string string3;
	string2 = string1;
	string3.assign(string1); //присваивание
	cout << "string1: " << string1 << "\nstring2: "
		<< string2 << "\nstring 3: " << string3 << "\n\n";

	string2[0] = string3[2] = 'r';
	cout << "After modification of string2 and string3:\n"
		<< "string1: " << string1 << "\nstring2: "
		<< string2 << "\nstring3: ";
	for (int i = 0; i < string3.length(); i++)
		cout << string3.at(i);
	string string4(string1 + "apult");
	string string5;
	string3 += "pet";
	string1.append("acomb");
	string5.append(string1, 4, string5.length() - 4);

	cout << "\n\nAfter concatenation:\nstring1: " << string1
		<< "\nstring2: " << string2 << "\nstring3: " << string3
		<< "\nstring4: " << string4 << "\nstring5: " << string5 << endl;

	string1 = "The airplane landed on time.";
	cout << string1.substr(7, 5) << endl;
	string1.swap(string2);
	cout << "string1: "<<string1 << endl;
	cout << "string2: " << string2 << endl;

	//statistics
	string1.clear();
	cout << "Statistic before input:\n" << boolalpha;
	printStatistics(string1);

	cout << "\n\nEnter a string: ";
	cin >> string1;
	cout << "The string entered was: " << string1;
	cout << "\nStatistics after input:\n";
	printStatistics(string1);
	cin >> string1;
	cout << "\n\nThe remaining string is: " << string1 << endl;
	printStatistics(string1);
	string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
	cout << "\n\nstring1 is now: " << string1 << endl;
	printStatistics(string1);
	string1.resize(string1.length() + 10);
	cout << "\n\nStats after resizing by (length +10):\n";
	printStatistics(string1);
	cout << endl;
	//поиск
	string1 = "noon is 12 pm; midnight is not.\n";
	int location;
	cout << "Original string:\n" << string1
		<< "\n\n(find)\"is\" was found at: " << string1.find("is")
		<< "\n(rfind) \"is\" was found at: " << string1.rfind("is");

	location = string1.find_first_of("misop");
	cout << "\n\n(find_first_of) found '" << string1[location]
		<< "' from the group \"misop\" at: " << location;

	location = string1.find_last_not_of("misop");
	cout << "\n\n(find_last_of) found '" << string1[location]
		<< "' from the group \"misop\" at: " << location;

	location = string1.find_first_not_of("noi spm");
	cout << "\n\n(find_fist_not_of) '" << string1[location]
		<< "' is not contained in \"noi spm\" and was foound at: "
		<< location;

	location = string1.find_first_not_of("12noi spm");
	cout << "\n\n(find_first_not_of) '" << string1[location]
		<< "' is not contained in \"12noi spm\" and was "
		<< "found at: " << location << endl;

	location = string1.find_first_not_of(
		"noon is 12 pm; midnight is not.");
	cout << "\nfind_first_not_of(\"noon is 12 pm; midnight is not.\")"
		<< " returned: " << location << endl;
	return 0;
}
void printStatistics(const string &stringref)
{
	cout << "capacity: " << stringref.capacity()
		<< "\nmax size: " << stringref.max_size() << "\nsize: " << stringref.size()
		<< "\nlength: "<<stringref.length()
		<< "\nempty: "<<stringref.empty();
}