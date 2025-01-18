#include <iostream>
#include <string>
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
    optional<string> arrival;
    optional<string> departure;

public:
    Plane(string id, string name, string modelName, string color, string type, int places, int availablePlaces, int speed, optional<string> arrival, optional<string> departure);
    void boardPassenger();
    void printPlaneInformation() const;
    int getAvailablePlaces();
};