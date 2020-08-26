#include <iostream>
#include <cstring>
#include <sstream>
#include "Store.h"
#include "Product.h"
#include "Customer.h"
using namespace std;

int Store::counter = 0; // defines and initializes

Store::Store() : numProducts(0), numCustomers(0)
{
    setName("");
}
Store::Store(const char name[]) : numProducts(0), numCustomers(0)
{
	setName(name);
}
const char* Store::getName()
{
	return name;
}
void Store::setName(const char storeName[])
{
	if(strlen(storeName) > 0)
	{
		strcpy(this->name, storeName);
	}
	else
	{
		counter++;
		ostringstream oss;
		oss << "Store " << counter;
		strcpy(this->name, oss.str().c_str());
	}
}
bool Store::addProduct(int productID, const char productName[])
{
	if(productExist(productID) || numProducts > 98) { return false; }
	products[numProducts] = new Product(productID, productName);
	numProducts++;
	return true;
}
Product* Store::getProduct(int productID)
{
	if(!productExist(productID)) { return nullptr;}
	for(int i = 0; i < numProducts; i++)
	{
		if(products[i]->getID() == productID) { return products[i]; }
	}
}
// even though getProduct should be private, it helps autograding to make it public
bool Store::addCustomer(int customerID, const char customerName[], bool credit)
{
	if(customerExist(customerID) || numCustomers > 98) { return false; }
	customers[numCustomers] = new Customer(customerID, customerName, credit);
	numCustomers++;
	return true;
}	
Customer* Store::getCustomer(int customerID)
{
	if(!customerExist(customerID)) { return nullptr; }
	for(int i = 0; i < 100; i++)
	{
		if(customers[i]->getID() == customerID) { return customers[i]; }
	}
}
// even though getCustomer should be private, it helps autograding to make it public
bool Store::takeShipment(int productID, int quantity, double cost)
{
	if(!productExist(productID)) { return false; }
	return getProduct(productID)->addShipment(quantity,cost);
}
bool Store::sellProduct(int customerID, int productID, int quantity)
{
	
	if(!(productExist(productID) && customerExist(customerID))) { return false;}
	if((getProduct(productID)->getInventoryCount() < quantity || quantity < 0)) {return false;}
	if(getCustomer(customerID)->getCredit() == false && getCustomer(customerID)->getBalance() < getProduct(productID)->getPrice()) { return false; }
	/*return getCustomer(customerID)->processPurchase(getProduct(productID)->getPrice(), *getProduct(productID)) && getProduct(productID)->reduceInventory(quantity);
	*/
	Product *p = Store::getProduct(productID);
	Customer *c = Store::getCustomer(customerID);
	
	double price = quantity * p->getPrice();
	if(p->getInventoryCount() >= quantity)
	{
		c->processPurchase(price, *p);
		p->reduceInventory(quantity);
	}
	return true;
}
bool Store::takePayment(int customerID, double amount)
{
	if(!customerExist(customerID)) { return false; }
	getCustomer(customerID)->processPayment(amount);
}
void Store::outputProducts(std::ostream& os)
{
	for(int i = 0; i < numProducts; i++)
	{
		Product *p = products[i];
		os << *p << endl;
	}
}
void Store::outputCustomers(std::ostream& os)
{
	for(int i = 0; i < numCustomers; i++)
	{
		Customer *c = customers[i];
		os << *c << endl;
	}
}

// NEW HELPER FUNCTIONS
bool Store::productExist(int productID)
{
	bool exist = false;
	for(int i = 0; i < numProducts; i++)
	{
		if(products[i]->getID() == productID) { exist = true; }
	}
	return exist;
}
bool Store::customerExist(int customerID)
{
	bool exist = false;
	for(int i = 0; i < numCustomers; i++)
	{
		if(customers[i]->getID() == customerID) { exist = true; }
	}
	return exist;
}