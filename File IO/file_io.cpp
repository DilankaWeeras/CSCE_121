#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;
ifstream in;

int main()
{
	srand(time(NULL));

	int nums[MAX_SIZE];
    int size = 0;
    
	//EDIT1 comment out the next for loop
	// Load with random values
	/*
	for (int i=0; i<MAX_SIZE; ++i) {
		nums[i] = (rand()%2) ? -1* rand()%999 : rand()%999;
        size++;
	}
	*/
	// EDIT2: Setup and use input file "nums.dat"	
	in.open("nums.dat");
	// Input Step 1 Open file, preferably with RAII approach
	
	// Input Step 2 Check that file opened sucessfully
	if(!in.is_open())
	{
		cout << "Could not open file." << endl;
	}
	// Input Step 3 Use file (i.e. read numbers from file into nums array)
	for(int i = 0; i<MAX_SIZE && !in.eof();i++)
	{
		in >> nums[i];
		//cout << nums[i] << endl;
		size++;
	}
	// Input Step 4 Close file, preferably with RAII approach
	in.close();
	
    // Output values in array to standard out
	cout << "Unsorted values: " << endl;
	for (unsigned int i = 0; i < size; ++i) {
		cout << setw(5) << nums[i];
		if ((i + 1) % 5 == 0) cout << endl; // new line for each 5 numbers
	}
	cout << endl << endl;

	sort(nums, nums+size);

	// Output values in array to standard out
	cout << "Sorted values: " << endl;
	for (unsigned int i = 0; i < size; ++i) {
		cout << setw(5) << nums[i];
		if ((i + 1) % 5 == 0) cout << endl; // new line for each 5 numbers
	}
	cout << endl << endl;

	// Calculate the median
    // next statement probably needs a comment, 
	//    but as a challenge figure out what's going on...
	double median = (size % 2) ? nums[(size - 1) / 2] : 
		(nums[(size - 1) / 2] + nums[size / 2]) / 2.0;
        
    // Calculate the average
    int sum = 0;
    for (unsigned int i=0; i < size; ++i) {
        sum += nums[i];
    }
    double average = sum/size;
    
    // Edit3: convert to send to the output file instead of to standard out
	ofstream out;
	// Output Step 1 Open file, preferably with RAII approach
	out.open("stats.dat");
	// Output Step 2: Check that file opened successfully
    if(!out.is_open())
	{
		cout << "File did not open.";
	}
	// Output Step 3: Use file 
	for(int i = 0; i < MAX_SIZE && !out.eof(); i++)
	{
		
	}
    //  (convert from using standard out to the output filestream)
		out << "Min: " << nums[0] << endl;
		out << "Max: " << nums[size - 1] << endl;
		out << "Median: " << median << endl;
        out << "Average: " << average << endl;
        
	// Output Step 4 Close, preferably with RAII approach
}