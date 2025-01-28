#pragma once

using namespace System;
using namespace System::Collections::Generic;

ref class Employee
{
private:
    String^ id;
    String^ firstName;
    String^ lastName;
    String^ position;
    int age;
    String^ email;
    String^ phoneNumber;
    double salary;

public:
    Employee(String^ id, String^ firstName, String^ lastName, String^ position, int age, String^ email, String^ phoneNumber, double salary) {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->position = position;
        this->age = age;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->salary = salary;
    }

    // ID
    void SetId(String^ id) { this->id = id; }
    String^ GetId() { return id; }

    // First Name
    void SetFirstName(String^ firstName) { this->firstName = firstName; }
    String^ GetFirstName() { return firstName; }

    // Last Name
    void SetLastName(String^ lastName) { this->lastName = lastName; }
    String^ GetLastName() { return lastName; }

    // Position
    void SetPosition(String^ position) { this->position = position; }
    String^ GetPosition() { return position; }

    // Age
    void SetAge(int age) { this->age = age; }
    int GetAge() { return age; }

    // Email
    void SetEmail(String^ email) { this->email = email; }
    String^ GetEmail() { return email; }

    // Phone Number
    void SetPhoneNumber(String^ phoneNumber) { this->phoneNumber = phoneNumber; }
    String^ GetPhoneNumber() { return phoneNumber; }

    // Salary
    void SetSalary(double salary) { this->salary = salary; }
    double GetSalary() { return salary; }

    String^ ToString() override {
        return "ID: " + id +
            ", Name: " + firstName + " " + lastName +
            ", Position: " + position +
            ", Age: " + age +
            ", Email: " + email +
            ", Phone: " + phoneNumber +
            ", Salary: $" + salary.ToString("F2");
    }
};

