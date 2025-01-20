#include "Flight.h"
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "FormatDate.h"

Flight::Flight(
	const string& flightId,
	const optional<std::chrono::system_clock::time_point>& arrival,
	const optional<std::chrono::system_clock::time_point>& departure,
	const Plane& plane
) : flightId(flightId), arrival(arrival), departure(departure), plane(plane) {
}

void Flight::printFlightInfo(int id) const {
	cout << "Flight number: " << id << endl;

	cout << "--- Plane Information ---" << endl;
	plane.printPlaneInformation();
};

void Flight::addFlight(const string& databaseName, const string&user, const string& password, const Plane& plane) const{
	try
	{
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
		unique_ptr<sql::Connection> conn(driver->connect("tcp://127.0.0.1:3306", user, password));
		conn->setSchema(databaseName);

		
		unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("INSERT INTO flights (flight_id, arrival, departure, plane_name, plane_model_name, plane_color, plane_type, plane_places, plane_available_places, plane_speed) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));
	
		pstmt->setString(1, flightId);
		pstmt->setDateTime(2, formatDate(arrival));
		pstmt->setDateTime(3, formatDate(departure));

		pstmt->executeUpdate();

		cout << "Flight " << this->flightId << " added successfully" << endl;
		
	}
	catch (const std::exception&)
	{

	}
}


