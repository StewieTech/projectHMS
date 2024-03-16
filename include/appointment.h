#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <list>
#include "Patient.h"
#include "MedicalStaff.h"
#include "Procedure.h" 
#include "exceptions.h"

using namespace std;

// Forward declaration to avoid circular dependencies
class Patient;
class InPatient;
class OutPatient;

// Exception class for appointment conflicts
// redefinition of class
// class AppointmentConflictException : public exception {
// public:
//     const char* what() const throw() {
//         return "Appointment conflict detected.";
//     }
// };

// Appointment Scheduling
class Appointment {
public:
    // Constructors
    Appointment();
    Appointment(const string& appointmentTime, Patient* patient, MedicalStaff* staff, Procedure* procedure);

    // Accessors
    const string& getAppointmentTime() const;
    Patient* getPatient() const;
    MedicalStaff* getMedicalStaff() const;
    Procedure* getProcedure() const; // Getter for procedure

    // Modifiers
    void setAppointmentTime(const string& appointmentTime);
    void setPatient(Patient* patient);
    void setMedicalStaff(MedicalStaff* staff);
    void setProcedure(Procedure* procedure); // Setter for procedure

    // Friend function declaration
    friend void Patient::setPatientAppointment(Patient* patient, Appointment* appointment);
    friend void InPatient::setPatientAppointment(Patient* patient, Appointment* appointment);
    friend void OutPatient::setPatientAppointment(Patient* patient, Appointment* appointment);

    // Display appointment history
    friend void Patient::displayHistory();
    friend void InPatient::displayHistory();
    friend void OutPatient::displayHistory();

    // Additional functions for appointment scheduling
    void displayMenu() const;

private:
    string appointmentTime;
    Patient* patient;
    InPatient* inPatient;
    OutPatient* outPatient;
    MedicalStaff* staff;
    Procedure* procedure; // Member variable representing the associated procedure
};

// Additional functions for appointment scheduling
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment);
void appointmentCancel(list<Appointment>& appointments, const Appointment& appointment);
void displayMenu();
void userInput(list<Appointment>& appointments);

#endif // APPOINTMENT_H
