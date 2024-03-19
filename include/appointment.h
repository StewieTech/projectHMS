#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <list>
#include "patient.h"
#include "medicalStaff.h"
#include "procedure.h" 
#include "exceptions.h"

using namespace std;

// Forward declarations to avoid circular dependencies
class Patient;
class MedicalStaff;
class Procedure;

class Appointment {
protected:
    string appointmentTime;
    Patient* patient;
    MedicalStaff* medicalStaff;
    Procedure* procedure;
    string procedures; // New member variable

public:
    // Constructors
    Appointment();
    Appointment(Patient* patInput, MedicalStaff* mInput, const string& atInput, const string& prInput); // Updated constructor

    // Accessors
    string getAppointmentTime() const;
    Patient* getPatient() const;
    MedicalStaff* getMedicalStaff() const;
    Procedure* getProcedure() const;
    string getProcedures() const; // Getter for procedures

    // Modifiers
    void setAppointmentTime(const string& appointmentTime);
    void setPatient(Patient* patient);
    void setMedicalStaff(MedicalStaff* staff);
    void setProcedure(Procedure* procedure);
    void setProcedures(const string& procedures); // Setter for procedures

    // Friend function declarations
    friend void setPatientAppointment(Patient* patient, Appointment* appointment);
    friend void displayHistory(const Patient& patient);

    // Additional functions for appointment scheduling
    void displayMenu() const;
};

// Additional functions for appointment scheduling
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment);
void appointmentCancel(list<Appointment>& appointments, const Appointment& appointment);
void displayMenu();
void userInput(list<Appointment>& appointments, vector<Patient*>& patients, vector<MedicalStaff*>& staffMembers);

#endif // APPOINTMENT_H
