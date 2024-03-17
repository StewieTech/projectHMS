
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <list>
// #include "Patient.h"
// #include "MedicalStaff.h"
// #include "Procedure.h" 
// #include "exceptions.h"

// using namespace std;


// Forward declaration to avoid circular dependencies
class Patient;
class InPatient;
class OutPatient;
class MedicalStaff;
class Procedure;

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
protected:
    std::string appointmentTime;
    Patient* patient;
    InPatient* inPatient;
    OutPatient* outPatient;
    std::string procedures;
    MedicalStaff* medicalStaff;
    // Procedure* procedures;

public:
    // Constructors
    Appointment();
    Appointment(Patient* patInput, MedicalStaff* mInput, const std::string& atInput, const std::string& prInput);
    // Appointment(const string& appointmentTime, Patient* patient, MedicalStaff* staff, Procedure* procedure);

    // Accessors
    std::string getAppointmentTime() const;
    Patient* getPatient() const;
    MedicalStaff* getMedicalStaff() const;
    Procedure* getProcedure() const; // Getter for procedure

    // Modifiers
    
    // void setAppointmentTime(const string& appointmentTime);
    // void setPatient(Patient* patient);
    // void setMedicalStaff(MedicalStaff* staff);
    // void setProcedure(Procedure* procedure); // Setter for procedure

    // Current;y Patient does not have friend functions declared for the below


    // Friend function declaration
    // friend void Patient::setPatientAppointment(Patient* patient, Appointment* appointment);
    // friend void InPatient::setPatientAppointment(Patient* patient, Appointment* appointment);
    // friend void OutPatient::setPatientAppointment(Patient* patient, Appointment* appointment);

    // Display appointment history
    // friend void Patient::displayHistory();
    // friend void InPatient::displayHistory();
    // friend void OutPatient::displayHistory();

    // Additional functions for appointment scheduling
    void displayMenu() const;


    // Procedure* procedure; // Need to update not sure where to get from Member variable representing the associated procedure
};

// Additional functions for appointment scheduling
void appointmentSchedule(std::list<Appointment>& appointments, const Appointment& appointment);
void appointmentCancel(std::list<Appointment>& appointments, const Appointment& appointment);
void displayMenu();
void userInput(std::list<Appointment>& appointments, std::vector<Patient*>& patients, std::vector<MedicalStaff*>& staffMembers);

#endif // APPOINTMENT_H

