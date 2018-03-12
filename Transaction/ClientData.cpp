#include <string>
#include "ClientData.h"
using namespace std;


//default ClientData constructor
ClientData::ClientData(int accountNumberValue,
	string lastNameValue, string firstNameValue, double balanceValue)
{
	setAccountNumber(accountNumberValue);
	setLastName(lastNameValue);
	setFirstName(firstNameValue);
	setBalance(balanceValue);
}


// get account-number value
int ClientData::getAccountNumber() const
{
	
}