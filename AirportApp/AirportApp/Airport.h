#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

#pragma once
class Airport
{
private:
	string name;
	int parkingLots;
	bool isForInternationalFlights;
	Flight* flights;
	Plane* planes;
};

