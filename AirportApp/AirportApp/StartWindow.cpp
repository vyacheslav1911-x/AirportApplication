﻿#include <iostream>
#include <string>
#include <vector>
#include "StartWindow.h"
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include "Plane.h"

using namespace std;

void viewPlanes();
void viewFlights();
void viewEmployees();
void addFlight();
void addPlane();
void sellTicket();
void addEmployee();

void showMenu();

void showWindow() {
	int choice;

    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewPlanes();
            break;
        case 2:
            viewFlights();
            break;
        case 3:
            viewEmployees();
            break;
        case 4:
            addFlight();
            break;
        case 5:
            addPlane();
            break;
        case 6:
            sellTicket();
            break;
        case 7:
            addEmployee();
            break;
        case 0:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << std::endl;
    } while (choice != 0);
}

void showMenu() {
    std::cout << "========== Airport Management ==========" << endl;
    std::cout << "1. View Planes" << endl;
    std::cout << "2. View Flights" << endl;
    std::cout << "3. View Employees" << endl;
    std::cout << "4. Add Flight" << endl;
    std::cout << "5. Add Plane" << endl;
    std::cout << "6. Sell Ticket" << endl;
    std::cout << "7. Add Employee" << endl;
    std::cout << "0. Exit" << endl;
    std::cout << "========================================" << endl;
}

void viewPlanes() {
    cout << "Viewing all planes..." << endl;

}

void viewFlights() {
    cout << "Viewing all flights..." << endl;
}

void viewEmployees() {
    std::cout << "Viewing all employees..." << endl;
    
}

void addFlight() {
    std::cout << "Adding a new flight..." << endl;
    // Реалізуйте логіку додавання нового польоту (запит даних у користувача, запис у базу даних)
}

void addPlane() {
    std::cout << "Adding a new plane..." << endl;;
    // Реалізуйте логіку додавання нового літака (запит даних у користувача, запис у базу даних)
}

void sellTicket() {
    std::cout << "Sell ticket for passenger..." << endl;
}

void addEmployee() {

}

std::vector<Plane> getPlanesFromDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
    std::vector<Plane> planes;

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));

        conn->setSchema(database);
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT id, name, modelName, color, type, places, availablePlaces, speed, arrival, departure FROM planes"));

        while (res->next()) {
            Plane plane;
            res->getString("id");

        }
    }
}