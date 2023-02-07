#pragma once
#include "Account.h"
class SavingsAccount :public Account
{
	double interestRate;
public:
	SavingsAccount(String, String, String, size_t, double, time_t, double);
	void deposit(double amount) override;
	bool withdraw(double amount) override;
	void display()override;
	Account* clone()const override;
};

