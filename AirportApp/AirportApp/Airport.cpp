#include "Airport.h"
#include <string>
#include <vector>
#include <iomanip>
#include "FormatDate.h"

Airport::Airport(
	const string& id,
	const string& name,
	const int& parkingLots,
	const bool& isForInternationalFlights,
	const optional<std::vector<Flight>>& flights,
	const optional<std::vector<Plane>>& planes,
	Employee* employees
) : id(id), 
	name(name), 
	parkingLots(parkingLots),
	isForInternationalFlights(isForInternationalFlights),
	flights(flights),
	planes(planes),
	employees(employees) {}

void Airport::printPlanes() const {
	for (const auto& plane : planes.value()) {
		std::cout << "--- Plane ---" << endl;
		std::cout << "Id: " << plane.getId() << endl;
		std::cout << "Name: " << plane.getName() << endl;
		std::cout << "Model Name: " << plane.getModelName() << endl;
		std::cout << "Color: " << plane.getColor() << endl;
		std::cout << "Type: " << plane.getType() << endl;
		std::cout << "Places: " << plane.getPlaces() << endl;
		std::cout << "Available places: " << plane.getAvailablePlaces() << endl;
		std::cout << "Speed: " << plane.getSpeed() << endl;
		std::cout << "Is available now: " << (plane.getIsAvailable() ? "Yes" : "No") << endl;
		std::cout << "Arrival time: " << formatDate(plane.getArrival()) << endl;
		std::cout << "Departure time: " << formatDate(plane.getDeparture()) << endl;
	}
}