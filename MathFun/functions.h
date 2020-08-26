#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void processTemperature();
double convertCelsiusToFahrenheit(double temp);
double convertFahrenheitToCelsius(double temp);

void processSums();
int sums(int num);

void processSumOfDigits();
int sumOfDigits(int num);

void processPrime();
bool is_prime(int num);

void printMenu();
void processMenuChoice(char choice);

#endif