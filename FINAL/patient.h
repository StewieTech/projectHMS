#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <ctime>
#include <list>
#include <memory>
#include "appointment.h"
#include "exceptions.h"

using namespace std;

class Appointment; // Forward declaration

class Patient {
public:
    // Constructors & Destructor
    Patient(int pID = 0, string n = "Unknown", int a = 0, char g = 'M', string add = "Unknown", string pN = "Unknown", string d = "Unassigned", bool urg = false, bool ip = false, bool op = false, Appointment* is = nullptr, Appointment* ns = nullptr, int tebc = 0);
    ~Patient();

    // Accessors - getters
    int getId() const;
    string getName() const;
    int getAge() const;
    char getGender() const;
    string getAddress() const;
    string getPhoneNum() const;
    string getDept() const;
    bool getUrgency() const;
    bool getStatusInpatient() const;
    bool getStatusOutpatient() const;
    Appointment* getInitStep() const;
    Appointment* getNextStep() const;

    // Setters
    void setId(int id);
    void setName(const string& name);
    void setAge(int age);
    void setGender(char gender);
    void setAddress(const string& address);
    void setPhoneNum(const string& phoneNum);
    void setDept(const string& dept);
    void setUrgency(bool urgency);
    void setStatusInpatient(bool inpatient);
    void setStatusOutpatient(bool outpatient);
    void setInitStep(Appointment* initStep);
    void setNextStep(Appointment* nextStep);

    // Member functions
    void displayInfo() const;
    void addAppointment(const Appointment& appointment);
    void displayAppointments() const;

    // Static member function to search for a patient by ID
    static Patient* searchById(int id, const list<unique_ptr<Patient>>& patientList);

private:
    string name;
    int age;
    char gender;
    string address;
    string phoneNum;
    int patientID;
    bool flagUrgency;
    string dept;
    bool isInpatient;
    bool isOutpatient;
    Appointment* initialStep;
    Appointment* nextStep;
    list<Appointment> appointments; // List of appointments for the patient
};

#endif // PATIENT_H
