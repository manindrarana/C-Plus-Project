#include <iostream>
#include "Service.h"
using namespace std;

Service::Service(int id, string date, float cost) {
	identCode = id;
	dateOfService = date;
	costOfService = cost;
}

float Service::getCost() const {
	return costOfService;
}

bool Service::operator<(const Service& service) const {
	return this->identCode< service.identCode;
}

void Service::print() {
	cout << "Identity code: " << identCode << endl;
	cout << "Date of Service: " << dateOfService << endl;
	cout << "Cost of Service: " << costOfService << endl;
}
