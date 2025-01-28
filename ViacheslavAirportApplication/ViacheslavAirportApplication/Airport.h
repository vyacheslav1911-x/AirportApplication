#include <string>
#include <optional>
#include <vector>
#include "Employee.h"
#include "Flight.h"
#include "Plane.h"
#pragma once

using namespace System;
using namespace System::Collections::Generic;

ref class Airport
{
private:
	String^ id;
	String^ name;
	int parkingLots;
	bool isForInternationalFlights;
	List<Flight^>^ flights;
	List<Plane^>^ planes;
	List<Employee^>^ employees;

public:
	Airport(
		String^ id,
		String^ name,
		int parkingLots,
		bool isForInternationalFlights,
		List<Flight^>^ flights,
		List<Plane^>^ planes,
		List<Employee^>^ employees
	) {
		this->id;
		this->name = name;
		this->parkingLots = parkingLots;
		this->isForInternationalFlights = isForInternationalFlights;
		this->flights = gcnew List<Flight^>();
		this->planes = gcnew List<Plane^>();
		this->employees = gcnew List<Employee^>();
	}

	// ID
	void SetId(String^ id) { this->id = id; }
	String^ GetId() { return id; }

	// Name
	void SetName(String^ name) { this->name = name; }
	String^ GetName() { return name; }

	// Parking Lots
	void SetParkingLots(int parkingLots) { this->parkingLots = parkingLots; }
	int GetParkingLots() { return parkingLots; }

	// Is For International Flights
	void SetIsForInternationalFlights(bool isForInternationalFlights) { this->isForInternationalFlights = isForInternationalFlights; }
	bool GetIsForInternationalFlights() { return isForInternationalFlights; }

	// Flights
	void SetFlights(List<Flight^>^ flights) { this->flights = flights != nullptr ? flights : gcnew List<Flight^>(); }
	List<Flight^>^ GetFlights() { return flights; }

	// Planes
	void SetPlanes(List<Plane^>^ planes) { this->planes = planes != nullptr ? planes : gcnew List<Plane^>(); }
	List<Plane^>^ GetPlanes() { return planes; }

	// Employees
	void SetEmployees(List<Employee^>^ employees) { this->employees = employees != nullptr ? employees : gcnew List<Employee^>(); }
	List<Employee^>^ GetEmployees() { return employees; }

	String^ ToString() override {
		return "ID: " + id + ", Name: " + name + ", Parking Lots: " + parkingLots +
			", International: " + (isForInternationalFlights ? "Yes" : "No") +
			", Employees: " + employees->Count + ", Flights: " + flights->Count +
			", Planes: " + planes->Count;
	}
};

