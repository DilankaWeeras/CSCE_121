#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



int main
{
	new int one = 1;
	new int two = 2;
	new int three = 3;
	new int four = 4;
	new int five = 5;
	new int six = 6;
	new int seven = 7;
	new int eight = 8;
	new int nine = 9;
	new int ten = 10;
	
	new int list[10] = {1,2,3,4,5,6,7,8,9,10};
	
	cout << one << two << three << four << five << six << seven << eight << nine << ten << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << list[i];
	}
	cout << endl;
}