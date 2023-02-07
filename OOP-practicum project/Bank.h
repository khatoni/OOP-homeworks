#pragma once
#include "Vector.hpp"
#include "String.h"
#include "Customer.h"
#include "Account.h"
#include "Log.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
class Bank
{
private:
	String name;
	String address;
	Vector<Customer> customers;
	Vector<Account*> accounts;
	Vector<Log> logs;
public:
	Bank(String, String);
	Bank(const Bank& other);
	Bank& operator=(const Bank& other);
	~Bank();
	bool addCustomer(const Customer&);
	bool deleteCustomer(size_t id);
	bool addAccount(const Account*);
	bool deleteAccount(String IBAN, size_t id);
	void listCustomers()const;
	void listLog()const;
	void addLogToVector(const Log&);
	void exportLog()const;
	void listAccounts()const;
	void listCustomerAccounts(size_t id)const;
	bool transfer(String, String, double money);
	void display()const;
	bool depositMoney(size_t id, String IBAN, double money);
	bool withdraw(String IBAN, double money);
	bool isValidId(size_t id)const;
	bool isValidIBAN(String IBAN)const;
private:
	void free();
	void copy(const Bank& other);
};

