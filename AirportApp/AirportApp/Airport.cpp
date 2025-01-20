#include "Airport.h"
#include <string>
#include <vector>

Airport::Airport(
	const string& id,
	const string& name,
	const int& parkingLots,
	const bool& isForInternationalFlights,
	const optional<std::vector<Flight>>& flights,
	const optional<std::vector<Plane>>& planes,
	Employee*& employees
) : id(id), 
	name(name), 
	parkingLots(parkingLots),
	isForInternationalFlights(isForInternationalFlights),
	flights(flights),
	planes(planes),
	employees(employees) {}

void Airport::createPlain(const Plane& plane) {
	Plane* plane = new Plane(plane);
	planes->push_back(plane);
}