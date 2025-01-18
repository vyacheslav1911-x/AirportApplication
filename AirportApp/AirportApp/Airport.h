#include <iostream>
#include <string>
#include "Flight.h"
#include "Employee.h"

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
	Employee* employees;

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

	// getters
	string getId() const {
		return this->id;
	}

	string getName() const {
		return this->name;
	}

	string getParkingLots() const {
		return this->parkingLots;
	}
};