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

	void printFlightInfo() const;
	void addFlight(const string& databaseName, const string& user, const string& password) const;
};