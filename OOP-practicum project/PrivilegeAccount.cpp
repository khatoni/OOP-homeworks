#include "PrivilegeAccount.h"
PrivilegeAccount::PrivilegeAccount(String username, String password, String IBAN, size_t id, double money, time_t date, double overdraft) :Account(username, password, IBAN, id, money, date) {
	this->overdraft = overdraft;
}
void PrivilegeAccount::deposit(double amount) {
	this->amount += amount;
}
bool PrivilegeAccount::withdraw(double amount) {
	if (this->amount + overdraft < amount) {
		return false;
	}
	this->amount -= amount;
	return true;
}
void PrivilegeAccount::display() {
	std::cout << "privilege account ";
	Account::display();
	std::cout << " overdraft:" << overdraft << std::endl;
}
Account* PrivilegeAccount::clone()const {
	return new PrivilegeAccount(*this);
}