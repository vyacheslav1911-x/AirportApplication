#include "Plane.h"
#pragma once

class Flight
{
private:
	string flightId;
	optional<std::chrono::system_clock::time_point> arrival;
	optional<std::chrono::system_clock::time_point> departure;
	Plane plane;

public:
	Flight(
		const string& flightId,
		const optional<std::chrono::system_clock::time_point>& arrival,
		const optional<std::chrono::system_clock::time_point>& departure,
		const Plane& plane
	);

	void printFlightInfo(int id) const;
	void addFlight(const string& databaseName, const string& user, const string& password, const Plane& plane) const;

	// setters
	void setFlightId(const string& flightId) {
		this->flightId = flightId;
	}

	void setArrival(const optional<std::chrono::system_clock::time_point> arrival) {
		this->arrival = arrival;
	}

	void setDeparture(const optional<std::chrono::system_clock::time_point> departure) {
		this->departure = departure;
	}

	void setPlane(const Plane& plane) {
		this->plane = plane;
	}

	// getters
	string getFlightId() const {
		return this->flightId;
	}

	optional<std::chrono::system_clock::time_point> getArrival() const {
		return this->arrival;
	}

	optional<std::chrono::system_clock::time_point> getDeparture() const {
		return this->departure;
	}

	Plane getPlane() const {
		return this->plane;
	}
};