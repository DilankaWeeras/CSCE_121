/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData()
 : id(id), year(year), month(month), temperature(temperature) {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature)
 : id(id), year(year), month(month), temperature(temperature) {} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
	if(this->id.compare(b.id) != 0) {
		if(this->id.compare(b.id) < 0) {return true;}
		return false;
	}
	else if(this->year != b.year) {
		return this->year < b.year;
	}
	else if(this->month != b.month) { 
		return this->month < b.month;
	}
	else {return false;}
	
}

