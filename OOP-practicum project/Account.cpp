#include "Account.h"
# pragma warning(disable:4996)
Account::Account(String username, String password, String IBAN, size_t id, double money, time_t date) {
	this->username = username;
	this->password = password;
	this->IBAN = IBAN;
	this->id = id;
	this->amount = money;
	this->dateOfCreation = date;
}
void Account::display() {
	std::cout << "IBAN: " << IBAN << " " << "  amount: " << amount << " date of creation: " << ctime(&dateOfCreation);
}
size_t Account::getId()const {
	return id;
}
String Account::getIBAN()const {
	return IBAN;
}
double Account::getBalance()const {
	return amount;
}