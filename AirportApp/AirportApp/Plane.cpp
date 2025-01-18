#include "Plane.h"

Plane::Plane(
    string name,
    string modelName,
    string color,
    string type,
    int places,
    int availablePlaces,
    int speed,
    optional<string> arrival,
    optional<string> departure
) : name(name), modelName(modelName), color(color), type(type), places(places), availablePlaces(availablePlaces), speed(speed), arrival(arrival), departure(departure) {}

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
    cout << "Plane Information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Model Name: " << modelName << endl;
    cout << "Color: " << color << endl;
    cout << "Type: " << type << endl;
    cout << "Total Places: " << places << endl;
    cout << "Available Places: " << availablePlaces << endl;
    if (arrival.has_value()) {
        cout << "Arrival: " << arrival.value() << endl;
    }
    else {
        cout << "Arrival: Not available" << endl;
    }

    if (departure.has_value()) {
        cout << "Departure: " << *departure << endl;
    }
    else {
        cout << "Departure: Not available" << endl;
    }
}
