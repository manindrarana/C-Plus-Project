#include <string>
#include "Appointment.h"
#include "Exam.h"
#include <iostream>

using namespace std;

Appointment::Appointment(int appointmentID, string appointmentDate, float appointmentCost, string diagnosis): Service(appointmentID, appointmentDate, appointmentCost) {
	this->diagnosis = diagnosis;
}

bool Appointment::addExam(Exam& ex) {
	costOfService = costOfService + ex.getCost();
	ex.assignAppointment(this);
	return exams.insert(ex);
}

Exam* Appointment::findExam(int examid) {
	Exam exam(examid, "",0,"");
	return exams.find(exam);
}

void Appointment::remoExam(int examid) {
	Exam* fe = findExam(examid);
	if (fe != NULL) {
		Exam exam(examid, "", 0, "");
		exams.erase(exam);
		costOfService = costOfService - fe->getCost();
	}
	else {
		cout << "Exam: " << examid << "does not exist!1!" << endl;
	}
}

int Appointment::numberOfExams() const{
	return exams.size();
}

float Appointment::getAppointmentId() const{
	return this->identCode;
}

bool Appointment::operator<(const Appointment& appointment) const {
	return this->identCode < appointment.identCode;
}

void Appointment::printExam() const {
	Colecao<Exam>::iterator it = exams.begin();
	while (it != exams.end()) {
		it->print();
		cout << endl;
		it++;
	}
}

void Appointment::print() const{
	cout << "Identity code: " << identCode << endl;
	cout << "Date of Appointment: " << dateOfService << endl;
	cout << "Cost of Appointment: " << costOfService << endl;
	cout << "Number of assigned exams: " << numberOfExams() << endl;
}