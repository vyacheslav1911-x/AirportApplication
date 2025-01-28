#pragma once
#include <string>
#include "Plane.h"
#include "Passenger.h"


ref class Ticket
{
private:
    String^ id;
    String^ departurePlace;
    String^ arrivalPlace;
    DateTime^ departureTime;
    DateTime^ arrivalTime;
    Plane^ plane;
    Passenger^ passenger;

public:
    Ticket(String^ id, String^ departurePlace, String^ arrivalPlace, DateTime^ departureTime, DateTime^ arrivalTime, Plane^ plane, Passenger^ passenger) {
        this->id = id;
        this->departurePlace = departurePlace;
        this->arrivalPlace = arrivalPlace;
        this->departureTime = departureTime;
        this->arrivalTime = arrivalTime;
        this->plane = plane;
        this->passenger = passenger;
    }

    // ID
    void SetId(String^ id) { this->id = id; }
    String^ GetId() { return id; }

    // Departure Place
    void SetDeparturePlace(String^ departurePlace) { this->departurePlace = departurePlace; }
    String^ GetDeparturePlace() { return departurePlace; }

    // Arrival Place
    void SetArrivalPlace(String^ arrivalPlace) { this->arrivalPlace = arrivalPlace; }
    String^ GetArrivalPlace() { return arrivalPlace; }

    // Departure Time
    void SetDepartureTime(DateTime^ departureTime) { this->departureTime = departureTime; }
    DateTime^ GetDepartureTime() { return departureTime; }

    // Arrival Time
    void SetArrivalTime(DateTime^ arrivalTime) { this->arrivalTime = arrivalTime; }
    DateTime^ GetArrivalTime() { return arrivalTime; }

    // Plane
    void SetPlane(Plane^ plane) { this->plane = plane; }
    Plane^ GetPlane() { return plane; }

    // Passenger
    void SetPassenger(Passenger^ passenger) { this->passenger = passenger; }
    Passenger^ GetPassenger() { return passenger; }

    String^ ToString() override {
        return "Ticket ID: " + id +
            ", Departure: " + departurePlace +
            ", Arrival: " + arrivalPlace +
            ", Departure Time: " + departureTime->ToString("yyyy-MM-dd HH:mm") +
            ", Arrival Time: " + arrivalTime->ToString("yyyy-MM-dd HH:mm") +
            ", Plane: " + (plane != nullptr ? plane->ToString() : "N/A") +
            ", Passenger: " + (passenger != nullptr ? passenger->ToString() : "N/A");
    }
};

