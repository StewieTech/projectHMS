#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <time.h>
#include "Patient.h"	// deadlocking declaration, pls review
#include "MedicalStaff.h"

using namespace std;

// Forward declaration to avoid circular dependencies
class Patient;
class InPatient;
class OutPatient;


class Appointment {
public:
    Appointment();  // Constructor
    Appointment(const string& appointmentTime, Patient* patient, MedicalStaff* staff);

    // Accessors
    const string& getAppointmentTime() const;
    Patient* getPatient() const;
    MedicalStaff* getMedicalStaff() const;

    // Modifiers
    void setAppointmentTime(const string& appointmentTime);
    void setPatient(Patient* patient);
    void setMedicalStaff(MedicalStaff* staff);

    // Friend function declaration:
    friend void Patient::setPatientAppointment(Patient* patient, Appointment* appointment);
    friend void InPatient::setPatientAppointment(Patient* patient, Appointment* appointment);
    friend void OutPatient::setPatientAppointment(Patient* patient, Appointment* appointment);

    // Display apppointment history
    friend void Patient::displayHistory();
    friend void InPatient::displayHistory();
    friend void OutPatient::displayHistory();

private:
    string appointmentTime;
    Patient* patient;       // Pointer to the patient associated with the appointment - only to identify inpatient or outpatient
    	InPatient* inPatient;	//will need to use template in this case
    	OutPatient* outPatient;
    MedicalStaff* staff;    // Pointer to the medical staff associated with the appointment
};

#endif // APPOINTMENT_H
