#pragma once

#include <string>
#include "Colecao.h"
#include "Service.h"
#include "Patient.h"
#include "Appointment.h"
#include "Exam.h"

using namespace std;

class Clinic {
	string name;
	Colecao<Patient> patients;
	Colecao<Appointment*> appointments;

public:
	Clinic(string name);
	bool addPatient(string namePat);
	bool addAppointmentInPatient(string appointmentDate, string diagnosis, int patientId);
	bool addExamInAppointment(string examDate, float examCost, string typology, int appointmentId, int patientId);
	Patient* findPatient(int patientId);
	Appointment* findAppointment(int appointmentId, int patientId);
	void remoPatient(int paitentId);
	void remoAppointment(int appointmentId, int patientId);
	void remoExam(int examid, int appointmentId, int patientId);
	int numberOfPatients() const;
	int numberOfAppointments() const;
	int numberOfExams() const;
	void print();
};
