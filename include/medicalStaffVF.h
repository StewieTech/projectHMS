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
// Forward declaration to avoid circular dependencies
// class Appointment;
// class InPatient;
// class OutPatient;
class Procedure;

class MedicalStaff {
protected:
    std::string name;
    std::string specialization;
    bool availability;
    int employeeID;
    std::vector<Procedure*> procedures; // Vector to store procedures associated with the medical staff
    std::string licenseNumber;


public:
    MedicalStaff(std::string name, std::string specialization, bool availability, int employeeID);
    virtual void displayInfo() const;
    bool isAvailable() const;

    // Accessor and modifier for procedures
    const std::vector<Procedure*>& getProcedures() const;
    void addProcedure(Procedure* procedure);

    std::string getSpecialization() const { return specialization; }

    
};

    MedicalStaff*  findMedicalStaff(const std::string& specialization, const std::vector<MedicalStaff*>& staffMembers ) ;



class Doctor : public MedicalStaff {
public:
    Doctor(std::string name, std::string specialization, bool availability, int employeeID, std::string licenseNumber);

    void displayInfo() const override;  // override the virtual function

private:
    std::string licenseNumber;
};

class Nurse : public MedicalStaff {
public:
    Nurse(std::string name, std::string specialization, bool availability, int employeeID);

    void displayInfo() const override;  // override the virtual function
};

class MedicalStaffManager {
public:
    static MedicalStaff* assignMedicalStaff(const std::string& specialization);
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
