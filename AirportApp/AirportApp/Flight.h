#include "Plane.h"
#pragma once

class Flight
{
private:
	string flightId;
	optional<string> arrival;
	optional<string> departure;
	Plane plane;

public:
	Flight(
		string flightId,
		optional<string> arrival,
		optional<string> departure,
		const Plane& plane
	);

	void printFlightInfo() const {
		cout << "Flight number: " << flightId << endl;

		if (arrival.has_value()) {
			cout << "Arrival: " << arrival.value() << endl;
		}
		else {
			cout << "Arrival: Not available" << endl;
		}

		if (departure.has_value()) {
			cout << "Departure: " << departure.value() << endl;
		}
		else {
			cout << "Departure: Not available" << endl;
		}

		cout << "--- Plane Information ---" << endl;
		plane.printPlaneInformation();
	}
};

