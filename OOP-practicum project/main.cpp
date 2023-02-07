#include<iostream>
#include <string>
#include "Bank.h"
const int MAX_SIZE = 100;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Bank bank("First Bank", " rido street 1");
	std::cout << " Choose from the options: Edit, List, Action, Display info for the bank, Quit\n";

	while (true) {
		char* command1 = new char[MAX_SIZE];
		std::cin.getline(command1, MAX_SIZE);
		if (strcmp(command1, "Edit") == 0) {
			std::cout << " Choose from the options: Customer, Account\n";
			char* command2 = new char[MAX_SIZE];
			std::cin.getline(command2, MAX_SIZE);
			if (strcmp(command2, "Customer") == 0) {
				std::cout << " Choose from the options: Add customer, Delete customer\n";
				char* command3 = new char[MAX_SIZE];
				std::cin.getline(command3, MAX_SIZE);
				if (strcmp(command3, "Add customer") == 0) {
					std::cout << "Enter name: ";
					char* name = new char[MAX_SIZE];
					std::cin.getline(name, MAX_SIZE);

					std::cout << "\nEnter id: ";
					size_t id;
					std::cin >> id;
					std::cin.ignore();
					std::cout << "\nEnter address: ";
					char* address = new char[MAX_SIZE];
					std::cin.getline(address, MAX_SIZE);

					Customer tmp(name, id, address);
					delete[]name;
					delete[]address;
					if (bank.addCustomer(tmp) == 1) {
						Log tmp(id, "Added customer");
						bank.addLogToVector(tmp);
						std::cout << "Customer added successfully!\n";
					}
					else {
						std::cout << "Error while adding the customer";
					}
				}
				if (strcmp(command3, "Delete customer") == 0) {

					std::cout << "\nEnter id: ";
					size_t id;
					std::cin >> id;
					std::cin.ignore();
					if (bank.deleteCustomer(id) == 1) {
						Log tmp(id, "Deleted customer");
						bank.addLogToVector(tmp);
						std::cout << "Customer deleted successfully\n";
					}
					else {
						std::cout << "Not such customer \n";
					}
				}
				delete[]command3;
			}

			if (strcmp(command2, "Account") == 0) {
				std::cout << " Choose from the options: Add account, Delete account\n";
				char* command3 = new char[MAX_SIZE];

				std::cin.getline(command3, MAX_SIZE);
				if (strcmp(command3, "Add account") == 0) {
					char* type = new char[MAX_SIZE];
					String username, password, IBAN;
					std::cout << "Choose type of account: Normal, Savings, Privilege:\n ";
					std::cin >> type;
					std::cout << "Enter username: \n";
					std::cin >> username;
					std::cout << "Enter password: \n";
					std::cin >> password;
					std::cin.ignore();
					size_t id;
					std::cout << "Enter id:\n";
					std::cin >> id;
					std::cin.ignore();
					std::cout << "Enter IBAN:\n";
					std::cin >> IBAN;
					time_t timer;
					timer = time(0);
					if (strcmp(type, "Normal") == 0) {
						NormalAccount* tmp = new NormalAccount(username, password, IBAN, id, 0, timer);
						if (bank.addAccount(tmp)) {
							Log tmp(id, "Created normal account");
							bank.addLogToVector(tmp);
							std::cout << "Account added successfully for user with id: " << id << std::endl;
						}
						else {
							std::cout << "Invalid account - whether invalid id or IBAN";
						}
						delete tmp;
					}
					if (strcmp(type, "Privilege") == 0) {
						std::cout << "Enter overdraft: \n";
						double overdraft;
						std::cin >> overdraft;
						std::cin.ignore();
						PrivilegeAccount* tmp = new PrivilegeAccount(username, password, IBAN, id, 0, timer, overdraft);
						if (bank.addAccount(tmp)) {
							Log tmp(id, "Created privilege account");
							bank.addLogToVector(tmp);
							std::cout << "Account added successfully for user with id: " << id << std::endl;
						}
						else {
							std::cout << "Invalid account - whether invalid id or IBAN";
						}
						delete tmp;
					}
					if (strcmp(type, "Savings") == 0) {

						std::cout << "Enter interest rate: \n";
						double interest;
						std::cin >> interest;
						std::cin.ignore();
						SavingsAccount* tmp = new SavingsAccount(username, password, IBAN, id, 0, timer, interest);
						if (bank.addAccount(tmp)) {
							Log tmp(id, "Created savings account");
							bank.addLogToVector(tmp);
							std::cout << "Account added successfully for user with id: " << id << std::endl;
						}
						else {
							std::cout << "Invalid account - whether invalid id or IBAN";
						}
						delete tmp;
					}
					delete[]type;
				}

				if (strcmp(command3, "Delete account") == 0) {
					std::cout << "Enter IBAN:\n";
					String IBAN;
					std::cin >> IBAN;
					std::cout << " Enter id";
					size_t id;
					std::cin >> id;
					if (bank.deleteAccount(IBAN, id)) {
						String str("Delete account with IBAN");
						str.concat(IBAN);
						Log tmp(id, str);
						bank.addLogToVector(tmp);
						std::cout << "Account deleted successfully\n";
					}
					else {
						std::cout << "Error while deleting the account- wrong id or IBAN\n";
					}

				}
				delete[]command3;
			}
			delete[]command2;
		}
		if (strcmp(command1, "List") == 0) {
			std::cout << " Choose from the options: List all customers, List all accounts, List customer account, List log\n";
			char* command2 = new char[MAX_SIZE];
			std::cin.getline(command2, MAX_SIZE);

			if (strcmp(command2, "List all customers") == 0) {
				bank.listCustomers();
			}
			if (strcmp(command2, "List all accounts") == 0) {
				bank.listAccounts();
			}
			if (strcmp(command2, "List customer account") == 0) {
				std::cout << "Enter id\n";
				size_t id;
				std::cin >> id;
				bank.listCustomerAccounts(id);
			}
			if (strcmp(command2, "List log") == 0) {
				bank.listLog();
			}
			delete[]command2;
		}
		if (strcmp(command1, "Action") == 0) {
			std::cout << "Enter one of withdraw,deposit,transfer\n";
			char* command2 = new char[MAX_SIZE];
			std::cin.getline(command2, MAX_SIZE);
			if (strcmp(command2, "withdraw") == 0) {
				std::cout << "Enter IBAN:\n";
				char* IBAN = new char[MAX_SIZE];
				std::cin >> IBAN;
				std::cout << " Enter id";
				size_t id;
				std::cin >> id;
				std::cout << "Enter money: ";
				double money;
				std::cin >> money;
				if (bank.isValidId(id) && bank.isValidIBAN(IBAN)) {
					if (bank.withdraw(IBAN, money)) {
						Log tmp(id, "Withdrawed money");
						bank.addLogToVector(tmp);
						std::cout << "Successfully withdrawed: " << money << " from the account with IBAN: " << IBAN << std::endl;
					}
					else {
						std::cout << "Unable to withdraw, because of not enough money or Savings account:" << std::endl;
					}
				}
				else {
					std::cout << "Not valid id or IBAN:\n";
				}
				delete[]IBAN;
			}
			if (strcmp(command2, "deposit") == 0) {
				std::cout << "IBAN: ";
				char* IBAN = new char[MAX_SIZE];
				std::cin >> IBAN;
				std::cout << "\nid: ";
				std::cin.ignore();
				size_t id;
				std::cin >> id;
				std::cout << "\nmoney= ";
				double money;
				std::cin >> money;
				if (bank.depositMoney(id, IBAN, money)) {
					Log tmp(id, "Deposited money");
					bank.addLogToVector(tmp);
					std::cout << "Deposite successfully " << money << " into your account with IBAN: " << IBAN << std::endl;
				}
				else {
					std::cout << "Wrong id or IBAN(no such account or user): " << std::endl;
				}
				delete[]IBAN;
			}
			if (strcmp(command2, "transfer") == 0) {
				String fromIBAN, toIBAN;
				std::cout << "Enter id: ";
				size_t id;
				std::cin >> id;
				std::cout << "\nEnter fromIBAN:\n";
				std::cin >> fromIBAN;
				std::cout << "Enter toIBAN:\n";
				std::cin >> toIBAN;
				std::cin.ignore();
				double money;
				std::cout << "Enter money= \n";
				std::cin >> money;
				if (bank.transfer(fromIBAN, toIBAN, money)) {
					Log tmp(id, "Transfered money");
					bank.addLogToVector(tmp);
					std::cout << "Successfully transfered money \n";
				}
				else {
					std::cout << "Error while transfering the money \n";
				}
			}
			delete[]command2;
		}
		if (strcmp(command1, "Display") == 0) {
			bank.display();
		}
		if (strcmp(command1, "Quit") == 0) {
			bank.exportLog();
			delete[]command1;
			break;
		}

		delete[]command1;
	}


	return 0;
}