#pragma once
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

void initializeDatabase(sql::Connection* conn) {
    try {
        conn->setSchema("");
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        stmt->execute("CREATE DATABASE IF NOT EXISTS dbAirport");

        conn->setSchema("dbAirport");

        stmt->execute("CREATE TABLE IF NOT EXISTS Users ("
            "id INT AUTO_INCREMENT PRIMARY KEY, "
            "name VARCHAR(255) NOT NULL, "
            "email VARCHAR(255) UNIQUE NOT NULL, "
            "password_hash VARCHAR(255) NOT NULL)");

        stmt->execute("CREATE TABLE IF NOT EXISTS Tasks ("
            "id INT AUTO_INCREMENT PRIMARY KEY, "
            "user_id INT NOT NULL, "
            "description TEXT NOT NULL, "
            "status ENUM('pending', 'completed') DEFAULT 'pending', "
            "FOREIGN KEY (user_id) REFERENCES Users(id) "
            "ON DELETE CASCADE)");

    }
    catch (sql::SQLException& e) {
        std::cerr << "B³¹d inicjalizacji bazy danych: " << e.what() << "\n";
        throw;
    }
}