#include "MyForm.h"
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include "InitDb.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	try {
		sql::Driver* driver = get_driver_instance();
		std::unique_ptr<sql::Connection> conn(driver->connect("tcp://127.0.0.1:3306", "root", "rootroot"));

		initializeDatabase(conn.get());
	}
	catch (sql::SQLException &e) {
		std::cerr << "B³¹d po³¹czenia z baz¹ danych: " << e.what() << "\n";
	}

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AirportCLRProject::MyForm form;
	Application::Run(% form);
}