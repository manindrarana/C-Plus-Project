#pragma once

#include <string>
#include "Colecao.h"
using namespace std;
class Service {
protected:
	int identCode;
	string dateOfService;
	float costOfService;
public:
	Service(int id, string date, float cost);
	float getCost() const;
	bool operator<(const Service& service) const;
	void print();
};