#include <iostream>
#include <string>
#pragma once

using namespace std;

class Employee
{
protected:
	string id;
	string firstName;
	string lastName;
	string position;
	int age;
	string email;
	string phoneNumber;
	double salary;

public:
	Employee(
		string id,
		string firstName,
		string lastName,
		string position,
		int age,
		string email,
		string phoneNumber,
		double salary
		);

	// setters
	void setFirstName(const string& firstName) {
		this->firstName = firstName;
	}

	void setLastName(const string& lastName) {
		this->lastName = lastName;
	}

	void setPosition(const string& position) {
		this->position = position;
	}

	void setAge(const int& age) {
		this->age = age;
	}
	void setEmail(const string& email) {
		this->email = email;
	}
	void setPhoneNumber(const string& phoneNumber) {
		this->phoneNumber = phoneNumber;
	}
	void setSalary(const double& salary) {
		this->salary = salary;
	}

	// getters
	string getId() const {
		return this->id;
	}

	string getFirstName() const {
		return this->firstName;
	}

	string getLastName() const {
		return this->lastName;
	}

	string getPosition() const {
		return this->position;
	}

	int getAge() const {
		return this->age;
	}

	string getEmail() const {
		return this->email;
	}

	string getPhoneNumber() const {
		return this->phoneNumber;
	}

	double getSalary() const {
		return this->salary;
	}

	void printEmployeeInformation() const {
		cout << "--- Employee Information ---" << endl;
		cout << "Id: " << this->id << endl;
	}
	void promote(const string& newPosition, double salaryIncrease) {
		this->position = newPosition;
		this->salary = salaryIncrease;
	}
	double calculateAnnualSalary() const {
		return salary * 12;
	}
};

