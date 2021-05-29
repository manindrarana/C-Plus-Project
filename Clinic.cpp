#include <iostream>
#include <string>
#include "Clinic.h"

using namespace std;

Clinic::Clinic(string name) {
	this->name = name;
}
bool Clinic::addPatient(string namePat) {
	int id = patients.size() + 1;
	Patient patient(id, namePat);
	return patients.insert(patient);
}

bool Clinic::addAppointmentInPatient(string appointmentDate, string diagnosis, int patientId) {
	Patient* patient = findPatient(patientId);
	if (patient != NULL) {
		int id = patient->numberOfAppointments() + 1;
		Appointment appointment(id, "", 0, "");
		return patient->addAppointment(appointment);
	}
	else {
		cout << "Patient: " << patientId << " does not exist!!!" << endl;
		return NULL;
	}
}

bool Clinic::addExamInAppointment(string examDate, float examCost, string typology, int appointmentid, int patientId) {
	Patient* patient = findPatient(patientId);
	if (patient != NULL) {
		Appointment* appointment = patient->findAppointment(appointmentid);
		if (appointment != NULL) {
			int id = appointment->numberOfExams() + 1;
			Exam exam(id, examDate, examCost, typology);
			return appointment->addExam(exam);
		}
		else {
			cout << "Appointment: " << appointmentid << " does not exist!!!" << endl;
			return NULL;
		}
	}
	else {
		cout << "Patient: " << patientId << " does not exist!!!" << endl;
		return NULL;
	}
}

Appointment* Clinic::findAppointment(int appointmentId, int patientId) {
	Patient* patient = findPatient(patientId);
	if (patient != NULL) {
		return patient->findAppointment(appointmentId);
	}
	else {
		cout << "Patient: " << patientId << " does not exist!!!" << endl;
		return NULL;
	}
}

Patient* Clinic::findPatient(int patientId){
	Patient patient(patientId, "");
	return patients.find(patient);
}

void Clinic::remoPatient(int patientId) {
	Patient* patient = findPatient(patientId);
	if (patient != NULL) {
		Patient p(patientId, "");
		patients.erase(p);
		cout << "Patient: " << patientId << " successfully removed." << endl;
	}
	else {
		cout << "Patient: " << patientId << " does not exist!!!" << endl;
	}
}

void Clinic::remoAppointment(int appointmentId, int patientId) {
	Patient* patient = findPatient(patientId);
	if (patient != NULL) {
		patient->remoAppointment(appointmentId);
		cout << "Appointment: " << appointmentId << " successfully removed." << endl;
	}
	else {
		cout << "Patient: " << patientId << " does not exist!!!" << endl;
	}
}

void Clinic::remoExam(int examid, int appointmentId, int patientId) {
	Patient* patient = findPatient(patientId);
	if (patient != NULL) {
		patient->remoExamInAppointment(appointmentId, examid);
		cout << "Exam: " << examid << " successfully removed." << endl;
	}
	else {
		cout << "Patient: " << patientId << " does not exist!!!" << endl;
	}
}

int Clinic::numberOfPatients() const {
	return patients.size();
}

int Clinic::numberOfAppointments() const {
	Colecao<Patient>::iterator it = patients.begin();
	int numberOfAppointments = 0;
	while (it != patients.end()) {
		numberOfAppointments += it->numberOfAppointments();
		it++;
	}
	return numberOfAppointments;
}

int Clinic::numberOfExams() const {
	Colecao<Patient>::iterator it = patients.begin();
	int numberOfExams = 0;
	while (it != patients.end()) {
		numberOfExams += it->numberOfExams();
		it++;
	}
	return numberOfExams;
}

void Clinic::print() {
	cout << "Clinic name: " << name << endl;
	cout << "Number of patients: " << numberOfPatients() << endl;
	cout << "Number of Appointments: " << numberOfAppointments() << endl;
	cout << "Number of Exams: " << numberOfExams() << endl<<endl;
	Colecao<Patient>::iterator it;
	cout << "\t\t\tPATIENTS:" << endl;
	for (it = patients.begin(); it != patients.end(); it++) {
		it->print();
		cout << endl;
	}
	cout << "\t\t\tAPPOINTMENTS:" << endl;
	for (it = patients.begin(); it != patients.end(); it++) {
		it->printAppointment();
		cout << endl;
	}
	cout << endl;
	cout << "\t\t\tEXAMS:" << endl;
	for (it = patients.begin(); it != patients.end(); it++) {
		it->printExams();
		cout << endl;
	}
}