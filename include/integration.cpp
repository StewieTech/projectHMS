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
    vector<MedicalStaff*> medicalStaff;
    vector<Appointment*> appointments;

    // Example: Adding new patients
    addNewPatient(patients, new Inpatient("John Doe", 35, 'M', 101, "Room 101"));
    addNewPatient(patients, new Outpatient("Jane Doe", 25, 'F', "2024-02-15", "Dr. Smith"));

    // Example: Adding medical staff
    medicalStaff.push_back(new Doctor("Dr. Smith", "Cardiologist", true, "License123"));
    medicalStaff.push_back(new Nurse("Nurse Johnson", "RN", true, 12345));

    // Example: Creating appointments
    appointments.push_back(new Appointment("2024-02-20", patients[0], medicalStaff[0]));
    appointments.push_back(new Appointment("2024-02-21", patients[1], medicalStaff[1]));

    // Example: Searching for a patient by ID
    Patient* foundPatient = searchPatientById(patients, 101);
    if (foundPatient) {
        cout << "Patient found:\n" << foundPatient->displayInfo() << endl;
    }
    else {
        cout << "Patient not found.\n";
    }

    // Displaying all patients
    displayAllPatients(patients);

    // Clean up memory
    for (auto& patient : patients) {
        delete patient;
    }

    for (auto& staff : medicalStaff) {
        delete staff;
    }

    for (auto& appointment : appointments) {
        delete appointment;
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
            cout << "Assigned Medical Staff: " << patient->getAppointment()->getMedicalStaff()->getName() << endl;
        }
        cout << "--------------------------\n";
    }
}
