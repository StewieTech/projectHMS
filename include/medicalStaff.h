#ifndef MEDICALSTAFF_H
#define MEDICALSTAFF_H

#include <string>
#include <vector>
#include "procedure.h"
#include "exceptions.h"

using namespace std;

class MedicalStaff {
protected:
    string name;
    string specialization;
    bool availability; 
    int employeeID;
    vector<Procedure*> procedures; // Vector to store procedures associated with the medical staff

public:
    MedicalStaff(string name, string specialization, bool availability, int employeeID);
    virtual ~MedicalStaff(); // Virtual destructor to ensure proper cleanup
    virtual void displayInfo() const;
    bool isAvailable() const; // Declaration of the isAvailable method
    const vector<Procedure*>& getProcedures() const;
    void addProcedure(Procedure* procedure);
    string getSpecialization() const { return specialization; }
};

class Doctor : public MedicalStaff {
private:
    string licenseNumber;

public:
    Doctor(string name, string specialization, bool availability, int employeeID, string licenseNumber);
    void displayInfo() const override;
};

class Nurse : public MedicalStaff {
public:
    Nurse(string name, string specialization, bool availability, int employeeID);
    void displayInfo() const override;
};

class MedicalStaffManager {
public:
    static MedicalStaff* assignMedicalStaff(const string& specialization);
    static MedicalStaff* findMedicalStaff(const string& specialization, const vector<MedicalStaff*>& staffMembers);
};

#endif // MEDICALSTAFF_H
