#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits>
using namespace std;

int main()
{
    // get a seed value for the pseudo-random number generator
    cout << "Enter seed value: ";
    int rseed;
    cin >> rseed;
    srand(rseed);
    cout << endl;

    // define constants for random values
    const int NUM_VALUES = 100;
    const int RANGE = 1000000;

    // populate a array with random values
    int values[NUM_VALUES];
    for (int i = 0; i < NUM_VALUES; i++)
    {
        int val = (rand()%2==0) ? rand()%RANGE : rand()%RANGE*-1;
        values[i] = val;
    }

    // iterate through array and print values
    // COMMENT OUT OR REMOVE THIS FOR LOOP FOR YOUR VOCAREUM SUBMISSION
    for (int i = 0; i < NUM_VALUES; i++)
    {
        cout << setw(8) << values[i];
        if ((i + 1) % 10 == 0) cout << endl; // new line every 10 numbers
        // For fun, change i+1 to just i above, run and
        //    see how that affects the output
    }
    cout << endl;

    int min, max;
    double avg, sum;

    /*
        Students: This is where your code will go to find the
        min, max, and average values in the array.

        Be sure to initialize your min, max, sum, and average values
        appropriately. Try not to initialize to a value that can potentially
        be a value in the array. Assume the array can hold any value.
    */
	min = values[0];
	max = values[0];
	sum = 0;
	
	for(int i = 0; i < NUM_VALUES; i++)
	{
		if(max < values[i]) max = values[i];
		if(min > values[i]) min = values[i];
		sum += values[i];
	}
   
    avg = sum / NUM_VALUES;

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << fixed << setprecision(2) << avg << endl;
}