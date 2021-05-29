#pragma once
#include <string>
#include "Colecao.h"
#include "Exam.h"


class Appointment: public Service {
	string diagnosis;
	Colecao<Exam> exams;

public:
	Appointment(int appointmentID,string appointmentDate,float appointmentCost,string diagnosis);
	bool addExam(Exam& ex);
	Exam* findExam(int examid);
	void remoExam(int examid);
	int numberOfExams() const;
	float getAppointmentId() const;
	bool operator<(const Appointment& appointment) const;
	void printExam() const;
	void print() const;
};
