/*
    This file should contain the member function
    implementations for the SavingsAccount class
*/

#include "SavingsAccount.h"

// FIXME: add the constructors (two if you use a default parameter, three otherwise)
SavingsAccount::SavingsAccount(double interest_rate) : 
	Account(), interest_rate(interest_rate) {}
	
SavingsAccount::SavingsAccount(double balance, double interest_rate) :
	Account(balance), interest_rate(interest_rate) {}
	
double SavingsAccount::getInterestRate() {return interest_rate;}

void SavingsAccount::setInterestRate(double interest) {interest_rate = interest;}
	
	

// FIXME: add definition for getInterestRate()


// FIXME: add definition for setInterestRate(double newRate)
