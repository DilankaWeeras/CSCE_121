#include <iostream>
#include <fstream>
#include <cmath>
#include "functions.h"
using namespace std;


void findMaxMin(const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, int& max, int& min) 
{
	max = elevations[0][0];
	min = elevations[0][0];
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(max < elevations[i][j]) max = elevations[i][j];
			if(min > elevations[i][j]) min = elevations[i][j];
		}
	}
}

void loadData(int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, istream& inData) 
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			int val;
			if(inData.eof())
			{
				cout << "Error: End of file reached prior to getting all required data.";
				abort();
			}
			inData >> val;
			if(inData.fail())
			{
				cout << "Error: Read a non-integer value.";
				abort();				
			}
			
			elevations[i][j] = val;
		}
	}
	int val;
	inData >> val;
	if(!inData.fail() && val != '\0')
	{
		cout << "Error: Too many data points.";
		abort();
	}
}

int scaleValue(int value, int max, int min)
{
	double nume = 255.0 * (value - min);
	double deno = (max - min);
	double dval  = nume/deno;
	int ival = round(dval);
	
	return ival;
}

void loadGreyscale(Pixel image[MAX_ROWS][MAX_COLS], const int elevations[MAX_ROWS][MAX_COLS], int rows, int cols, int max, int min) 
{
	int color;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			color = scaleValue(elevations[i][j],max,min);
			image[i][j].red = color;
			image[i][j].green = color;
			image[i][j].blue = color;
		}
	}
}

void outputImage(const Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, ostream& outData) 
{
	outData << "P3" << endl;
	outData << cols << " " << rows << endl;
	outData << 255 << endl;
	
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			outData << image[i][j].red << " " << image[i][j].green << " " << image[i][j].blue << endl;
		}
	}
}

int colorPath(const int elevations[MAX_ROWS][MAX_COLS], Pixel image[MAX_ROWS][MAX_COLS], int rows, int cols, Pixel color, int start_row)
{
	int index_row = start_row;
	int index_col = 0;
	
	int topDiff;
	int midDiff;
	int botDiff;
	
	int dis = 0;
	
	image[index_row][index_col] = color;
	
	while(index_col < cols - 1)
	{
		
		if(index_row == 0)
		{
			midDiff = abs(elevations[index_row][index_col] - elevations[index_row][index_col+1]);
			botDiff = abs(elevations[index_row][index_col] - elevations[index_row+1][index_col+1]);
			
			if(midDiff <= botDiff)
			{
				index_col++;
				dis += midDiff;
			}
			else
			{
				index_row++;
				index_col++;
				dis += botDiff;
			}
		}
		else if(index_row == rows - 1)
		{
			midDiff = abs(elevations[index_row][index_col] - elevations[index_row][index_col+1]);
			topDiff = abs(elevations[index_row][index_col] - elevations[index_row-1][index_col+1]);
			
			if(midDiff <= topDiff)
			{
				index_col++;
				dis += midDiff;
			}
			else
			{
				index_row--;
				index_col++;
				dis += topDiff;
			}
		}
		else
		{
			topDiff = abs(elevations[index_row][index_col] - elevations[index_row-1][index_col+1]);
			midDiff = abs(elevations[index_row][index_col] - elevations[index_row][index_col+1]);
			botDiff = abs(elevations[index_row][index_col] - elevations[index_row+1][index_col+1]);
			
			if(midDiff <= botDiff && midDiff <= topDiff)
			{
				index_col++;
				dis += midDiff;
			}
			else if(botDiff <= midDiff && botDiff <= topDiff)
			{
				index_row++;
				index_col++;
				dis += botDiff;
			}
			else
			{
				index_row--;
				index_col++;
				dis += topDiff;
			}
		}
		image[index_row][index_col] = color;
	}	
	return dis;
}


