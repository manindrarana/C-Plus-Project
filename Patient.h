#pragma once

#include <string>
#include "Colecao.h"
#include "Service.h"
#include "Appointment.h"
using namespace std;

//class Appointment;
//class Exam;

class Patient {
	int id;
	string name;
	Colecao<Appointment> appointments;
	Colecao<Exam*> exams;
public:
	Patient(int id, string name);
	bool addAppointment(const Appointment&);
	bool addExamInAppointment(int idAppointment, Exam& exam);
	int numberOfAppointments() const;
	int numberOfExams() const;
	void remoAppointment(int appointmentid);
	void remoExamInAppointment(int appointmentId, int examId);
	Appointment* findAppointment(int appointmentId);
	float totalCost() const;
	bool operator<(const Patient& patient) const;
	void printAppointment() const;
	void printExams() const;
	void print() const;
};