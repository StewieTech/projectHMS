#include "appointment.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

// Constructor
Appointment::Appointment(const string& patInput, int inputID, MedicalStaff* mInput, const string& atInput, const string& prInput)
    : patient(patInput), patientID(to_string(inputID)), medicalStaff(mInput), appointmentTime(atInput), procedures(prInput), canceled(false), appointmentID(0) {}

// Destructor
Appointment::~Appointment() {}

// Getters
string Appointment::getPatientName() const {
    return patient;
}

string Appointment::getAppointmentTime() const {
    return appointmentTime;
}

int Appointment::getAppointmentID() const {
    return stoi(patientID);
}

bool Appointment::isCanceled() const {
    return canceled;
}

MedicalStaff* Appointment::getMedicalStaff() const {
    return medicalStaff;
}

string Appointment::getProcedures() const {
    return procedures;
}

// Setters
void Appointment::setAppointmentTime(const string& appointmentTime) {
    this->appointmentTime = appointmentTime;
}

void Appointment::setPatientID(const string& patientID) {
    this->patientID = patientID;
}

void Appointment::setPatientName(const string& patientName) {
    patient = patientName;
}

void Appointment::setMedicalStaff(MedicalStaff* staff) {
    medicalStaff = staff;
}

void Appointment::setProcedures(const string& procedures) {
    this->procedures = procedures;
}

// Schedule Appointment
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment) {
    appointments.push_back(appointment);
}

// Static function to reschedule appointment
void Appointment::rescheduleAppointment(list<Appointment>& appointments, const string& appointmentID, const string& newTime) {
    // Iterate through the list of appointments to find the appointment with the given ID
    for (auto& appointment : appointments) {
        if (to_string(appointment.getAppointmentID()) == appointmentID) {
            // Validate appointment time format
            // Implement isValidAppointmentTimeFormat if necessary
            if (!isValidAppointmentTimeFormat(newTime)) {
                throw invalid_argument("Invalid appointment time format. Please use the format YYYY-MM-DD HH:MM.");
            }

            // Reschedule the appointment
            appointment.setAppointmentTime(newTime);
            cout << "Appointment successfully rescheduled." << endl;
            return;
        }
    }

    // If the appointment is not found
    cerr << "No appointment found with ID " << appointmentID << "." << endl;
}

// Cancel Appointment
void cancelAppointment(list<Appointment>& appointments, const string& appointmentID) {
    int targetAppointmentID = stoi(appointmentID);
    for (auto& appointment : appointments) {
        if (appointment.getAppointmentID() == targetAppointmentID) {
            appointment.cancelAppointment();
            return;
        }
    }
    cerr << "No appointment found with ID " << appointmentID << "." << endl;
}
