#include "NormalAccount.h"
NormalAccount::NormalAccount(String username, String password, String IBAN, size_t id, double money, time_t date) :Account(username, password, IBAN, id, money, date) {}

void NormalAccount::deposit(double amount) {
	this->amount += amount;
}
bool NormalAccount::withdraw(double amount) {
	if (this->amount < amount) {
		return false;
	}
	this->amount -= amount;
	return true;
}
void NormalAccount::display() {
	std::cout << "normal account ";
	Account::display();
	std::cout << std::endl;
}
Account* NormalAccount::clone()const {
	return new NormalAccount(*this);
}