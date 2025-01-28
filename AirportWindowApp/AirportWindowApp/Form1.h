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
#include <sstream>
#include <vector>
#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			std::string host = "tcp://127.0.0.1:3306";
			std::string user = "root";
			std::string password = "rootroot";
			std::string dbName = "airport_db";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;


	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Lista samolot�w";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(60, 171);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 51);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Lista lot�w";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(60, 243);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 51);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Lista pracownik�w";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(276, 171);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(156, 51);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Doda� pracownika";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(276, 96);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(156, 51);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Doda� samolot";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(60, 314);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(156, 51);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Lista bilet�w";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(497, 96);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(156, 51);
			this->button7->TabIndex = 9;
			this->button7->Text = L"Sprzeda� bilet";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(328, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 29);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Lotnisko";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(777, 466);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string host = "tcp://127.0.0.1:3306";
		const char* server = "localhost";     
		const char* user = "root";             
		const char* password = "password";    
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
				std::string name = resultSet->getString("name");
				std::string model = resultSet->getString("model");

				airplaneList << "ID: " << id << "| Name: " << name << "| Model: " << model << "| " << "\n";
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
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
