#include <iostream>
#include <string>
#include "Flight.h"
#include "Employee.h"
#include <optional>
#include <vector>

using namespace std;

#pragma once
class Airport
{
private:
	string id;
	string name;
	int parkingLots;
	bool isForInternationalFlights;
	Employee* employees;

public:
	Airport(
		const string& id,
		const string& name,
		const int& parkingLots,
		const bool& isForInternationalFlights,
		const optional<std::vector<Flight>>& flights,
		const optional<std::vector<Plane>>& planes,
		Employee* employees
	);
	optional<std::vector<Flight>> flights;
	optional<std::vector<Plane>> planes;


	void createPlain(const Plane& plane) {
		if (!planes.has_value()) {
			planes = std::vector<Plane>();
		}

		planes->push_back(plane);
	}

	void printPlanes() const;

	// setters
	void setName(const string& name) {
		this->name = name;
	}

	void setParkingLots(const int& parkingLots) {
		this->parkingLots = parkingLots;
	}

	void setIsForInternationalFlights(const bool& isForInternationalFlights) {
		this->isForInternationalFlights = isForInternationalFlights;
	}

	void setFlights(const optional<std::vector<Flight>> flights) {
		this->flights = flights;
	}

	void setPlanes(const optional<std::vector<Plane>> planes) {
		this->planes = planes;
	}

	void setEmployees(Employee*& employees) {
		this->employees = employees;
	}

	// getters
	string getId() const {
		return this->id;
	}

	string getName() const {
		return this->name;
	}

	int getParkingLots() const {
		return this->parkingLots;
	}

	bool getIsForInternationalFlights() const {
		return this->isForInternationalFlights;
	}

	optional<std::vector<Flight>> getFlights() const {
		return this->flights;
	}

	optional<std::vector<Plane>> getPlanes() const {
		return this->planes;
	}

	Employee* getEmployees() const {
		return this->employees;
	}
};