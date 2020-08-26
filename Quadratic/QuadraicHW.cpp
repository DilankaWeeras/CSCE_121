#include <iostream>
#include <math.h>
using namespace std;



int main()
{

	double a;
	double b;
	double c;

	double nums[3];

	for (int i = 0;i < 3; i++)
	{
		cin >> nums[i];
	}
	// (-b - sqrt(b^2 - 4*A*C))2*A
	a = nums[0];
	b = nums[1];
	c = nums[2];
	
	double start = -b/(2*a);
	double swapper = (b*b) - (4*a*c);
	double vec = (pow(swapper,.5))/(2*a);
	
	
	if(a>=0&b>=0&c>=0){
		cout << a << "x^2 + " << b << "x + " << c << " = 0\n";
	}
	if(a<0&b>=0&c>=0){
		cout << a << "x^2 + " << b << "x + " << c << " = 0\n";
	}
	if(a<0&b<0&c>=0){
		cout << a << "x^2 - " << -1*(b) << "x + " << c << " = 0\n";
	}
	if(a<0&b<0&c<0){
		cout << a << "x^2 - " << -1*(b) << "x - " << -1*(c) << " = 0\n";
	}
	if(a>=0&b<0&c>=0){
		cout << a << "x^2 - " << -1*(b) << "x + " << c << " = 0\n";
	}
	if(a>=0&b<0&c<0){
		cout << a << "x^2 - " << -1*(b) << "x - " << -1*(c) << " = 0\n";
	}
	if(a>=0&b>=0&c<0){
		cout << a << "x^2 + " << b << "x - " << -1*(c) << " = 0\n";
	}
	if(a<0&b>=0&c<0){
		cout << a << "x^2 + " << b << "x - " << -1*(c) << " = 0\n";
	}
	
	if(a == 0 && b != 0 && c != 0)
	{
		cout << "x = " << -c/b << endl;
		return 0;
	}
	
	
	
	if(swapper < 0)
	{
		swapper =swapper * (-1);
		double vec = pow(swapper,.5)/(2*a);
		if(vec < 0)
		{
		vec = vec * (-1);
		cout << "x = " << start << " + " << vec << "i\n";
		cout << "x = " << start << " - " << vec << "i\n";
		}
		else
		{
		cout << "x = " << start << " - " << vec << "i\n";
		cout << "x = " << start << " + " << vec << "i\n";
		}
	}
	else if(isnan(vec))
	{
		cout << "Unable to determine root(s).\n";
	}
	else if(swapper == 0)
	{
		cout << "x = " << start << endl;
	}
	else
	{
		cout << "x = " << start - vec << endl;
		cout << "x = " << start + vec << endl;
	}


	return 0;
}
