#pragma once

#include <string>
#include "Colecao.h"
#include "Service.h"
using namespace std;

class Appointment;

class Exam: public Service {
	string typology;
protected:
	Appointment* appointment;

public:
	Exam(int examId, string examDate, float examCost, string typology );
	void assignAppointment(Appointment* appointment);
	Appointment* getAssignedAppointment();
	int getExamId() const;
	bool operator<(const Exam& exam) const;
	void print() const;
};