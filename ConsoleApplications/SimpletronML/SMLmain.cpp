#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include "SMLheader.h"
#include<iomanip>
using std::setw;
#include <cmath>

void showStart();
int main()
{/*
 Example command word:
 +4300     43: address of command
		   00: address of operand
 */
	int memory[100] = { 0 };
	bool flag = true;
	int accumulator=0;
	int instructionCounter=0; //address next command
	int instructionRegistr=0;
	int operationCode;
	int operand=0;

	showStart();

	while (operand<100)
	{
		if (operand<10)
			cout <<'0'<< operand <<"? ";
		else
			cout << operand << "? ";
		cin >> memory[operand];
		
		if (memory[operand] == -99999)
		{
			memory[operand] = 0;
			break;
		}
		else if (memory[operand] > 9999 && memory[operand] < -9999)
		{
			cout << "\nout of range!\n";
			continue;
		}
		operand++;
	}
	operand = 0;
	cout << "\nStart PROGRAMM\n";

	while (flag)
	{
		instructionRegistr = memory[instructionCounter];
		operationCode = instructionRegistr / 100;
		operand = instructionRegistr % 100;
		
		switch (operationCode)
		{
		case READ: {cout << '?'; cin >> memory[operand]; break; }
		case WRITE: {cout << "\nResult: " << memory[operand] << endl; break; }
		case LOAD: {accumulator = memory[operand]; break; }
		case STORE: {memory[operand] = accumulator; break; }
		case ADD: 
		{
			accumulator += memory[operand];
			if (accumulator > 9999 || accumulator < -9999)
			{
				cout << "Fatal ERROR. out range memory."; flag = false;
			}
			break;
		}
		case SUBSTRUCT: 
		{
			accumulator -= memory[operand]; 
			if (accumulator > 9999 && accumulator < -9999)
			{
				cout << "Fatal ERROR. out range memory."; flag = false;
			}
			break;
		}
		case DIVINE: 
		{
			if (memory[operand] != 0)
				accumulator /= memory[operand];
			else
				cout << "Fatal ERROR. divine by null\n";
			break;
		}
		case MULTIPLY: 
		{
			accumulator *= memory[operand];
			if (accumulator > 9999 || accumulator < -9999)
			{
				cout << "Fatal ERROR. out range memory."; flag = false;
			}
			break; 
		}
		case BRANCH: {instructionCounter = operand-1; break; }
		case BRANCHNEG: {
			if(accumulator<0)
				instructionCounter = operand-1;
			break;
		}
		case BRANCHZERO: {if(accumulator == 0)instructionCounter = operand-1; break; }
		case HALT: {cout << "***  Calculation is finished\t\t***\n"; flag = false; break; }
		}
		++instructionCounter;
	}
	//Dumps of memorycout << "\n" << "accumulator\t\t" << accumulator;
	cout << "\nREGISTERS:" << endl
		<< "accumulator\t\t" << accumulator << endl << "instructionCounter\t" << instructionCounter << endl;
	cout << "instructionRegistr\t" << instructionRegistr << endl;
	cout << "operationCode\t\t" << operationCode;
	cout << "\noperand\t\t\t" << operand << endl;
	cout << "\nMEMORY:\n";
	cout << "   ";
	for (int i = 0; i < 10; i++)
		cout << setw(5) << i << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout <<setw(2)<< i * 10 << " ";
		for (int j = i*10; j < i * 10+10; j++)
		{
			
			if (memory[j] >= 0)
				cout << '+' << setw(4)<<std::setfill('0') << memory[j] << ' ';
			else
				cout << '-'<<setw(4) << std::setfill('0') <<std::abs( memory[j]) << ' ';
		}
		cout << endl;
	}
}
void showStart()
{
	cout << "***\tWelcome to simpletron!\t***\n";
	cout << "***   Please, enter your programm\t***\n";
	cout << "***   current address: ()?.Entered\t***\n"
		<< "***   word will save in current\t\t***\n"
		<< "***   address. For finish entering\t***\n";
	cout << "***   programm input number -99999.\t***\n";
}