/*
#include <iostream>
#include <string>
#include <list>

#include "patient.h"
#include "medicalStaff.h"
#include "exceptions.h"

using namespace std;

// Exception class for appointment conflicts
// Redefinition of appointment conflicts
// class AppointmentConflictException : public exception {
// public:
//     const char* what() const throw() {
//         return "Appointment conflict detected.";
//     }
// };

// User Interface (Errol):
// Develop the user interface for interacting with the Hospital Management System.
// Implement menus, prompts, error messages, and user input validations.

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

// Appointment Scheduling
class Appointment {
protected:
    Patient* patient; // Will make a dynamic reference to the patient class from Question 1
    MedicalStaff* medicalStaff; // dynamic from MedicalStaff.cpp
    string appointmentTime;
    string procedures;

public:
    Appointment(Patient* patInput, MedicalStaff* mInput, const string& atInput, const string& prInput);
    string getAppointmentTime() const;
    void displayMenu() const;
};

void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment);
void appointmentCancel(list<Appointment>& appointments, const Appointment& appointment);
void displayMenu();
void userInput(list<Appointment>& appointments);

#endif // USERINTERFACE_H

*/