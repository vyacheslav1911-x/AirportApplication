#pragma once

using namespace System;

ref class Flight
{
private:
	String^ id;
	DateTime departureTime;
	DateTime arrivalTime;
	String^ departurePlace;
	String^ arrivalPlace;

public:
	Flight(String^ id, DateTime departureTime, DateTime arrivalTime, String^ departurePlace, String^ arrivalPlace) {
		this->id = id;
		this->departureTime = departureTime;
		this->arrivalTime = arrivalTime;
		this->departurePlace = departurePlace;
		this->arrivalPlace = arrivalPlace;
	}

	Flight(String^ id, DateTime departureTime, DateTime arrivalTime) {
		this->id = id;
		this->departureTime = departureTime;
		this->arrivalTime = arrivalTime;
		this->departurePlace = nullptr;
		this->arrivalPlace = nullptr;
	}

	// ID
	void SetId(String^ id) { this->id = id; }
	String^ GetId() { return id; }

	// Departure Time
	void SetDepartureTime(DateTime departureTime) { this->departureTime = departureTime; }
	DateTime GetDepartureTime() { return departureTime; }

	// Arrival Time
	void SetArrivalTime(DateTime arrivalTime) { this->arrivalTime = arrivalTime; }
	DateTime GetArrivalTime() { return arrivalTime; }

	// Departure Place
	void SetDeparturePlace(String^ departurePlace) { this->departurePlace = departurePlace; }
	String^ GetDeparturePlace() { return departurePlace != nullptr ? departurePlace : "N/A"; }

	// Arrival Place
	void SetArrivalPlace(String^ arrivalPlace) { this->arrivalPlace = arrivalPlace; }
	String^ GetArrivalPlace() { return arrivalPlace != nullptr ? arrivalPlace : "N/A"; }

	String^ ToString() override {
		return "Flight ID: " + id +
			", Departure: " + (departurePlace != nullptr ? departurePlace : "N/A") +
			", Arrival: " + (arrivalPlace != nullptr ? arrivalPlace : "N/A") +
			", Departure Time: " + departureTime.ToString("yyyy-MM-dd HH:mm") +
			", Arrival Time: " + arrivalTime.ToString("yyyy-MM-dd HH:mm");
	}
};

