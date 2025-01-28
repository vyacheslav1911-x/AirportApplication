#include "pch.h"
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <mysql_driver.h>
#include <driver.h>

// #include "Form1.h"

void InitializeDatabase(const std::string& host, const std::string& user, const std::string& password, const std::string& dbName) {
	try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> connection(driver->connect(host, user, password));
        std::unique_ptr<sql::Statement> statement(connection->createStatement());

        std::string checkDbQuery = "SHOW DATABASES LIKE '" + dbName + "'";
        std::unique_ptr<sql::ResultSet> resultSet(statement->executeQuery(checkDbQuery));

        if (!resultSet->next()) {
            std::cout << "Database does not exist. Creating a new one..." << std::endl;
            statement->execute("CREATE DATABASE " + dbName);
            std::cout << "Database " << dbName << " created successfully." << std::endl;
        }
        else {
            std::cout << "Database " << dbName << " already exists. Connecting to it..." << std::endl;
        }

        connection->setSchema(dbName);
        std::cout << "Connected to database " << dbName << "." << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}