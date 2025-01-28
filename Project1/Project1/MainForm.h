#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <mysql_driver.h>
#include <driver.h>
#pragma once

namespace AirportDesktopApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ flightListButton;
	protected:
	private: System::Windows::Forms::Button^ ticketsListButton;
	private: System::Windows::Forms::Button^ employeesListButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->flightListButton = (gcnew System::Windows::Forms::Button());
			this->ticketsListButton = (gcnew System::Windows::Forms::Button());
			this->employeesListButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// flightListButton
			// 
			this->flightListButton->Location = System::Drawing::Point(61, 81);
			this->flightListButton->Name = L"flightListButton";
			this->flightListButton->Size = System::Drawing::Size(150, 46);
			this->flightListButton->TabIndex = 0;
			this->flightListButton->Text = L"Lista lotów";
			this->flightListButton->UseVisualStyleBackColor = true;
			this->flightListButton->Click += gcnew System::EventHandler(this, &MainForm::flightListButton_Click);
			// 
			// ticketsListButton
			// 
			this->ticketsListButton->Location = System::Drawing::Point(61, 153);
			this->ticketsListButton->Name = L"ticketsListButton";
			this->ticketsListButton->Size = System::Drawing::Size(150, 46);
			this->ticketsListButton->TabIndex = 1;
			this->ticketsListButton->Text = L"Lista biletów";
			this->ticketsListButton->UseVisualStyleBackColor = true;
			this->ticketsListButton->Click += gcnew System::EventHandler(this, &MainForm::ticketsListButton_Click);
			// 
			// employeesListButton
			// 
			this->employeesListButton->Location = System::Drawing::Point(61, 223);
			this->employeesListButton->Name = L"employeesListButton";
			this->employeesListButton->Size = System::Drawing::Size(150, 46);
			this->employeesListButton->TabIndex = 2;
			this->employeesListButton->Text = L"Lista pracowników";
			this->employeesListButton->UseVisualStyleBackColor = true;
			this->employeesListButton->Click += gcnew System::EventHandler(this, &MainForm::employeesListButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(337, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 46);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Dodaæ pracownika";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(337, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 46);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Dodaæ samolot";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(337, 223);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 46);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Sprzedaæ bilet";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(61, 301);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(150, 46);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Lista samolotów";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(223, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 29);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Lotnisko";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 438);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->employeesListButton);
			this->Controls->Add(this->ticketsListButton);
			this->Controls->Add(this->flightListButton);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void flightListButton_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string host = "tcp://127.0.0.1:3306";
		const char* server = "localhost";
		const char* user = "root";
		const char* password = "rootroot";
		const char* database = "airport_db";

		try {
			sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
			std::unique_ptr<sql::Connection> connection(driver->connect(host, user, password));
			connection->setSchema(database);

			std::string query = "SELECT * FROM planes";

			std::unique_ptr<sql::Statement> statement(connection->createStatement());
			std::unique_ptr<sql::ResultSet> resultSet(statement->executeQuery(query));

			std::stringstream airplaneList;
			while (resultSet->next()) {
				std::string id = resultSet->getString("id");
				std::string departureTime = resultSet->getString("departure_time");
				std::string arrivalTime = resultSet->getString("arrival_time");
				std::string departurePlace = resultSet->getString("departure_place");
				std::string arrivalPlace = resultSet->getString("arrival_place");

				airplaneList << "ID: " << id << "| Departure time: " << departureTime << "| Arrival time: " << arrivalTime << "| Departure place: " << departurePlace << "| Arrival place: " << arrivalPlace << "\n";
			}

			if (airplaneList.str().empty()) {
				MessageBox::Show("No airplanes found in the database.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show(gcnew System::String(airplaneList.str().c_str()), "Available Airplanes", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

		}
		catch (sql::SQLException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			MessageBox::Show("Failed to retrieve airplane data. Please check the database connection.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}	
	}
private: System::Void ticketsListButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string host = "tcp://127.0.0.1:3306";
	const char* server = "localhost";
	const char* user = "root";
	const char* password = "rootroot";
	const char* database = "airport_db";

	try {
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
		std::unique_ptr<sql::Connection> connection(driver->connect(host, user, password));
		connection->setSchema(database);

		std::string queryTickets = "SELECT * FROM tickets";
		std::string queryPlanes = "SELECT * FROM planes";

		std::unique_ptr<sql::Statement> statement(connection->createStatement());
		std::unique_ptr<sql::ResultSet> resultSetTickets(statement->executeQuery(queryTickets));
		std::unique_ptr<sql::ResultSet> resultSetPlanes(statement->executeQuery(queryPlanes));

		std::stringstream airplaneList;
		std::stringstream ticketList;
		while (resultSetTickets->next()) {
			std::string id = resultSetTickets->getString("id");
			std::string departureTime = resultSetTickets->getString("departure_time");
			std::string arrivalTime = resultSetTickets->getString("arrival_time");
			std::string departurePlace = resultSetTickets->getString("departure_place");
			std::string arrivalPlace = resultSetTickets->getString("arrival_place");
			std::string planeId = resultSetPlanes->getString("id");
			std::string planeName = resultSetPlanes->getString("name");
			std::string planeModel = resultSetPlanes->getString("model");
			std::string planeColor = resultSetPlanes->getString("color");
			std::string planeType = resultSetPlanes->getString("type");
			int planePlaces = resultSetPlanes->getInt("places");
			int planeAvailablePlaces = resultSetPlanes->getInt("available_places");
			int planeSpeed = resultSetPlanes->getInt("speed");
			bool planeIsAvailable = resultSetPlanes->getBoolean("is_available");
			std::string planeDepartureTime = resultSetPlanes->getString("departure");
			std::string planeArrivalTime = resultSetPlanes->getString("arrival");

			airplaneList << "ID: " << id << "| Departure time: " << departureTime << "| Arrival Time: " << arrivalTime << "| Departure Place:" << departurePlace << "| Arrival Place: " << arrivalPlace << "\n";
		}

		if (airplaneList.str().empty()) {
			MessageBox::Show("No airplanes found in the database.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show(gcnew System::String(airplaneList.str().c_str()), "Available Airplanes", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}
	catch (sql::SQLException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		MessageBox::Show("Failed to retrieve airplane data. Please check the database connection.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void employeesListButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string host = "tcp://127.0.0.1:3306";
	const char* server = "localhost";
	const char* user = "root";
	const char* password = "password";
	const char* database = "airport_db";

	try {
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
		std::unique_ptr<sql::Connection> connection(driver->connect(host, user, password));
		connection->setSchema(database);

		std::string queryTickets = "SELECT * FROM tickets";
		std::string queryPlanes = "SELECT * FROM planes";

		std::unique_ptr<sql::Statement> statement(connection->createStatement());
		std::unique_ptr<sql::ResultSet> resultSetTickets(statement->executeQuery(queryTickets));
		std::unique_ptr<sql::ResultSet> resultSetPlanes(statement->executeQuery(queryPlanes));

		std::stringstream airplaneList;
		std::stringstream ticketList;
		while (resultSetTickets->next()) {
			std::string id = resultSetTickets->getString("id");
			std::string departureTime = resultSetTickets->getString("departure_time");
			std::string arrivalTime = resultSetTickets->getString("arrival_time");
			std::string departurePlace = resultSetTickets->getString("departure_place");
			std::string arrivalPlace = resultSetTickets->getString("arrival_place");
			std::string planeId = resultSetPlanes->getString("id");
			std::string planeName = resultSetPlanes->getString("name");
			std::string planeModel = resultSetPlanes->getString("model");
			std::string planeColor = resultSetPlanes->getString("color");
			std::string planeType = resultSetPlanes->getString("type");
			int planePlaces = resultSetPlanes->getInt("places");
			int planeAvailablePlaces = resultSetPlanes->getInt("available_places");
			int planeSpeed = resultSetPlanes->getInt("speed");
			bool planeIsAvailable = resultSetPlanes->getBoolean("is_available");
			std::string planeDepartureTime = resultSetPlanes->getString("departure");
			std::string planeArrivalTime = resultSetPlanes->getString("arrival");

			airplaneList << "ID: " << id << "| Departure time: " << departureTime << "| Arrival Time: " << arrivalTime << "| Departure Place:" << departurePlace << "| Arrival Place: " << arrivalPlace << "\n";
		}

		if (airplaneList.str().empty()) {
			MessageBox::Show("No airplanes found in the database.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show(gcnew System::String(airplaneList.str().c_str()), "Available Airplanes", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}
	catch (sql::SQLException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		MessageBox::Show("Failed to retrieve airplane data. Please check the database connection.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string host = "tcp://127.0.0.1:3306";
	const char* server = "localhost";
	const char* user = "root";
	const char* password = "password";
	const char* database = "airport_db";

	try {
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
		std::unique_ptr<sql::Connection> connection(driver->connect(host, user, password));
		connection->setSchema(database);

		std::string queryTickets = "SELECT * FROM tickets";
		std::string queryPlanes = "SELECT * FROM planes";

		std::unique_ptr<sql::Statement> statement(connection->createStatement());
		std::unique_ptr<sql::ResultSet> resultSetTickets(statement->executeQuery(queryTickets));
		std::unique_ptr<sql::ResultSet> resultSetPlanes(statement->executeQuery(queryPlanes));

		std::stringstream airplaneList;
		std::stringstream ticketList;
		while (resultSetTickets->next()) {
			std::string id = resultSetTickets->getString("id");
			std::string departureTime = resultSetTickets->getString("departure_time");
			std::string arrivalTime = resultSetTickets->getString("arrival_time");
			std::string departurePlace = resultSetTickets->getString("departure_place");
			std::string arrivalPlace = resultSetTickets->getString("arrival_place");
			std::string planeId = resultSetPlanes->getString("id");
			std::string planeName = resultSetPlanes->getString("name");
			std::string planeModel = resultSetPlanes->getString("model");
			std::string planeColor = resultSetPlanes->getString("color");
			std::string planeType = resultSetPlanes->getString("type");
			int planePlaces = resultSetPlanes->getInt("places");
			int planeAvailablePlaces = resultSetPlanes->getInt("available_places");
			int planeSpeed = resultSetPlanes->getInt("speed");
			bool planeIsAvailable = resultSetPlanes->getBoolean("is_available");
			std::string planeDepartureTime = resultSetPlanes->getString("departure");
			std::string planeArrivalTime = resultSetPlanes->getString("arrival");

			airplaneList << "ID: " << id << "| Departure time: " << departureTime << "| Arrival Time: " << arrivalTime << "| Departure Place:" << departurePlace << "| Arrival Place: " << arrivalPlace << "\n";
		}

		if (airplaneList.str().empty()) {
			MessageBox::Show("No airplanes found in the database.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show(gcnew System::String(airplaneList.str().c_str()), "Available Airplanes", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}
	catch (sql::SQLException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		MessageBox::Show("Failed to retrieve airplane data. Please check the database connection.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
