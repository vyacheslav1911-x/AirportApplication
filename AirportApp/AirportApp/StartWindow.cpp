#include <iostream>
#include <string>
#include "StartWindow.h"

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
    // Реалізуйте логіку перегляду співробітників (зчитування з бази даних, вивід у консоль)
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