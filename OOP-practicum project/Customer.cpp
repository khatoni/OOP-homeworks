#include "Customer.h"

Customer::Customer(String name, size_t id, String address) {
	this->address = address;
	this->name = name;
	this->id = id;
}
size_t Customer::getCustomerId()const {
	return id;
}
String Customer::getCustomerName()const {
	return name;
}
String Customer::getCustomerAddress()const {
	return address;
}
void Customer::setCustomerId(size_t id) {
	this->id = id;
}
void Customer::setCustomerName(String name) {
	this->name = name;
}
void Customer::setCustomerAddress(String address) {
	this->address = address;
}
bool operator==(const Customer s1, const Customer s2) {
	return s1.getCustomerName() == s2.getCustomerName() &&
		s1.getCustomerId() == s2.getCustomerId();
}
std::ostream& operator<<(std::ostream& os, const Customer& other) {
	os << "name: " << other.name << "  id: " << other.id << "  address: " << other.address;
	return os;
}
