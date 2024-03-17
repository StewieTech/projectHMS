#ifndef MEDICALSTAFF_H
#define MEDICALSTAFF_H

#include <string>
#include <vector>
// #include "exceptions.h"
// #include "Procedure.h" 

// #include "Appointment.h"
// #include "Patient.h"

#include <iostream>
#include <list>
#include <algorithm>


// using namespace std;

class MedicalStaff {
protected:
    string name;
    string specialization;
    bool availability;
    int employeeID;
    vector<Procedure*> procedures; // Vector to store procedures associated with the medical staff
    string licenseNumber;


public:
    MedicalStaff(string name, string specialization, bool availability, int employeeID);
    virtual void displayInfo() const;
    bool isAvailable() const;

    // Accessor and modifier for procedures
    const vector<Procedure*>& getProcedures() const;
    void addProcedure(Procedure* procedure);

    string getSpecialization() const { return specialization; }

    
};

    MedicalStaff*  findMedicalStaff(const string& specialization, const vector<MedicalStaff*>& staffMembers ) ;



class Doctor : public MedicalStaff {
public:
    Doctor(string name, string specialization, bool availability, int employeeID, string licenseNumber);

    void displayInfo() const override;  // override the virtual function

private:
    string licenseNumber;
};

class Nurse : public MedicalStaff {
public:
    Nurse(string name, string specialization, bool availability, int employeeID);

    void displayInfo() const override;  // override the virtual function
};

class MedicalStaffManager {
public:
    static MedicalStaff* assignMedicalStaff(const string& specialization);
};

// Exception handling for invalid name
// redifinition of InvalidNameException
// class InvalidNameException : public BaseException {
// public:
//     void invalidNames(const std::string& Name) {
//         try {
//             for (char c : Name) {
//                 if (!isalpha(c)) {
//                     throw std::invalid_argument("Names must contain letters only.");
//                 }
//             }
//         }
//         catch (const std::invalid_argument& e) {
//             reportError(e.what());
//         }
//     }
// };



#endif // MEDICALSTAFF_H
