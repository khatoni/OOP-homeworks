#include "SavingsAccount.h"
SavingsAccount::SavingsAccount(String username, String password, String IBAN, size_t id, double money, time_t date, double interest) :Account(username, password, IBAN, id, money, date) {
	this->interestRate = interest;
}
void SavingsAccount::deposit(double amount) {
	this->amount += amount;
}
bool SavingsAccount::withdraw(double amount) {
	return false;
}
void SavingsAccount::display() {
	std::cout << "savings ";
	Account::display();
	std::cout << " interest rate: " << interestRate << std::endl;
}
Account* SavingsAccount::clone()const {
	return new SavingsAccount(*this);
}