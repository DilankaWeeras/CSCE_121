// Number Fun! Homework
#include <iostream>
#include "functions.h"


using namespace std;

int main() {
    char choice = ' ';
    do {
        printMenu();
        cin >> choice;
        processMenuChoice(choice);
    } while (tolower(choice) != 'q'); // comparing case allows 'Q' to work as well
}