#include <iostream>
#include <cstring>
#include <sstream>
#include "Customer.h"
#include "Product.h"
using namespace std;

int Customer::counter = 0; // defines and initializes

Customer::Customer(int customerID, const char name[], bool credit) :
		id(customerID), balance(0.0), numPurchased(0), credit(credit) {
	setName(name);		
}
int Customer::getID() const { return id; }

const char* Customer:: getName() const { return name; }

void Customer::setName(char const customerName[])
{
	if (strlen(customerName) > 0) {
        strcpy(this->name, customerName);
    }
    else {
        counter++;
        ostringstream oss;
        oss << "Customer " << counter;
        strcpy(this->name, oss.str().c_str());
    } 
}

bool Customer:: getCredit() const { return credit; }

void Customer::setCredit(bool hasCredit) { credit = hasCredit; }

double Customer:: getBalance() const { return balance; }

bool Customer::processPayment(double amount)
{
	if(amount < 0) {
		return false;
	}
	else {
		balance += amount;
	}
	return true;
}

bool Customer::processPurchase(double amount, Product product)
{
	if(!credit && balance < amount) {
		return false;
	}
	else {
		balance -= amount;
	}
	bool inList = false;
	for(int i = 0; i < numPurchased; i++)
	{
		if(strcmp(product.getName(), productsPurchased[i]) == 0) { inList = true; }
	}
	if(!inList)
	{
		if(numPurchased < 5) { numPurchased++; }
		for(int i = numPurchased -1; i > 0; i--)
		{
			strcpy(productsPurchased[i], productsPurchased[i-1]);
		}
		strcpy(productsPurchased[0], product.getName());
	}
	return true;
}

void Customer::outputRecentPurchases(std::ostream& os) const
{
	os << "Products Purchased --" << endl;
	for(int i = 0; i < numPurchased ; i++)
	{
		os << productsPurchased[i] << endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Customer& customer)
{
	char creditC[5];
	if(customer.getCredit()){
		strcpy(creditC,"true");
	}
	else{
		strcpy(creditC,"false");
	}
	os << "Customer Name: " << customer.getName()    << endl;
	os << "Customer ID: "   << customer.getID()      << endl;
	os << "Has Credit: "    << creditC               << endl;
	os << "Balance: "       << customer.getBalance() << endl;
	customer.outputRecentPurchases(os);
	return os;
}
