#include "Plane.h"
#include <chrono>
#include "FormatDate.h"

Plane::Plane(
    const string& id,
    const string& name,
    const string& modelName,
    const string& color,
    const string& type,
    const int& places,
    const int& availablePlaces,
    const int& speed,
    const bool& isAvailable,
    const optional<std::chrono::system_clock::time_point>& arrival,
    const optional<std::chrono::system_clock::time_point>& departure
) : id(id), 
    name(name), 
    modelName(modelName), 
    color(color), type(type), 
    places(places), 
    availablePlaces(availablePlaces), 
    speed(speed), 
    isAvailable(isAvailable),
    arrival(arrival), 
    departure(departure) {}

void Plane::boardPassenger() {
    if (availablePlaces > 0) {
        availablePlaces--;
        cout << "Passenger has boarded the plane" << endl;
    }
    else {
        cout << "Plane is full" << endl;
    }
}

int Plane::getAvailablePlaces() {
    return availablePlaces;
}

void Plane::printPlaneInformation() const {
    cout << "--- Plane Information --- " << endl;
    cout << "Id: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "Model Name: " << this->modelName << endl;
    cout << "Color: " << this->color << endl;
    cout << "Type: " << this->type << endl;
    cout << "Total Places: " << this->places << endl;
    cout << "Available Places: " << this->availablePlaces << endl;
    cout << "Speed: " << this->speed << endl;
    cout << "Is available" << (this->isAvailable ? "Yes" : "No") << endl;
    cout << "Arrival: " << formatDate(this->arrival) << endl;
    cout << "Departure: " << formatDate(this->arrival) << endl;
}
