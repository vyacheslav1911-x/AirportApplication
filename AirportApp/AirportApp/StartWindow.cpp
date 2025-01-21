#include "Plane.h"
#include "Flight.h"
#include "Employee.h"
#include "StartWindow.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <mysql_driver.h>
#include <driver.h>

using namespace std;

const string HOST = "tcp://127.0.0.1:3306";
const string USER = "root";
const string PASSWORD = "rootroot";
const string DATABASE_NAME = "db";

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
    getPlanesFromDatabase(HOST, USER, PASSWORD, DATABASE_NAME);
}

void viewFlights() {
    cout << "Viewing all flights..." << endl;
    getFlightsFromDatabase(HOST, USER, PASSWORD, DATABASE_NAME);
}

void viewEmployees() {
    std::cout << "Viewing all employees..." << endl;
    getEmployeesFromDatabase(HOST, USER, PASSWORD, DATABASE_NAME);
}

void addFlight() {
    std::cout << "Adding a new flight..." << endl;
    addFlightInDatabase(HOST, USER, PASSWORD, DATABASE_NAME);
}

void addPlane() {
    std::cout << "Adding a new plane..." << endl;
    addPlaneInDatabase(HOST, USER, PASSWORD, DATABASE_NAME);
}

void sellTicket() {
    std::cout << "Sell ticket for passenger..." << endl;
    sellPassengerTicket(HOST, USER, PASSWORD, DATABASE_NAME);
}

void addEmployee() {
    std::cout << "Adding a new employee..." << endl;
    addEmployeeInDatabase(HOST, USER, PASSWORD, DATABASE_NAME);
}

std::vector<Plane> getPlanesFromDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
    std::vector<Plane> planes;

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));

        conn->setSchema(database);
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM planes"));

        while (res->next()) {
            Plane plane;
            res->getString("id");

        }
    }
    catch (const std::exception&) {

    }
}

std::vector<Flight> getFlightsFromDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
    std::vector<Flight> flights;

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));
        conn->setSchema(database);

        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(
            "SELECT f.flightId, f.arrival, f.departure, "
            "p.id AS planeId, p.name AS planeName, p.modelName, p.color, p.type, "
            "p.places, p.availablePlaces, p.speed, p.isAvailable, "
            "p.arrival AS planeArrival, p.departure AS planeDeparture "
            "FROM flights f "
            "JOIN planes p ON f.planeId = p.id"));

        while (res->next()) {
            Plane plane(
                res->getString("planeId"),
                res->getString("planeName"),
                res->getString("modelName"),
                res->getString("color"),
                res->getString("type"),
                res->getInt("places"),
                res->getInt("availablePlaces"),
                res->getInt("speed"),
                res->getBoolean("isAvailable"),
                res->isNull("planeArrival") ? std::nullopt : std::optional<std::chrono::system_clock::time_point>(std::chrono::system_clock::from_time_t(res->getInt64("planeArrival"))),
                res->isNull("planeDeparture") ? std::nullopt : std::optional<std::chrono::system_clock::time_point>(std::chrono::system_clock::from_time_t(res->getInt64("planeDeparture")))
            );

            Flight flight(
                res->getString("flightId"),
                res->isNull("arrival") ? std::nullopt : std::optional<std::chrono::system_clock::time_point>(std::chrono::system_clock::from_time_t(res->getInt64("arrival"))),
                res->isNull("departure") ? std::nullopt : std::optional<std::chrono::system_clock::time_point>(std::chrono::system_clock::from_time_t(res->getInt64("departure"))),
                plane
            );
            flights.push_back(flight);
        }
    } catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::vector<Employee> getEmployeesFromDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
    std::vector<Employee> employees;

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));

        conn->setSchema(database);
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM employees"));

        while (res->next()) {
            Employee employee;
            employee.setId(res->getString("id"));
            employee.setFirstName(res->getString("firstName"));
            employee.setLastName(res->getString("lastName"));
            employee.setPosition(res->getString("position"));
            employee.setAge(res->getInt("age"));
            employee.setEmail(res->getString("email"));
            employee.setPhoneNumber(res->getString("phoneNumber"));
            employee.setSalary(res->getDouble("salary"));

            employees.push_back(employee);
        }
    } catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << endl;
    }

    return employees;
}

