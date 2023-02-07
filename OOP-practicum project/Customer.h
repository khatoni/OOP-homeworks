#pragma once
#include "String.h"
class Customer
{
	String name;
	size_t id;
	String address;
public:
	Customer() = default;
	Customer(String, size_t, String);

	size_t getCustomerId()const;
	String getCustomerName()const;
	String getCustomerAddress()const;

	void setCustomerId(size_t);
	void setCustomerName(String);
	void setCustomerAddress(String);
	friend bool operator==(const Customer, const Customer);
	friend std::ostream& operator<<(std::ostream& os, const Customer&);
};

