#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

/*  FIXME:
    Create a SavingsAccount class inherited from the Account class.

    Add the data member interest_rate
      type should be double
      set default value of 0.001 in constructor

    This file should contain the class definition and the
    declarations of its member functions.
*/


//FIXME 1: add class definition for SavingsAccount
class SavingsAccount : public Account {
// FIXME 1A: add data member interest_rate
	private:
		double interest_rate;
	public:
// FIXME 1B: add default constructor and single parameter constructor
	SavingsAccount(double interest_rate = 0.001);
// FIXME 1C: add two parameter constructor
	SavingsAccount(double balance, double interest_rate);
// FIXME 1D: add getter declaration for interest_rate
	double getInterestRate();
// FIXME 1E: add setter declaration for interest_rate
	void setInterestRate(double interest);
};
#endif