void addFlightInDatabase(
    const std::string& host,
    const std::string& user,
    const std::string& password,
    const std::string& database) {

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));
        conn->setSchema(database);

        std::string flightId;
        std::string planeId;
        std::string arrivalStr, departureStr;
        std::cout << "Enter Flight ID: ";
        std::cin >> flightId;
        std::cout << "Enter Plane ID: ";
        std::cin >> planeId;
        std::cout << "Enter Arrival Time (YYYY-MM-DD HH:MM:SS): ";
        std::cin.ignore();
        std::getline(std::cin, arrivalStr);
        std::cout << "Enter Departure Time (YYYY-MM-DD HH:MM:SS): ";
        std::getline(std::cin, departureStr);

        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement(
                "INSERT INTO flights (flightId, planeId, arrival, departure) "
                "VALUES (?, ?, ?, ?)"
            )
        );

        pstmt->setString(1, flightId);
        pstmt->setString(2, planeId);
        pstmt->setString(3, arrivalStr);
        pstmt->setString(4, departureStr);

        int rowsAffected = pstmt->executeUpdate();
        if (rowsAffected > 0) {
            std::cout << "Flight added successfully." << std::endl;
        }
        else {
            std::cout << "Failed to add the flight." << std::endl;
        }
    }
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void addPlaneInDatabase(
    const std::string& host,
    const std::string& user,
    const std::string& password,
    const std::string& database) {

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));
        conn->setSchema(database);

        std::string planeId, name, modelName, color, type;
        int places, availablePlaces, speed;
        bool isAvailable;
        std::string arrivalStr, departureStr;

        std::cout << "Enter Plane ID: ";
        std::cin >> planeId;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Model Name: ";
        std::getline(std::cin, modelName);
        std::cout << "Enter Color: ";
        std::getline(std::cin, color);
        std::cout << "Enter Type: ";
        std::getline(std::cin, type);
        std::cout << "Enter Number of Seats: ";
        std::cin >> places;
        std::cout << "Enter Number of Available Seats: ";
        std::cin >> availablePlaces;
        std::cout << "Enter Speed: ";
        std::cin >> speed;
        std::cout << "Is Available (1 for Yes, 0 for No): ";
        std::cin >> isAvailable;
        std::cin.ignore();
        std::cout << "Enter Arrival Time (YYYY-MM-DD HH:MM:SS, or leave blank): ";
        std::getline(std::cin, arrivalStr);
        std::cout << "Enter Departure Time (YYYY-MM-DD HH:MM:SS, or leave blank): ";
        std::getline(std::cin, departureStr);

        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement(
                "INSERT INTO planes (id, name, modelName, color, type, places, availablePlaces, speed, isAvailable, arrival, departure) "
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
            )
        );

        pstmt->setString(1, planeId);
        pstmt->setString(2, name);
        pstmt->setString(3, modelName);
        pstmt->setString(4, color);
        pstmt->setString(5, type);
        pstmt->setInt(6, places);
        pstmt->setInt(7, availablePlaces);
        pstmt->setInt(8, speed);
        pstmt->setBoolean(9, isAvailable);

        if (arrivalStr.empty()) {
            pstmt->setNull(10, sql::DataType::TIMESTAMP);
        }
        else {
            pstmt->setString(10, arrivalStr);
        }

        if (departureStr.empty()) {
            pstmt->setNull(11, sql::DataType::TIMESTAMP);
        }
        else {
            pstmt->setString(11, departureStr);
        }

        int rowsAffected = pstmt->executeUpdate();
        if (rowsAffected > 0) {
            std::cout << "Plane added successfully." << std::endl;
        }
        else {
            std::cout << "Failed to add the plane." << std::endl;
        }
    }
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void sellPassengerTicket(
    const std::string& host,
    const std::string& user,
    const std::string& password,
    const std::string& database) {

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));
        conn->setSchema(database);

        std::string flightId, passengerName, passengerEmail;
        std::cout << "Enter Flight ID: ";
        std::cin >> flightId;
        std::cout << "Enter Passenger Name: ";
        std::cin.ignore();
        std::getline(std::cin, passengerName);
        std::cout << "Enter Passenger Email: ";
        std::getline(std::cin, passengerEmail);

        std::unique_ptr<sql::PreparedStatement> checkSeatsStmt(
            conn->prepareStatement("SELECT availablePlaces FROM flights WHERE flightId = ?")
        );
        checkSeatsStmt->setString(1, flightId);
        std::unique_ptr<sql::ResultSet> res(checkSeatsStmt->executeQuery());

        if (!res->next()) {
            std::cout << "Flight not found." << std::endl;
            return;
        }

        int availablePlaces = res->getInt("availablePlaces");
        if (availablePlaces <= 0) {
            std::cout << "No available seats for this flight." << std::endl;
            return;
        }

        std::unique_ptr<sql::PreparedStatement> updateSeatsStmt(
            conn->prepareStatement("UPDATE flights SET availablePlaces = availablePlaces - 1 WHERE flightId = ?")
        );
        updateSeatsStmt->setString(1, flightId);
        int rowsAffected = updateSeatsStmt->executeUpdate();
        if (rowsAffected == 0) {
            std::cout << "Failed to update available seats." << std::endl;
            return;
        }

        std::unique_ptr<sql::PreparedStatement> insertTicketStmt(
            conn->prepareStatement(
                "INSERT INTO tickets (flightId, passengerName, passengerEmail) VALUES (?, ?, ?)"
            )
        );
        insertTicketStmt->setString(1, flightId);
        insertTicketStmt->setString(2, passengerName);
        insertTicketStmt->setString(3, passengerEmail);

        rowsAffected = insertTicketStmt->executeUpdate();
        if (rowsAffected > 0) {
            std::cout << "Ticket sold successfully to " << passengerName << "!" << std::endl;
        }
        else {
            std::cout << "Failed to sell the ticket." << std::endl;
        }
    }
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void addEmployeeInDatabase(
    const std::string& host,
    const std::string& user,
    const std::string& password,
    const std::string& database) {

    try {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect(host, user, password));
        conn->setSchema(database);

        std::string employeeId, firstName, lastName, position, email, phoneNumber;
        int age;
        double salary;

        std::cout << "Enter Employee ID: ";
        std::cin >> employeeId;
        std::cout << "Enter First Name: ";
        std::cin.ignore();
        std::getline(std::cin, firstName);
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);
        std::cout << "Enter Position: ";
        std::getline(std::cin, position);
        std::cout << "Enter Age: ";
        std::cin >> age;
        std::cout << "Enter Email: ";
        std::cin.ignore();
        std::getline(std::cin, email);
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Enter Salary: ";
        std::cin >> salary;

        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement(
                "INSERT INTO employees (id, firstName, lastName, position, age, email, phoneNumber, salary) "
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?)"
            )
        );

        pstmt->setString(1, employeeId);
        pstmt->setString(2, firstName);
        pstmt->setString(3, lastName);
        pstmt->setString(4, position);
        pstmt->setInt(5, age);
        pstmt->setString(6, email);
        pstmt->setString(7, phoneNumber);
        pstmt->setDouble(8, salary);

        int rowsAffected = pstmt->executeUpdate();
        if (rowsAffected > 0) {
            std::cout << "Employee added successfully." << std::endl;
        }
        else {
            std::cout << "Failed to add the employee." << std::endl;
        }
    }
    catch (const sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << " (MySQL error code: " << e.getErrorCode() << ")" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}