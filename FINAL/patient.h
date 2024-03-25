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

    // Getters
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
    void displayInfo() const; //display patient information
    void addAppointment(const Appointment& appointment); //add appointment for the patient
    void displayAppointments() const; //display all appointments for the patient

    // Static member function to search for a patient by ID
    static Patient* searchById(int id, const list<unique_ptr<Patient>>& patientList);

private:
    string name; //patient name
    int age; //patient age
    char gender; //patient gender
    string address; //patient address
    string phoneNum; //patient phone number
    int patientID; //patient ID
    bool flagUrgency; //flag for whether patient needs urgent care
    string dept; //department associated with patient
    bool isInpatient; //flag for whether patient is in-patient
    bool isOutpatient; //flag or whether patient is out-patient
    Appointment* initialStep; //intial appointment for patient
    Appointment* nextStep; //subsequent appointment(s) for patient
    list<Appointment> appointments; // List of appointments for the patient
};

#endif // PATIENT_H
