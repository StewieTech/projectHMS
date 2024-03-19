#include "Appointment.h"
#include "Procedure.h" 
#include "exceptions.h"
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Constructors
Appointment::Appointment()
    : patient(nullptr), medicalStaff(nullptr), procedure(nullptr) {}

Appointment::Appointment(Patient* patInput, MedicalStaff* mInput, const string& atInput, const string& prInput)
    : patient(patInput), medicalStaff(mInput), appointmentTime(atInput), procedures(prInput), procedure(nullptr) {}

// Accessors
string Appointment::getAppointmentTime() const {
    return appointmentTime;
}

Patient* Appointment::getPatient() const {
    return patient;
}

MedicalStaff* Appointment::getMedicalStaff() const {
    return medicalStaff;
}

Procedure* Appointment::getProcedure() const {
    return procedure;
}

string Appointment::getProcedures() const {
    return procedures;
}

// Modifiers
void Appointment::setAppointmentTime(const string& appointmentTime) {
    this->appointmentTime = appointmentTime;
}

void Appointment::setPatient(Patient* patient) {
    this->patient = patient;
}

void Appointment::setMedicalStaff(MedicalStaff* staff) {
    medicalStaff = staff;
}

void Appointment::setProcedure(Procedure* procedure) {
    this->procedure = procedure;
}

void Appointment::setProcedures(const string& procedures) {
    this->procedures = procedures;
}

// Additional functions for appointment scheduling
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment) {
    list<string> scheduledAppointments;
    for (const auto& appointment : appointments) {
        scheduledAppointments.push_back(appointment.getAppointmentTime());
    }

    if (find(scheduledAppointments.begin(), scheduledAppointments.end(), appointment.getAppointmentTime()) != scheduledAppointments.end()) {
        throw AppointmentConflictException();
    }

    appointments.push_back(appointment);
}

void appointmentCancel(list<Appointment>& appointments, const string& appointmentTime) {
    auto iter = find_if(appointments.begin(), appointments.end(), [appointmentTime](const Appointment& appointment) {
        return appointment.getAppointmentTime() == appointmentTime;
        });

    if (iter != appointments.end()) {
        appointments.erase(iter);
    }
}
