#include "Patient.h"
#include "MedicalStaff.h"
#include "Appointment.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to add a new patient to the list
void addNewPatient(vector<Patient*>& patients, Patient* newPatient);

// Function to search for a patient by ID
Patient* searchPatientById(const vector<Patient*>& patients, const int patientId);

// Function to display the list of all patients
void displayAllPatients(const vector<Patient*>& patients);

int main() {
    vector<Patient*> patients;

    // Example: Adding new patients
    addNewPatient(patients, new Inpatient("John Doe", 35, 'M', 101, "Room 101"));
    addNewPatient(patients, new Outpatient("Jane Doe", 25, 'F', "2024-02-15", "Dr. Smith"));

    // Example: Searching for a patient by ID
    Patient* foundPatient = searchPatientById(patients, 101);
    if (foundPatient) {
        cout << "Patient found:\n" << foundPatient->displayInfo() << endl;
    }
    else {
        cout << "Patient not found.\n";
    }

    // Example: Displaying all patients
    displayAllPatients(patients);

    // Clean up memory
    for (auto& patient : patients) {
        delete patient;
    }

    return 0;
}

// Function definitions
void addNewPatient(vector<Patient*>& patients, Patient* newPatient) {
    patients.push_back(newPatient);
}

Patient* searchPatientById(const vector<Patient*>& patients, const int patientId) {
    auto it = find_if(patients.begin(), patients.end(), [patientId](const Patient* patient) {
        return patient->getId() == patientId;
    });

    if (it != patients.end()) {
        return *it;
    }

    return nullptr; // Patient not found
}

void displayAllPatients(const vector<Patient*>& patients) {
    for (const auto& patient : patients) {
        cout << patient->displayInfo() << endl;
        // Assuming there's a getHealthHistory() function in the Patient class
        cout << patient->getHealthHistory() << endl;
        // Display patient's appointment information
        if (patient->getAppointment()) {
            cout << "Appointment Time: " << patient->getAppointment()->getAppointmentTime() << endl;
        }
        cout << "--------------------------\n";
    }
}

// Doctor class functions
Doctor::Doctor(string name, string specialization, bool availability, string licenseNumber)
    : MedicalStaff(name, specialization, availability), licenseNumber(licenseNumber) {}

void Doctor::displayInfo() const {
    MedicalStaff::displayInfo();
    cout << "License Number: " << licenseNumber << endl;
}

void Doctor::assignToAppointment(Appointment* appointment) {
    // Implementation to assign a doctor to an appointment
    // This can involve updating the doctor's schedule, etc.
    cout << "Doctor " << name << " assigned to appointment." << endl;
}

// Nurse class functions
Nurse::Nurse(string name, string specialization, bool availability, int employeeId)
    : MedicalStaff(name, specialization, availability), employeeId(employeeId) {}

void Nurse::displayInfo() const {
    MedicalStaff::displayInfo();
    cout << "Employee ID: " << employeeId << endl;
}

void Nurse::assignToAppointment(Appointment* appointment) {
    // Implementation to assign a nurse to an appointment
    // This can involve updating the nurse's schedule, etc.
    cout << "Nurse " << name << " assigned to appointment." << endl;
}
