#include "Plane.h"
#include "Flight.h"
#include <vector>
#pragma once

using namespace std;

void viewPlanes();
void viewFlights();
void viewEmployees();
void addFlight();
void addPlane();
void sellTicket();
void addEmployee();

void showWindow();

std::vector<Plane> getPlanesFromDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
std::vector<Flight> getFlightsFromDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
std::vector<Flight> getEmployeesFromDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
void addEmployeeInDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
void addPlaneInDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
void sellPassengerTicket(const std::string& host, const std::string& user, const std::string& password, const std::string& database);