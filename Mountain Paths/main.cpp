#include <iostream>
#include <fstream>
#include <cstring>
#include "functions.h"
using namespace std;

// Normally you should not use global variables. However, the stack is
//   limited in size and will not allow arrays of this size. We'll learn
//   later how to put these arrays on the heap instead. Regardless, for now
//   we'll use these and treat them as if they were declared in main. So
//   when used in functions, we'll pass them as we would any other array.

static int elevations[MAX_ROWS][MAX_COLS];
static Pixel image[MAX_ROWS][MAX_COLS];

int main() 
{
	int rows;
	int cols;
	
	int max;
	int min;
	
	char filename[100];
	
	cout << "What is the Max Rows: " << endl;
	cin >> rows;
	if(cin.fail() || rows == '\0')
	{
		cout << "Error: Problem reading in rows and columns.";
		abort();
	}
	cout << "What is the Max Cols: " << endl;
	cin >> cols;
	if(cin.fail() || cols == '\0')
	{
		cout << "Error: Problem reading in rows and columns.";
		abort();
	}
	if(rows <= 0 || cols <= 0)
	{
		cout << "Error: Problem reading in rows and columns.";
		abort();
	}
	
	cout << "What is the name of the file? " << endl;
	cin >> filename;
	
	ifstream in {filename};
	//ifstream in {"map-input-100-100.dat"};
	
	if(!in.is_open())
	{
		cout << "Error: Unable to open file " << filename << ".";
		abort();
	}
	
	loadData(elevations, rows, cols, in);
	
	findMaxMin(elevations, rows, cols, max, min);
	
	loadGreyscale(image,elevations,rows,cols,max,min);
	
	//PART II
	
	Pixel color;
	color.red = 252;
	color.green = 25;
	color.blue = 63;
	
	int minDis = colorPath(elevations, image, rows, cols, color, 0);
	int tempDis = colorPath(elevations, image, rows, cols, color, 0);
	
	int minRow = 0;
	
	for(int i = 0; i < rows; i++)
	{
		tempDis = colorPath(elevations, image, rows, cols, color, i);
		if(minDis > tempDis)
		{
			minDis = tempDis;
			minRow = i;
		}
	}
	
	color.red = 31;
	color.green = 253;
	color.blue = 13;
	
	colorPath(elevations, image, rows, cols, color, minRow);
	
	// END PART II
	
	strcat(filename,".ppm");
	
	
	ofstream out {filename};
	
	if(!out.is_open())
	{
		cout << "Unable to open file " << filename << ".\n";
		abort();
	}
	
	outputImage(image,rows,cols,out);
	
	
	
	return 0;
}