#ifndef MEDICALSTAFF_H
#define MEDICALSTAFF_H

#include <string>
#include <vector>
#include "procedure.h"
#include "exceptions.h"  

using namespace std;

class Appointment; // Forward declaration of Appointment class

class MedicalStaff {
protected:
     string name; //medical staff person's name
     string specialization; //specialization for medical staff
    bool availability; //availability status for medical staff
    int employeeID; //employee ID of medical staff
     vector<Procedure*> procedures; // Vector to store procedures associated with the medical staff

public:
    MedicalStaff( string name,  string specialization, bool availability, int employeeID); //Constructor
    virtual ~MedicalStaff(); // Virtual destructor to ensure proper cleanup
    virtual void displayInfo() const; //Virtual method to display medical staff information
    bool isAvailable() const; //Method to check availability
    const  vector<Procedure*>& getProcedures() const;
    void addProcedure(Procedure* procedure); //Getter method for procedures vector
     string getSpecialization() const; // Getter method for specialization
     string getName() const; // Getter method for name
    bool getAvailability() const; // Getter method for availability
    int getEmployeeID() const; // Getter method for employeeID

    // Method to set appointment for medical staff
    void setAppointment(Appointment* appointment);
};

class Doctor : public MedicalStaff {
private:
     string licenseNumber; //license number of the doctor

public:
    Doctor( string name,  string specialization, bool availability, int employeeID,  string licenseNumber); //constructor
    void displayInfo() const override; //Method to display doctor's information
};

class Nurse : public MedicalStaff {
public:
    Nurse( string name,  string specialization, bool availability, int employeeID); //constructor
    void displayInfo() const override; //Method to display nurse's information
};

class MedicalStaffManager {
public:
     //Static method to assign medical staff based on specialization
    static MedicalStaff* assignMedicalStaff(const  string& specialization);
    //Static method to find medical staff based on specialization
    static MedicalStaff* findMedicalStaff(const  string& specialization, const  vector<MedicalStaff*>& staffMembers);
};

#endif // MEDICALSTAFF_H
