#pragma once
#include "Account.h"
class NormalAccount :public Account
{
public:
	NormalAccount(String, String, String, size_t, double, time_t);
	void deposit(double)override;
	bool withdraw(double)override;
	void display()override;
	Account* clone()const override;
	/*void setUsername(String);
	void setPassword(String);*/

};

