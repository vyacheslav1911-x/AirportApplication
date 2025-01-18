#include "Flight.h"
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

Flight::Flight(
	string flightId,
	optional<string> arrival,
	optional<string> departure,
	const Plane& plane
) : flightId(flightId), arrival(arrival), departure(departure), plane(plane) {
}

void Flight::printFlightInfo() const {
	cout << "Flight number: " << flightId << endl;
	if (arrival.has_value()) {
		cout << "Arrival: " << arrival.value() << endl;
	}
	else {
		cout << "Arrival: Not available" << endl;
	}
	if (departure.has_value()) {
		cout << "Departure: " << departure.value() << endl;
	}
	else {
		cout << "Departure: Not available" << endl;
	}
	cout << "--- Plane Information ---" << endl;
	plane.printPlaneInformation();
}

void Flight::addFlight(const string& databaseName, const string&user, const string& password) const{
	try
	{
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
		unique_ptr<sql::Connection> conn(driver->connect("tcp://127.0.0.1:3306", user, password));
		conn->setSchema(databaseName);

		
		unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("INSERT INTO flights (flight_id, arrival, departure, plane_name, plane_model_name, plane_color, plane_type, plane_places, plane_available_places, plane_speed) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));
	
		pstmt->setString(1, flightId);
		pstmt->setString(2, arrival.value_or("NULL"));
		pstmt->setString(3, departure.value_or("NULL"));


		pstmt->executeUpdate();

		cout << "Flight " << this->flightId << " added successfully" << endl;
		
	}
	catch (const std::exception&)
	{

	}
}


