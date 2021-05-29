#include<iostream>
#include "Exam.h"
#include"Appointment.h"

Exam::Exam(int examId, string examDate, float examCost, string typology): Service(examId, examDate, examCost) {
	this->typology = typology;
}
void Exam::assignAppointment(Appointment* appointment) {
	if (this->appointment == NULL) this->appointment = appointment;
}

Appointment* Exam::getAssignedAppointment(){
	return appointment;
}

int Exam::getExamId() const{
	return identCode;
}

bool Exam::operator<(const Exam& exam) const {
	return this->identCode < exam.identCode;
}

void Exam::print() const{
	cout << "Assigned appointment Id: " << appointment->getAppointmentId() << endl;
	cout << "Identity code: " << identCode << endl;
	cout << "Date of Exam: " << dateOfService << endl;
	cout << "Cost of Exam: " << costOfService << endl;
}
