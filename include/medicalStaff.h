#ifndef MEDICALSTAFF_H
#define MEDICALSTAFF_H
#include <string>

using namespace std;


class MedicalStaff {
public:
    MedicalStaff(string name, string specialization, bool availability, employeeID);

    virtual void displayInfo() const;  

    bool isAvailable() const;

protected:
    string name;
    string specialization;
    bool availability;
};


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

private:
    int employeeId;
};

class MedicalStaffManager {
public:
    static MedicalStaff* assignMedicalStaff(const string& specialization);
};

#endif // MEDICALSTAFF_H
