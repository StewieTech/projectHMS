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
    // Constructor & Destructor
    Patient(int pID, string n, int a, char g, string add="Unknown", string pN="Unknown", string d="Unassigned", bool urg=false, bool ip=false, bool op=false, Appointment* is, Appointment* ns, int tebc=0);
    virtual ~Patient();

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
    vector<Procedure*>& getProcedures() const; // Getter for procedures


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
    void addProcedure(Procedure* procedure); // Function to add a medical procedure

    // Member functions
    void preProcess();
    void displayInfo() const;
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

class InPatient : public Patient {
	friend class Appointment; // allows access from Appointment objects
public:
    InPatient(int pID, string n, int a, char g, string add, string pN, string d, int rn, Appointment* is, Appointment* ns, int tebc );
    string displayInfo() const override;

    // Accessors - getters
    int getRoomNo() const;
    time_t getInTime() const;
    time_t getInTime() cosnt;

    // Acceessors - setters
    InPatient* setRoomNo(int r);
    InPatient* setInTime(time_t it);
    InPatient* setOutTime(time_t ot);

    InPatient* setAppointment(Appointment* appointment);
    InPatient* setTotalInCents(int t);

    //other functions
    InPatient* randomProcess();
    InPatient* redoClassify();
    InPatient* transferToOutPatient();
    InPatient* transferOut(string nameHospital);
    InPatient* exitCured();
    // A function to gather history appointments and present them
	void displayHistory();

protected:
	int roomNumber;
    time_t inTime;
    time_t outTime;

    bool is_inpatient = true;
	bool is_outpatient = false;
};


class OutPatient : public Patient {
	friend class Appointment; // allows access from Appointment objects
public:
    Outpatient(string name, int age, char gender, string appointmentDate, string doctorName);
    virtual string displayInfo() const override;

    //Accessors
    //Accessors - getters
    time_t getAppTime();
    string getDocName();
    //Accessors - setters
    OutPatient* setAppTime(time_t at);
    OutPatient* setDocName(string dn);

    //Other func
    OutPatient* randomProcess();
    OutPatient* redoClassify();
    OutPatient* transferToInPatient();
    OutPatient* transferOut(string nameHospital);
	OutPatient* exitCured();
    // A function to gather history appointments and present them
	void displayHistory();

protected:
    time_t appointmentTime;
    string doctorName;

    bool flag_urgency = false;
    bool is_inpatient = false;
	bool is_outpatient = true;
};


#endif // PATIENT_H
