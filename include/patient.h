#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "Appointment.h" 

using namespace std;

class Inpatient;
class Outpatient;

class Patient {
public:
    Patient(string name, int age, char gender);
    virtual ~Patient();

    virtual string displayInfo() const;
    virtual int getId() const;  // Hypothetical function to retrieve ID

    // Additional member functions
    void updateInfo(int newAge, char newGender);
    void addMedicalProcedure(string procedureName);
    string getHealthHistory() const;

    // Function to set the appointment
    void setAppointment(Appointment* appointment);

protected:
    string name;
    int age;
    char gender;
    int id;  // Assuming each patient has a unique ID
    vector<string> medicalProcedures;  // Store a list of medical procedures
    Appointment* appointment;  // Pointer to the patient's appointment
};

class Inpatient : public Patient {
public:
    Inpatient(string name, int age, char gender, int roomNumber);
    virtual string displayInfo() const override;

private:
    int roomNumber;
};

class Outpatient : public Patient {
public:
    Outpatient(string name, int age, char gender, string appointmentDate, string doctorName);
    virtual string displayInfo() const override;

private:
    string appointmentDate;
    string doctorName;
};

#endif // PATIENT_H
