/*
 * TemperatureData.h
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */
#include <string>
#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA

using namespace std;

struct TemperatureData {
	string id = "-1";
	int year = 1800;
	int month = 1;
	double temperature = -99.99;
	
	
	// Put data members here
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
};

#endif /* TEMPERATUREDATA */
