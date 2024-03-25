#include "appointment.h"

// Constructor
Appointment::Appointment(const string& patInput, int inputID, MedicalStaff* mInput, const string& atInput, const string& prInput)
    : patient(patInput), patientID(inputID), medicalStaff(mInput), appointmentTime(atInput), procedures(prInput), canceled(false) {}

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
    return appointmentID;
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
    this->patient = patientName;
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

// Cancel Appointment
void cancelAppointment(list<Appointment>& appointments, const string& appointmentID) {
    int targetAppointmentID = stoi(appointmentID);
    for (auto& appointment : appointments) {
        // Assuming you have a getAppointmentID() function in your Appointment class
        if (appointment.getAppointmentID() == targetAppointmentID) {
            appointment.cancelAppointment();
            return;
        }
    }
    // If the appointment is not found
    cerr << "No appointment found with ID " << appointmentID << "." << endl;
}