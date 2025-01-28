#pragma once
#include <string>
#include <optional>
#include <chrono>
#include <msclr/marshal_cppstd.h>

using namespace System;

ref class Plane
{
private:
	String^ id;
	String^ name;
	String^ modelName;
	String^ color;
	String^ type;                           
	int places;                            
	int availablePlaces;                     
	int speed; 
	bool isAvailable;
	DateTime^ arrival;
	DateTime^ departure;

public:
	Plane(String^ id, String^ name, String^ modelName, String^ color, String^ type, int places, int availablePlaces, int speed, bool isAvailable) {
		this->id = id;
		this->name = name;
		this->modelName = modelName;
		this->color = color;
		this->type = type;
		this->places = places;
		this->availablePlaces = availablePlaces;
		this->speed = speed;
		this->isAvailable = isAvailable;
		this->arrival = nullptr;
		this->departure = nullptr;
	}

	// ID
	void SetId(String^ id) { this->id = id; }
	String^ GetId() { return id; }

	// Name
	void SetName(String^ name) { this->name = name; }
	String^ GetName() { return name; }

	// Model Name
	void SetModelName(String^ modelName) { this->modelName = modelName; }
	String^ GetModelName() { return modelName; }

	// Color
	void SetColor(String^ color) { this->color = color; }
	String^ GetColor() { return color; }

	// Type
	void SetType(String^ type) { this->type = type; }
	String^ GetType() { return type; }

	// Places
	void SetPlaces(int places) { this->places = places; }
	int GetPlaces() { return places; }

	// Available Places
	void SetAvailablePlaces(int availablePlaces) { this->availablePlaces = availablePlaces; }
	int GetAvailablePlaces() { return availablePlaces; }

	// Speed
	void SetSpeed(int speed) { this->speed = speed; }
	int GetSpeed() { return speed; }

	// Is Available
	void SetIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }
	bool GetIsAvailable() { return isAvailable; }

	// Arrival
	void SetArrival(DateTime^ arrivalTime) { this->arrival = arrivalTime; }
	DateTime^ GetArrival() { return arrival; }
	String^ GetArrivalString() { return arrival != nullptr ? arrival->ToString("yyyy-MM-dd HH:mm:ss") : "N/A"; }

	// Departure
	void SetDeparture(DateTime^ departureTime) { this->departure = departureTime; }
	DateTime^ GetDeparture() { return departure; }
	String^ GetDepartureString() { return departure != nullptr ? departure->ToString("yyyy-MM-dd HH:mm:ss") : "N/A"; }


	String^ ToString() override {
		return "ID: " + id +
			", Name: " + name +
			", Model: " + modelName +
			", Color: " + color +
			", Type: " + type +
			", Total Places: " + places +
			", Available Places: " + availablePlaces +
			", Speed: " + speed +
			", Is Available: " + (isAvailable ? "Yes" : "No") +
			", Arrival: " + GetArrivalString() +
			", Departure: " + GetDepartureString();
	}

private:
	String^ GetArrivalString() {
		return arrival != nullptr ? arrival->ToString("yyyy-MM-dd HH:mm:ss") : "N/A";
	}

	String^ GetDepartureString() {
		return departure != nullptr ? departure->ToString("yyyy-MM-dd HH:mm:ss") : "N/A";
	}
};

