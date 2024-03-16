#include "Patient.h"
#include "MedicalStaff.h"
#include "Appointment.h"
#include "Procedure.h" // Include the Procedure header file
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

// Function to assign medical staff to an appointment
void assignMedicalStaffToAppointment(MedicalStaff* medicalStaff, Appointment* appointment);

int main() {
    vector<Patient*> patients;

    // Example: Adding new patients
    Patient* johnDoe = new InPatient("John Doe", 35, 'M', 101, "Room 101");
    Patient* janeDoe = new OutPatient("Jane Doe", 25, 'F', "2024-02-15", "Dr. Smith");

    // Creating appointments
    Appointment* johnsAppointment = new Appointment("2024-02-16 10:00", johnDoe, nullptr);
    Appointment* janesAppointment = new Appointment("2024-02-17 14:30", janeDoe, nullptr);

    // Adding procedures for the patients
    Procedure* procedure1 = new Procedure("X-Ray", "2024-02-16 10:30");
    Procedure* procedure2 = new Procedure("Blood Test", "2024-02-17 15:00");
    johnDoe->addProcedure(procedure1);
    janeDoe->addProcedure(procedure2);

    // Assigning appointments to patients
    johnDoe->setAppointment(johnsAppointment);
    janeDoe->setAppointment(janesAppointment);

    // Adding patients to the list
    addNewPatient(patients, johnDoe);
    addNewPatient(patients, janeDoe);

    // Assigning medical staff to appointments using MedicalStaffManager
    MedicalStaff* drSmith = MedicalStaffManager::assignMedicalStaff("Cardiologist");
    MedicalStaff* nurseJohnson = MedicalStaffManager::assignMedicalStaff("ER Nurse");

    assignMedicalStaffToAppointment(drSmith, johnsAppointment);
    assignMedicalStaffToAppointment(nurseJohnson, janesAppointment);

    // Example: Searching for a patient by ID
    Patient* foundPatient = searchPatientById(patients, 101);
    if (foundPatient) {
        cout << "Patient found:\n" << foundPatient->displayInfo() << endl;
    } else {
        cout << "Patient not found.\n";
    }

    // Example: Displaying all patients
    displayAllPatients(patients);

    // Clean up memory
    for (auto& patient : patients) {
        delete patient;
    }

    // Clean up procedures
    delete procedure1;
    delete procedure2;

    // Clean up medical staff
    delete drSmith;
    delete nurseJohnson;

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
        cout << "Health History: " << endl;
        patient->displayHealthHistory(); // Display health history including procedures
        // Display patient's appointment information
        if (patient->getAppointment()) {
            cout << "Appointment Time: " << patient->getAppointment()->getAppointmentTime() << endl;
        }
        cout << "--------------------------\n";
    }
}

// Function to assign medical staff to an appointment
void assignMedicalStaffToAppointment(MedicalStaff* medicalStaff, Appointment* appointment) {
    medicalStaff->assignToAppointment(appointment);
}
