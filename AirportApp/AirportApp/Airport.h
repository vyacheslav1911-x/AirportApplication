#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

#pragma once
class Airport
{
private:
	string id;
	string name;
	int parkingLots;
	bool isForInternationalFlights;
	Flight* flights;
	Plane* planes;

public:
	Airport(
		string id,
		string name,
		int parkingLots,
		bool isForInternationalFlights
	) {}

	// setters
	void setName(const string& name) {
		this->name = name;
	}

	void setParkingLots(const int& parkingLots) {
		this->parkingLots = parkingLots;
	}


};