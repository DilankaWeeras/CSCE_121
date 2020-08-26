#include <iostream>
#include <cmath>
using namespace std;

int main() {

int num = 0;

cout << "Enter number: ";
cin >> num;



int count = 0;

for(int i = 1; i <= 500; i += 1)
{
	for(int j = 1; j <= 500; j += 1 )
	{
		int calc = (i*i*i) + (j*j*j);
		if(calc == num && i<=j)
		{
			count += 1;
			cout << i << "^3 + " << j << "^3 = " << num << endl;
		}
	}
}
if(count > 0)
{
	cout << "There are " << count << " ways!" << endl;
}
else 
{
	cout << "There are no ways." << endl;
}





return 0;
}