#include <string>
using std::string;

#include "ClientData.h"

ClientData::ClientData(int accountNumberValue,
	string lastNameValue, string firstNameValue,
	double balanceValue)
{
	setAccountNumber(accountNumberValue);
	setLastName(lastNameValue);
	setFirstName(firstNameValue);
	setBalance(balanceValue);
}
int ClientData::getAccountNumber()const
{
	return accountNumber;
}

void ClientData::setAccountNumber(int accountNumberValue)
{
	accountNumber = accountNumberValue;
}

string ClientData::getLastName()const
{
	return lastName;
}

void ClientData::setLastName(string lastNameString)
{
	const char *lastNameValue = lastNameString.data();
	int length = lastNameString.size();
	length = (length < 15) ? length : 14;
	strncpy(lastName, lastNameValue, length);
	lastName[length] = '\0';
}

string ClientData::getFirstName()const
{
	return firstName;
}
void ClientData::setFirstName(string firstNameString)
{
	const char *firstNameValue = firstNameString.data();
	int length = firstNameString.size();
	length = (length < 10) ? length : 9;
	strncpy(firstName, firstNameValue, length);
	firstName[length] = '\0';
}
double ClientData::getBalance()const
{
	return balance;
}
void ClientData::setBalance(double balanceValue)
{
	balance = balanceValue;
}