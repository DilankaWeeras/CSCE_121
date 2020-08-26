#include "TemperatureDatabase.h"
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {records.clear();}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream in {filename};
	
	string id;
	bool add = true;
	int year;
	int month;
	double temp;

	if(!in.is_open()) // if it is not open error
	{
		cout << "Error: Unable to open " << filename ;
	}
	
	while(!in.eof()) { // until the end is reached	
		string tempString;
		getline(in, tempString);
		if(tempString == "") {break;}
		add = true;
		stringstream ss;
		ss << tempString;
		
		
		
		ss >> id; // input id
		if(ss.fail()) {
			add = false;
			cout << "Error: Other invalid input" << endl;
		}
		ss >> year; // input year
		if(ss.fail()) {
			add = false;
			cout << "Error: Other invalid input" << endl;
		}
		ss >> month; // input month
		if(ss.fail()) {
			add = false;
			cout << "Error: Other invalid input" << endl;
		}
		ss >> temp; // input temp
		if(temp == -99.99 || ss.fail()) {
			add = false;
			cout << "Error: Other invalid input" << endl;
		}
		
		//in >> id;
		//in >> year;
		//in >> month;
		//in >> temp;
		if(add) { // if add then it will work
			if(year > 2018 || year < 1800) {
				add = false;
				cout << "Error: Invalid year " << year << endl;
			}
			/*else if(in.eof()) {
				break;
			}*/
			else if(month > 12 || month < 1) { 
				add = false;
				cout << "Error: Invalid month " << month << endl;
			}
			if(temp == -99.99 || temp < -50 || temp > 50) { 
				add = false;
				cout << "Error: Invalid temperature " << temp << endl;
			}
		}
		if(add) {records.insert(id, year, month, temp);}
	}
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
	ifstream in {filename};
	ofstream out {"result.dat"};
	
	string tempString;
	bool add = true;
	
	int yearStart;
	int yearEnd;
	string location;
	string q;
	while(!in.eof()) {
		getline(in, tempString);
	if(tempString == "") {break;}
		add = true;
		stringstream ss;
		ss << tempString;
		
		
		ss >> location;
		/*if(in.fail()) {
			add = false;
			cout << "Error: Other invalid query" << endl;
		}*/
		ss >> q;
		/*if(in.fail()) {
			add = false;
			cout << "Error: Other invalid query" << endl;
		}*/
		ss >> yearStart;
		/*if(in.fail()) {
			add = false;
			cout << "Error: Other invalid query" << endl;
		}*/
		ss >> yearEnd;
		if(ss.fail()) { // if it fails then output the error sequence
			add = false;
			cout << "Error: Other invalid query" << endl;
			ss.clear();
			ss.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		else if(yearStart < 1800 || yearEnd > 2018 || yearEnd < yearStart) { // it cannot be outside the bounds of the given year parameters
			add = false;
			cout << "Error: Invalid range " << yearStart << "-" << yearEnd << endl;
		}
		else if(q != "AVG" && q != "MODE") { // if the type of input is incorrect, you can only have MODE or AVG
			add = false;
			cout << "Error: Unsupported query " << q << endl;
		}
		
		if(add) { // if add is true the program did not hit any errors
			if(q == "AVG") { 
				if(records.calcAvg(location, yearStart, yearEnd) == -9999) { // make sure the average is not unkown
					out << location << " " << yearStart << " " << yearEnd << " AVG unknown" << endl;
				}
				else { //print answer
					out << location << " " << yearStart << " " << yearEnd << " AVG " << records.calcAvg(location, yearStart, yearEnd) << endl;
				}
			}
			if(q == "MODE") { 
				if(records.mode(location, yearStart, yearEnd) == -9999) { // make sure the mode is not unknown
					out << location << " " << yearStart << " " << yearEnd << " MODE unknown" << endl;
				}
				else { //print answer
					out << location << " " << yearStart << " " << yearEnd << " MODE " << records.mode(location, yearStart, yearEnd) << endl;
				}
			}			
		}
	}
	print();
}

void TemperatureDatabase::print() {
	cout << records; // prints the data in LL
}
