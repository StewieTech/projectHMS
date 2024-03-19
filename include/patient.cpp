#include "Patient.h"
#include <iostream>

using namespace std;

// Function definitions related to patients

// Function to add a new patient to the list
void addNewPatient(vector<Patient*>& patients, Patient* newPatient) {
    patients.push_back(newPatient);
}

// Function to search for a patient by name
Patient* findPatientByName(const string& name, const vector<Patient*>& patients) {
    for (auto& p : patients) {
        if (p->getName() == name) return p;
    }
    return nullptr;
}

// Function to search for a patient by ID
Patient* searchPatientById(const vector<Patient*>& patients, const int patientId) {
    auto it = find_if(patients.begin(), patients.end(), [patientId](const Patient* patient) {
        return patient->getId() == patientId;
        });

    if (it != patients.end()) {
        return *it;
    }

    return nullptr; // Patient not found
}

// Function to display the list of all patients
void displayAllPatients(const vector<Patient*>& patients) {
    for (const auto& patient : patients) {
        cout << patient->displayInfo() << endl;
        cout << "Health History: " << endl;
        patient->displayHealthHistory(); // Display health history including procedures
        // Display patient's appointment information
        if (patient->getAppointment()) {
            cout << "Appointment Time: " << patient->getAppointment()->getAppointmentTime() << endl;
            cout << "Procedures: " << patient->getAppointment()->getProcedure()->getName() << endl; // Updated line to display procedures
        }
        cout << "--------------------------\n";
    }
}
