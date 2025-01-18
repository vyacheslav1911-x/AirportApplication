#include "Plane.h"

Plane::Plane(
    string id,
    string name,
    string modelName,
    string color,
    string type,
    int places,
    int availablePlaces,
    int speed,
    optional<string> arrival,
    optional<string> departure
) : id(id), name(name), modelName(modelName), color(color), type(type), places(places), availablePlaces(availablePlaces), speed(speed), arrival(arrival), departure(departure) {}

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
    cout << "Id: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "Model Name: " << this->modelName << endl;
    cout << "Color: " << this->color << endl;
    cout << "Type: " << this->type << endl;
    cout << "Total Places: " << this->places << endl;
    cout << "Available Places: " << this->availablePlaces << endl;
    cout << "Arrival: " << this->arrival.value_or("NULL") << endl;
    cout << "Departure: " << this->departure.value_or("NULL") << endl;
}
