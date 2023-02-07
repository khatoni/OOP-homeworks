#pragma once
#include "Account.h"
class PrivilegeAccount :public Account
{
	double overdraft;
public:
	PrivilegeAccount(String, String, String, size_t, double, time_t, double);
	void deposit(double money)override;
	bool withdraw(double money)override;
	void display()override;
	Account* clone()const override;
};

