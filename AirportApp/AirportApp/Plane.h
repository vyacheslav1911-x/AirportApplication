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

    string getId() const {
        return this->id;
    }

    string getName() const {
        return this->name;
    }

    string getModelName() const {
        return this->modelName;
    }

    string getColor() const {
        return this->color;
    }

    string getType() const {
        return this->type;
    }

    int getPlaces() const {
        return this->places;
    }

    int getAvailablePlaces() const {
        return this->availablePlaces;
    }

    int getSpeed() const {
        return this->speed;
    }

    bool getIsAvailable() const {
        return this->isAvailable;
    }

    optional<std::chrono::system_clock::time_point> getArrival() const {
        return this->arrival;
    }

    optional<std::chrono::system_clock::time_point> getDeparture() const {
        return this->departure;
    }
};