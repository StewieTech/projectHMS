#include <iostream>
#include "MedicalStaffVF.h"



// Constructor for MedicalStaff



MedicalStaff::MedicalStaff(string name, string specialization, bool availability, int employeeID)
    : name(name), specialization(specialization), availability(availability), employeeID(employeeID) {}

// Destructor for MedicalStaff
MedicalStaff::~MedicalStaff() {
    for (Procedure* procedure : procedures) {
        delete procedure;
    }
}

// Display information about MedicalStaff
void MedicalStaff::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Procedures: ";
    for (Procedure* procedure : procedures) {
        cout << procedure->getName() << ", ";
    }
    cout << endl;
}

// Check if MedicalStaff is available
bool MedicalStaff::isAvailable() const {
    return availability;
}

// Get the list of procedures associated with MedicalStaff
const vector<Procedure*>& MedicalStaff::getProcedures() const {
    return procedures;
}

// Add a procedure to MedicalStaff
void MedicalStaff::addProcedure(Procedure* procedure) {
    procedures.push_back(procedure);
}

// Constructor for Doctor
Doctor::Doctor(string name, string specialization, bool availability, int employeeID, string licenseNumber)
    : MedicalStaff(name, specialization, availability, employeeID), licenseNumber(licenseNumber) {}

// Display information about Doctor
void Doctor::displayInfo() const {
    MedicalStaff::displayInfo(); // Call base class displayInfo method
    cout << "License Number: " << licenseNumber << endl;
}

// Constructor for Nurse
Nurse::Nurse(string name, string specialization, bool availability, int employeeID)
    : MedicalStaff(name, specialization, availability, employeeID) {}

// Display information about Nurse
void Nurse::displayInfo() const {
    MedicalStaff::displayInfo(); // Call base class displayInfo method
}

// Static method to assign MedicalStaff based on specialization
MedicalStaff* MedicalStaffManager::assignMedicalStaff(const string& specialization) {
    if (specialization == "Doctor") {
        return new Doctor("Dr. John Doe", specialization, true, 12345, "123456789");
    }
    else if (specialization == "Nurse") {
        return new Nurse("Nurse Jane", specialization, true, 67890);
    }
    return nullptr; // Return nullptr if specialization is not recognized
}

// Method to find MedicalStaff by specialization
MedicalStaff* MedicalStaffManager::findMedicalStaff(const string& specialization, const vector<MedicalStaff*>& staffMembers) {
    for (auto& staff : staffMembers) {
        if (staff->getSpecialization() == specialization && staff->isAvailable()) {
            return staff;
        }
    }
    return nullptr;
}
