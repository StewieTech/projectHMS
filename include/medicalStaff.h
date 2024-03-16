#ifndef MEDICALSTAFF_H
#define MEDICALSTAFF_H
#include <string>
#include "exceptions.h"

using namespace std;


class MedicalStaff {
public:
    MedicalStaff(string name, string specialization, bool availability, int employeeID);

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

#include "medicalStaff.h"

class MedicalStaffManager {
public:
    static class MedicalStaff* assignMedicalStaff(const string& specialization);
};

// Exception handling for invalid name
class InvalidNameException : public BaseException {
public:
    void invalidNames(const std::string& Name) {
        try {
            for (char c : Name) {
                if (!isalpha(c)) {
                    throw std::invalid_argument("Names must contain letters only.");
                }
            }
        } catch (const std::invalid_argument& e) {
            reportError(e.what());
        }
    }
};
#endif // MEDICALSTAFF_H
