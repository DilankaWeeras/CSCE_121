#include <iostream>
#include "Color.h"

using namespace std;

int main() {
	Color a = Color(255, 0, 0);

	Color b = Color(0, 0, 255);

	Color c = a + b;
        
    /*//comment out start (remove after switch to use overloaded output operator)
	cout << "color a: ";
	a.printColor();
	cout << endl;
    */// comment out end
    
     // uncomment to use overloaded output operator
    cout << "color a: " << a << endl;
    cout << "color b: " << b << endl;
    cout << "color c (a+b): " << c << endl;
    
}