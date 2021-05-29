#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

Patient::Patient(int id, string name) {
	this->id = id;
	this->name = name;
}

bool Patient::addAppointment(const Appointment& appointment){
	return appointments.insert(appointment);
}

bool Patient::addExamInAppointment(int idAppointment, Exam& exam) {
	Appointment* appointment = findAppointment(idAppointment);
	if (appointment != NULL) {
		return appointment->addExam(exam);
	}
	else {
		cout << "Appointment: " << idAppointment << " does not exist!!!" << endl;
		return NULL;
	}
}

int Patient::numberOfAppointments() const{
	return appointments.size();
}

int Patient::numberOfExams() const {
	Colecao<Appointment>::iterator it = appointments.begin();
	int numberOfExam = 0;
	while (it != appointments.end()) {
		 numberOfExam += it->numberOfExams();
		 it++;
	}
	return numberOfExam;
}

void Patient::remoAppointment(int appointmentid) {
	Appointment* fa = findAppointment(appointmentid);
	if (fa != NULL) {
		Appointment appointment(appointmentid, "", 0, "");
		appointments.erase(appointment);
	}
	else {
		cout << "Appointment: " << appointmentid << " does not exist!!!" << endl;
	}
}

void Patient::remoExamInAppointment(int appointmentId, int examId) {
	Appointment* appointment = findAppointment(appointmentId);
	if (appointment != NULL) {
		appointment->remoExam(examId);
	}
	else {
		cout << "Appointment: " << appointmentId << " does not exist!!!" << endl;
	}
}

Appointment* Patient::findAppointment(int appointmentId) {
	Appointment appointment(appointmentId, "", 0, "");
	return appointments.find(appointment);
}

bool Patient::operator<(const Patient& patient) const {
	return id < patient.id;
}

float Patient::totalCost() const {
	float totalCost = 0;
	Colecao<Appointment>::iterator it = appointments.begin();
	while (it != appointments.end()) {
		totalCost += it->getCost();
		it++;
	}
	return totalCost;
}
void Patient::printAppointment() const {
	Colecao<Appointment>::iterator it = appointments.begin();
	while (it != appointments.end()) {
		it->print();
		cout << endl;
		it++;
	}
}
void Patient::printExams() const {
	Colecao<Appointment>::iterator it = appointments.begin();
	while (it != appointments.end()) {
		it->printExam();
		cout << endl;
		it++;
	}
}

void Patient::print() const{
	cout << "Identity code: " << id << endl;
	cout << "Name of patient: " << name << endl;
	cout << "Number of assigned appointments: " << numberOfAppointments() << endl;
	cout << "Number of assigned exams: " << numberOfExams() << endl;
	cout << "Total : " << totalCost() << endl;
}