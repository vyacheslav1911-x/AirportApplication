#include <iostream>
#include <string>
#include <chrono>
#include <optional>
#pragma once

using namespace std;

class Plane
{
private:
    string id;
    string name;
    string modelName;
    string color;
    string type;
    int places;
    int availablePlaces;
    int speed;
    bool isAvailable;
    optional<std::chrono::system_clock::time_point> arrival;
    optional<std::chrono::system_clock::time_point> departure;

public:
    Plane();
    Plane(const string& id, 
        const string& name, 
        const string& modelName, 
        const string& color, 
        const string& type, 
        const int& places, 
        const int& availablePlaces, 
        const int& speed, 
        const bool& isAvailable,
        const optional<std::chrono::system_clock::time_point>& arrival, 
        const optional<std::chrono::system_clock::time_point>& departure);
    void boardPassenger();
    void printPlaneInformation() const;
    int getAvailablePlaces();

    void setId(const string& id) {
        this->id = id;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setModelName(const string& modelName) {
        this->modelName = modelName;
    }

    void setColor(const string& color) {
        this->color = color;
    }

    void setType(const string& type) {
        this->type = type;
    }

    void setPlaces(const int& places) {
        this->places = places;
    }

    void setAvailablePlaces(const int& availablePlaces) {
        this->availablePlaces = availablePlaces;
    }

    void setSpeed(const int& speed) {
        this->speed = speed;
    }

    void setIsAvailable(const bool& isAvailable) {
        this->isAvailable = isAvailable;
    }

    void setArrival(const optional<std::chrono::system_clock::time_point> arrival) {
        this->arrival = arrival;
    }

    void setDeparture(const optional<std::chrono::system_clock::time_point> departure) {
        this->departure = departure;
    }

    string getId() {
        return this->id;
    }

    string getName() {
        return this->name;
    }

    string getModelName() {
        return this->modelName;
    }

    string getColor() {
        return this->color;
    }

    string getType() {
        return this->type;
    }

    int getPlaces() {
        return this->places;
    }

    int getAvailablePlaces() {
        return this->availablePlaces;
    }

    int getSpeed() {
        return this->speed;
    }

    optional<std::chrono::system_clock::time_point> getArrival() {
        return this->arrival;
    }

    optional<std::chrono::system_clock::time_point> getDeparture() {
        return this->departure;
    }
};