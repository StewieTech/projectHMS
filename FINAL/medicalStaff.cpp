#include <iostream>
#include "medicalStaff.h"
#include "exceptions.h"

using namespace std;

// Const object for MedicalStaff
MedicalStaff::MedicalStaff( string name,  string specialization, bool availability, int employeeID)
    : name(name), specialization(specialization), availability(availability), employeeID(employeeID) {}

// Destructor for medical staff obj
MedicalStaff::~MedicalStaff() {
    for (Procedure* procedure : procedures) {
        delete procedure;
    }
}

// Display function for medical staff info
void MedicalStaff::displayInfo() const {
     cout << "Name: " << name <<  endl;
     cout << "Specialization: " << specialization <<  endl;
     cout << "Availability: " << (availability ? "Available" : "Not Available") <<  endl;
     cout << "Employee ID: " << employeeID <<  endl;
     cout << "Procedures: ";
    for (Procedure* procedure : procedures) {
         cout << procedure->getName() << ", ";
    }
     cout <<  endl;
}

// bool function to see if MedicalStaff is available
bool MedicalStaff::isAvailable() const {
    return availability;
}

// list out procedures associated with MedicalStaff
const  vector<Procedure*>& MedicalStaff::getProcedures() const {
    return procedures;
}

// Add a procedure to MedicalStaff
void MedicalStaff::addProcedure(Procedure* procedure) {
    procedures.push_back(procedure);
}

// Add exception handling to this method
void MedicalStaff::setAppointment(Appointment* appointment) {
    try {
        if (!availability) {
            throw AppointmentConflictException(); // Change here
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
}


// doctor obj const
Doctor::Doctor( string name,  string specialization, bool availability, int employeeID,  string licenseNumber)
    : MedicalStaff(name, specialization, availability, employeeID), licenseNumber(licenseNumber) {}

// call display info for Doctor obj
void Doctor::displayInfo() const {
    MedicalStaff::displayInfo(); 
     cout << "License Number: " << licenseNumber <<  endl;
}

// Const obj for Nurse
Nurse::Nurse( string name,  string specialization, bool availability, int employeeID)
    : MedicalStaff(name, specialization, availability, employeeID) {}

// call display info for nurse obj
void Nurse::displayInfo() const {
    MedicalStaff::displayInfo(); // Call base class displayInfo method
}

// assign staff based on specialization
MedicalStaff* MedicalStaffManager::assignMedicalStaff(const  string& specialization) {
    if (specialization == "Doctor") {
        return new Doctor("Dr. John Doe", specialization, true, 12345, "123456789");
    }
    else if (specialization == "Nurse") {
        return new Nurse("Nurse Jane", specialization, true, 67890);
    }
    return nullptr; // Return nullptr if specialization is not recognized
}

// find staff by specialization
MedicalStaff* MedicalStaffManager::findMedicalStaff(const  string& specialization, const  vector<MedicalStaff*>& staffMembers) {
    for (auto& staff : staffMembers) {
        if (staff->getSpecialization() == specialization && staff->isAvailable()) {
            return staff;
        }
    }
    return nullptr;
}

// returns name
string MedicalStaff::getName() const {
    return name;
}

// returns specialization
string MedicalStaff::getSpecialization() const {
    return specialization;
}
