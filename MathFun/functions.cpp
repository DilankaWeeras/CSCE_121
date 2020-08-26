#include <iostream>
#include "functions.h"
#include <math.h>

using namespace std;


/*
    Returns temperature in Fahrenheit
    T(f) = 9/5 T(c) + 32
    You do not have to verify that the input is a valid 
       Celsius Temperature
    Input: double representing a temperature in 
    Returns: double that represents the input's equivalent 
       Fahrenheit temperature
*/
double convertCelsiusToFahrenheit(double tempC) {
    return (tempC*(9.0/5) + 32); // replace 0 with actual return value
	
}
/*
    Returns temperature in Celsius
    T(c) = 5/9 (T(f) - 32)
    You do not have to verify that the input is a valid 
       Fahrenheit Temperature
    Input: double representing a temperature in Fahrenheit
    Returns: double that represents the input's equivalent 
       Celsius temperature
*/
double convertFahrenheitToCelsius(double tempF) {
    return (tempF - 32)*(5.0/9); // replace 0 with actual return value
}
/*
    Get input from user, call appropriate functions to calculate results
      and output those results.
*/
void processTemperature() {
	double temp;
	cout << "Please enter a temperature: ";
	cin >> temp;
//	cout << endl;
	char choice;
	cout << "Is that Celsius or Fahrenheit? [F/C] ";
	cin >> choice;
	
	switch(choice){	
	case 'f':
	cout << temp << "F is " << convertFahrenheitToCelsius(temp) << "C.";
	break;
	case 'c':
	cout << temp << "C is " << convertCelsiusToFahrenheit(temp) << "F.";
	break;
	case 'F':
	cout << temp << "F is " << convertFahrenheitToCelsius(temp) << "C.";
	break;
	case 'C':
	cout << temp << "C is " << convertCelsiusToFahrenheit(temp) << "F.";
	break;
	default : 
	cout << choice << " is not a supported temperature scale.";
	break;
	cout << endl << endl;
}
}

/*
    Calculates the sum of integers between 0 and input number
    For example if the number is 4, then the output will be 0+1+2+3+4 
       which is 10
    For example if the number is -3, then the output will be 0-1-2-3 
       which is -6
    Input: int
    Output: int representing the sum of integers between 0 and the input
*/
int sums(int num) {
    int sum = 0;
	if(num < 0)
	for(int i = 0; i >= num; i--)
	{
		sum = sum + i;
	}
	else
	for(int i = 0; i <= num; i++)
	{
		sum = sum + i;
	}
	
	return sum;
}
/*
    Get input from user, call appropriate functions to calculate results
      and output those results.
*/
void processSums() {
	int temp = 0;
	cout << "Get sum from zero to what integer? ";
	cin >> temp;
	cout << "The sum from zero to " << temp << " is " << sums(temp) << ".\n";
}

/*
    Calculates the sum of digits in a number
    If the number is negative, then negative sum will be output
    For example if the number is 4235, then the output will be 4+2+3+5 
       which is 14
    For example if the number is -367, then the output will be -(3+6+7) 
       which is -16
    Input: int
    Output: int representing sum of digits in a number that is negative 
       if the input is negative
*/
int sumOfDigits(int num) {
    int sum = 0;
	bool neg = false;
	if(num < 1)
	{
		num = num * -1;
		neg = true;
	}
	while(num > 0)
	{
		sum = sum + (num % 10);
		num = num / 10;
	}
	if(neg)
		sum *= -1;
	return sum;
}
/*
    Get input from user, call appropriate functions to calculate results
      and output those results.
*/
void processSumOfDigits() {
	int temp = 0;
	cout << "Get sum of digits for what integer? ";
	cin >> temp;
	cout << "The sum of digits for " << temp << " is " << sumOfDigits(temp) << ".\n";
	
	
}

/*
    Determines whether a number is prime or not
    Input: integer
    Output: boolean that is true if the input is prime, and false otherwise
*/
bool is_prime(int num) {
	for(int i = num/2; i > 1; i--)
	{
		if(num%i == 0)
			return false;
	}
    return true;  // replace false with actual return value
}
/*
    Get input from user, call appropriate functions to calculate results
      and output those results.
*/
void processPrime() {
	int temp = 0;
	cout << "Determine if what integer is prime? ";
	cin >> temp;
	if(is_prime(temp))
		cout << temp << " is prime.\n";
	else
		cout << temp << " is not prime.\n";
}

void printMenu() {
    cout << endl;
    cout << "Please choose from the following: " << endl;
    cout << " T - Convert temperature" << endl;
    cout << " S - Sum numbers from 0 to designated integer" << endl;
    cout << " D - Sum of digits in integer" << endl;
    cout << " P - Prime number" << endl;
    cout << " Q - Quit" << endl;
    cout << endl;
    cout << "Please enter choice: ";
}

/*
    Based on input, call appropriate "process" function for menu choices.
    
    switch statements work well in this context, 
      but if statements can work as well.
*/
void processMenuChoice(char choice) {
	choice = tolower(choice);
	switch(choice){
		
		case 't':
		processTemperature();
		break;
		case 's':
		processSums();
		break;
		case 'd':
		processSumOfDigits();
		break;
		case 'p':
		processPrime();
		break;
	}
}

