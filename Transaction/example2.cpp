#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

enum RequestType
{
	ZERO_BALANCE = 1,
	CREDIT_BALANCE,
	DEBIT_BALANCE,
	END
};


int getRequest();
bool shouldDisplay(int, double);
void outputLine(int, const string, double);


int main()
{
	ifstream inClientFile("clients.dat",ios::in);
	if(!inClientFile){
		cerr << "File could not be opened " << endl;
		exit(1);
	}

	int request;
	int account;
	string name;
	double balance;

	// get user's request (e.g. zero , credit, or debit balance)
	request = getRequest();

	// process user's request
	while(request != END)
	{

		switch(request)
		{
			case ZERO_BALANCE:
				cout << "\nAccounts with zero balances:\n";
				break;
			case CREDIT_BALANCE:
				cout << "\nAccounts with credit balances:\n";
				break;
			case DEBIT_BALANCE:
				cout << "\nAccounts with debit balances:\n";
				break;
		}
		// read account , name , and balance from file
		inClientFile >> account >> name >> balance;

		// display file contents (until eof)
		while(!inClientFile.eof())
		{
			// display record //
			if(shouldDisplay(request,balance))
				outputLine(account,name,balance);
			// read account, name and balance from file
			inClientFile >> account >> name >> balance;
		}

		inClientFile.clear(); // reset eof for next input //
		inClientFile.seekg(0); // reposition to beginning of file //

		request = getRequest(); // get additional request from user //

	}

	cout << "End of run. " << endl;

}


int getRequest()
{
	int request;

	cout << "\nEnter request" << endl
	<< "1 - List accounts with zero balances" << endl
	<< "2 - List accounts with credit balances" << endl
	<< "3 - List accounts with debit balances" << endl
	<< "4 - End of run" << fixed << showpoint;

	do 
	{
		cout << "\n";
		cin >> request;
	}while(request < ZERO_BALANCE && request > END);

	return request;
}


bool shouldDisplay(int type, double balance)
{
	if(type == ZERO_BALANCE && balance == 0)
		return true;

	if(type == CREDIT_BALANCE && balance < 0)
		return true;

	if(type == DEBIT_BALANCE && balance > 0)
		return true;

	return false;
}


void outputLine(int account, const string name, double balance)
{
	cout << left << setw(10) << account << setw(13) << name 
	<< setw(7) << setprecision(2) << right << balance << endl;
}