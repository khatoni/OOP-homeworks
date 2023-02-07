#pragma once
#include "String.h"
#include <ctime>
class Account
{
protected:
	String username;
	String password;
	String IBAN;
	size_t id;
	double amount;
	time_t dateOfCreation;

public:

	Account(String, String, String, size_t, double, time_t);
	virtual ~Account() {};
	virtual Account* clone() const = 0;
	virtual void deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;
	virtual void display();
	double getBalance()const;
	size_t getId()const;
	String getIBAN()const;
};

