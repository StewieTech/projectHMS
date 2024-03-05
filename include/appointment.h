#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Patient.h"
#include "MedicalStaff.h"

using namespace std;

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

private:
    string appointmentTime;
    Patient* patient;       // Pointer to the patient associated with the appointment
    MedicalStaff* staff;    // Pointer to the medical staff associated with the appointment
};

#endif // APPOINTMENT_H
