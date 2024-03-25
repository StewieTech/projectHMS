
#ifndef PATIENTVF_H
#define PATIENTVF_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <memory>
#include "appointmentVF.h"

class Appointment; // Forward declaration of Appointment class

class Patient {
public:
    // Constructors & Destructor
    Patient(int pID = 0, std::string n = "Unknown", int a = 0, char g = 'M', std::string add = "Unknown", std::string pN = "Unknown", std::string d = "Unassigned", bool urg = false, bool ip = false, bool op = false, Appointment* is = nullptr, Appointment* ns = nullptr, int tebc = 0);
    ~Patient();

    // Accessors - getters
    int getId() const;
    std::string getName() const;
    int getAge() const;
    char getGender() const;
    std::string getAddress() const;
    std::string getPhoneNum() const;
    std::string getDept() const;
    bool getUrgency() const;
    bool getStatusInpatient() const;
    bool getStatusOutpatient() const;
    Appointment* getInitStep() const;
    Appointment* getNextStep() const;
    int getTotalInCents() const;
    std::list<Procedure*> getProcedure() const;

    // Setters
    void setID(int i);
    void setName(std::string n);
    void setAge(int i);
    void setGender(char g);
    void setAddress(std::string add);
    void setPhoneNum(std::string pN);
    void setDept(std::string d);
    void setUrgency(bool urg);
    void setInpatient();
    void setOutpatient();
    void setAppointment(Appointment* appointment);
    void setTotalInCents(int t);
    void setProcedure(std::list<Procedure*> procedureList);

    // Member functions
    void displayInfo() const;

protected:
    std::string name;
    int age;
    char gender;
    std::string address;
    std::string phoneNum;
    int patientID;
    bool flag_urgency = false;
    std::string dept;
    bool is_inpatient = false;
    bool is_outpatient = false;
    Appointment* initialStep;
    Appointment* nextStep;
    int totalExpenseByCents;
    std::list<Procedure*> procedure;
};

class InPatient : public Patient {
public:
    InPatient(int pID, std::string n, int a, char g, std::string add, std::string pN, std::string d, int rn, Appointment* is, Appointment* ns, int tebc, time_t it, time_t ot);
    void displayInfo() const;

    // Accessors - getters
    int getRoomNo() const;
    time_t getInTime() const;
    time_t getOutTime() const;

    // Accessors - setters
    void setRoomNo(int r);
    void setInTime(time_t it);
    void setOutTime(time_t ot);

    void exitCured();

protected:
    int roomNumber;
    time_t inTime;
    time_t outTime;
};

class OutPatient : public Patient {
public:
    OutPatient(int pID, std::string n, int a, char g, std::string add, std::string pN, std::string d, Appointment* is, Appointment* ns, int tebc);
    void displayInfo() const;

    void exitCured();

protected:
    bool flag_urgency = false;
    bool is_inpatient = false;
    bool is_outpatient = true;
};

class patientManager {
public:
    static Patient* findPatientByName(const std::string& name, const std::list<std::unique_ptr<Patient>>& patientList);
    static Patient* findPatientById(int id, const std::list<std::unique_ptr<Patient>>& patientList);

    Patient* addNewPatient();
};

#endif // PATIENTVF_H
