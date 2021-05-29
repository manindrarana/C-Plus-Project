#include<iostream>
#include "Clinic.h"

void main() {

	//add a clinic 
	Clinic c("Estig");

	//add patients to the clinic
	c.addPatient("Randy Orton");
	c.addPatient("Brock Lesnar");
	c.addPatient("Undertaker");

	//add appointments to the patients
	c.addAppointmentInPatient("28-05-2021", "Broken neck", 1);
	c.addAppointmentInPatient("31-05-2021", "Swollen hand", 1);
	c.addAppointmentInPatient("12-06-2021", "Broken back", 2);
	c.addAppointmentInPatient("07-06-2021", "Broken arm", 3);

	//add exam to the appointments
	c.addExamInAppointment("28-05-2021", 12.5, "Clinical Analysis", 1, 1);
	c.addExamInAppointment("28-05-2021", 10.5, "Check up", 1, 1);
	c.addExamInAppointment("31-05-2021", 11, "Imaging", 2,1);

	c.addExamInAppointment("12-06-2021", 20, "Check up", 1, 2);

	c.addExamInAppointment("07-06-2021", 13.5, "Clinical Analysis", 1, 3);
	c.addExamInAppointment("07-06-2021", 10.5, "Check up", 1, 3);
	c.addExamInAppointment("07-06-2021", 11, "Imaging", 1, 3);

	c.print();

	//delete patient
	c.remoPatient(3);

	//delete appointment
	c.remoAppointment(2, 1);

	//delete exam
	c.remoExam(1, 1, 2);

	cout << endl << "\t\t\tAfter deletion:" << endl;
	c.print();

}