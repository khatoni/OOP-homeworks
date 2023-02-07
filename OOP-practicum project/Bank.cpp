#include "Bank.h"
#include <fstream>
Bank::Bank(String name, String adress) {
	this->name = name;
	this->address = address;
}
bool Bank::addCustomer(const Customer& new_acc) {
	if (customers.empty() == 1) {
		customers.pushBack(new_acc);
		return 1;
	}
	bool flag = 0;
	for (int i = 0; i < customers.getSize(); i++) {
		if (customers[i].getCustomerId() == new_acc.getCustomerId()) {
			flag = 1;
		}
	}
	if (flag == 1) {
		return 0;
	}
	else {
		customers.pushBack(new_acc);
		return 1;
	}
}
void Bank::addLogToVector(const Log& other) {
	logs.pushBack(other);
}
bool Bank::deleteCustomer(size_t id) {
	size_t customer_size = customers.getSize();
	for (size_t i = 0; i < customer_size; i++) {
		if (customers[i].getCustomerId() == id) {
			customers.popAt(i);
			for (size_t j = 0; j < accounts.getSize(); j++) {
				if (accounts[i]->getId() == id) {
					Account* temp  = accounts.popAt(i);
					delete temp;
				}
			}
			return 1;
		}
	}

	return 0;
}
bool Bank::addAccount(const Account* other) {
	if (accounts.empty() == 1 && customers.empty() == 0) {
		accounts.pushBack(other->clone());
		return 1;
	}
	if (customers.empty() == 1) {
		return false;
	}
	size_t accounts_size = accounts.getSize();
	size_t customers_size = customers.getSize();
	bool flag_accounts = 1;
	bool flag_users = 0;
	for (size_t i = 0; i < accounts_size; i++) {
		if (accounts[i]->getIBAN() == other->getIBAN()) {
			flag_accounts = 0;
		}
	}
	for (size_t i = 0; i < customers_size; i++) {
		if (customers[i].getCustomerId() == other->getId()) {
			flag_users = 1;
		}
	}
	if (flag_accounts == 0) {
		return 0;
	}
	if (flag_users == 1 && flag_accounts == 1) {
		accounts.pushBack(other->clone());
		return 1;
	}
	else {
		return 0;
	}
}
void Bank::listCustomers()const {
	if (customers.empty() == 1) {
		std::cout << "No customers\n";
		return;
	}
	for (size_t i = 0; i < customers.getSize(); i++) {
		std::cout << customers[i] << std::endl;
	}
}
void Bank::listAccounts()const {
	if (accounts.empty() == 1) {
		std::cout << "No accounts\n";
		return;
	}
	size_t accounts_size = accounts.getSize();
	for (size_t i = 0; i < accounts_size; i++) {
		accounts[i]->display();
	}
}
void Bank::display()const {
	std::cout << "Number of customers: " << customers.getSize() << " Number of accounts: " << accounts.getSize();
}
void Bank::listCustomerAccounts(size_t id)const {
	size_t accounts_size = accounts.getSize();
	for (size_t i = 0; i < accounts_size; i++) {
		if (accounts[i]->getId() == id) {
			accounts[i]->display();
		}
	}
}
bool Bank::transfer(String IBAN1, String IBAN2, double money) {
	size_t accounts_size = accounts.getSize();
	int first_index = -1; int second_index = -1;
	for (size_t i = 0; i < accounts_size; i++) {
		if (accounts[i]->getIBAN() == IBAN1) {
			first_index = i;
		}
		if (accounts[i]->getIBAN() == IBAN2) {
			second_index = i;
		}
	}
	if (first_index == -1) {
		std::cout << "NO such IBAN1:" << std::endl;
		return false;
	}
	if (second_index == -1) {
		std::cout << "No such IBAN2:" << std::endl;
		return false;
	}
	if (first_index == -1 && second_index == -1) {
		std::cout << "Both IBANS are incorrect" << std::endl;
		return false;
	}
	if (accounts[first_index]->getBalance() <= money) {
		std::cout << "Not enough money in to account to transfer the wanted sum:" << std::endl;
		return false;
	}
	if (accounts[first_index]->withdraw(money)) {
		accounts[second_index]->deposit(money);
		return true;
	}
	return 0;

}
bool Bank::depositMoney(size_t id, String IBAN, double money) {
	for (size_t i = 0; i < accounts.getSize(); i++) {
		if (accounts[i]->getIBAN() == IBAN && accounts[i]->getId() == id) {
			accounts[i]->deposit(money);
			return true;
		}
	}
	return false;
}
void Bank::listLog()const {
	for (size_t i = 0; i < logs.getSize(); i++) {
		std::cout << logs[i] << " ";
	}
}

bool Bank::withdraw(String IBAN, double money) {

	for (size_t i = 0; i < accounts.getSize(); i++) {
		if (accounts[i]->getIBAN() == IBAN) {
			return accounts[i]->withdraw(money);
		}
	}
}
bool Bank::isValidId(size_t id)const {
	bool flag = 0;
	for (size_t i = 0; i < customers.getSize(); i++) {
		if (customers[i].getCustomerId() == id) {
			flag = 1; break;
		}
	}
	return flag;
}
bool Bank::isValidIBAN(String IBAN)const {
	bool flag = 0;
	for (size_t i = 0; i < accounts.getSize(); i++) {
		if (accounts[i]->getIBAN() == IBAN) {
			flag = 1; break;
		}
	}
	return flag;
}

bool Bank::deleteAccount(String IBAN, size_t id) {
	for (size_t i = 0; i < accounts.getSize(); i++) {
		if (accounts[i]->getIBAN() == IBAN && accounts[i]->getId() == id) {
			delete accounts[i];
			accounts.popAt(i);
			return true;
		}
	}
	return false;
}
void Bank::exportLog()const {
	std::ofstream outFile("Log.txt", std::ios::app);
	for (size_t i = 0; i < logs.getSize(); i++) {
		outFile << logs[i] << std::endl;
	}
	outFile.close();
}

void Bank::free() {
	for (size_t i = 0; i < accounts.getSize(); i++) {
		delete accounts[i];
	}

	accounts.clear();
}
void Bank::copy(const Bank& other) {
	name = other.name;
	address = other.address;
	customers = other.customers;
	logs = other.logs;
	for (int i = 0; i < accounts.getSize(); i++) {
		accounts.pushBack(other.accounts[i]->clone());
	}
}
Bank::Bank(const Bank& other) {
	copy(other);
}
Bank& Bank::operator=(const Bank& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}
Bank::~Bank() {
	free();
}