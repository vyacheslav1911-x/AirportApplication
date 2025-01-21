#include "Employee.h"
#include <string>

Employee::Employee(
	const std::string& id,
	const std::string& firstName,
	const std::string& lastName,
	const std::string& position,
	const int& age,
	const std::string& email,
	const std::string& phoneNumber,
	const double& salary
) : id(id), 
	firstName(firstName), 
	lastName(lastName), 
	position(position), 
	age(age),
	email(email),
	phoneNumber(phoneNumber),
	salary(salary) {}