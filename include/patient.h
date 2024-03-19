#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <time.h>
#include "appointment.h"
#include "exceptions.h"
#include "procedure.h"

using namespace std;

// Forward declaration to avoid circular dependencies
class Appointment;
class InPatient;
class OutPatient;
class Procedure; // Forward declaration of Procedure class

class Patient {
    friend class Appointment; // Allow access from Appointment objects;

public:
    Patient(int patientID, string name, int age, char gender); // Constructor
    virtual ~Patient(); // Destructor

    string getName() const { return name; }     // Getter method for name


    // Accessors - getters
    int getId() const;
    int getAge() const;
    char getGender() const;
    string getAddress() const;
    int getPhoneNum() const;
    string getDept() const;
    bool getUrgency() const;
    bool getStatusInpatient() const;
    bool getStatusOutpatient() const;
    Appointment* getInitStep() const;
    Appointment* getNextStep() const;
    int getTotalInCents() const;
    const vector<Procedure*>& getProcedures() const; // Getter for procedures
    void addProcedure(Procedure* procedure); // Function to add a medical procedure

    // Accessors - setters
    void setID(int i);
    void setName(string n);
    void setAge(int i);
    void setGender(char g);
    void setDept(string d);
    void setUrgency();
    void resetUrgency();
    void setInpatient();
    void resetInpatient();
    void setOutpatient();
    void resetOutpatient();
    void setAppointment(Appointment* appointment);
    void setTotalInCents(int t);

    // Member functions
    void preProcess();
    virtual void displayInfo() const;
    void displayHealthHistory() const;
    Appointment* getHealthHistory() const;

    // Friend function declarations
    friend void setPatientAppointment(Patient* patient, Appointment* appointment);
    friend void displayHistory(const Patient& patient);

protected:
    string name;
    int age;
    char gender;
    string address;
    string phoneNum;
    int patientID;
    vector<Procedure*> procedures; // Store a list of medical procedures
    bool flag_urgency = false;
    string dept;
    bool is_inpatient = false;
    bool is_outpatient = false;
    Appointment* initialStep;
    Appointment* nextStep;
    int totalExpenseByCents;
};

Patient* findPatientByName(const string& name, const vector<Patient*>& patients);

#endif // PATIENT_H
