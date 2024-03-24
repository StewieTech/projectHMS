#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <list>
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
    list<Procedure*> getProcedure() const;


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
    void setProcedure(list<Procedure*> procedureList);

    // Member functions
    virtual void displayInfo() const;

    // Friend function declarations
    friend void setPatientAppointment(Patient* patient, Appointment* appointment);

protected:
    string name;
    int age;
    char gender;
    string address;
    string phoneNum;
    int patientID;
    bool flag_urgency = false;
    string dept;
    bool is_inpatient = false;
    bool is_outpatient = false;
    Appointment* initialStep;
    Appointment* nextStep;
    int totalExpenseByCents;
    list<Procedure*> procedure;

};

class InPatient : public Patient {
	friend class Appointment; // allows access from Appointment objects
public:
    InPatient(int pID, string n, int a, char g, string add, string pN, string d, int rn, Appointment* is, Appointment* ns, int tebc, time_t it, time_t ot);
    virtual void displayInfo() const;

    // Accessors - getters
    int getRoomNo() const;
    time_t getInTime() const;
    time_t getOutTime() const;

    // Acceessors - setters
    void setRoomNo(int r);
    void setInTime(time_t it);
    void setOutTime(time_t ot);

    void setAppointment(Appointment* appointment);
    void setTotalInCents(int t);

    //other functions
    void exitCured();

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
    OutPatient(string name, int age, char gender, string appointmentDate, string doctorName);
    string displayInfo() const;

    //Accessors

    //Other func
	void exitCured();

protected:
    bool flag_urgency = false;
    bool is_inpatient = false;
	bool is_outpatient = true;
};


#endif // PATIENT_H
