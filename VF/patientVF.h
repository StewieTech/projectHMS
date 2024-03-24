#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <memory>
#include <ctime>
#include <time.h>
#include "appointmentVF.h"

// #include "exceptionsVF.h"
// #include "procedureVF.h"

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
    Patient(int pID=0, string n="Unknown", int a=0, char g='M', string add="Unknown", string pN="Unknown", string d="Unassigned", bool urg=false, bool ip=false, bool op=false, Appointment* is=nullptr, Appointment* ns=nullptr, int tebc=0);
    virtual ~Patient();

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
    int getTotalInCents() const;
    list<Procedure*> getProcedure() const;


    // Accessors - setters
    void setID(int i);
    void setName(string n);
    void setAge(int i);
    void setGender(char g);
    void setAddress(string add);
    void setPhoneNum(string pN);
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
    Appointment* initialStep;		// this part is already addressed in appointment so no need to implement
    Appointment* nextStep;			// this part is already addressed in appointment so no need to implement
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
    OutPatient(int pID, string n, int a, char g, string add, string pN, string d, Appointment* is, Appointment* ns, int tebc);
    void displayInfo() const;

    //Accessors

    //Other func
	void exitCured();

protected:
    bool flag_urgency = false;
    bool is_inpatient = false;
	bool is_outpatient = true;
};

class patientManager
{
public:
	static Patient* findPatientByName(const string& name, const list<unique_ptr<Patient>>& patientList);
	static Patient* findPatientById(int id, const list<unique_ptr<Patient>>& patientList);

	//prompt for adding new patient
	Patient* addNewPatient();
};

#endif // PATIENT_H

/*
 * Sample run script:
 *
	patientManager pM1;
	list<unique_ptr<Patient>> patientsList;

	//new patient
	unique_ptr<Patient> p1(pM1.addNewPatient());
	patientsList.push_back(move(p1));
	patientsList.back()->displayInfo();

	// Display information of all patients in the list
	for (const auto& patientPtr : patientsList) {
		patientPtr->displayInfo();
		std::cout << "---------------------------------------" << std::endl;
	}
	return 0;
 *
 * UI:
Please add new patient:
Please enter patient ID (integer):
101
Please enter patient name (string):
John Doe
Please enter patient age (int):
35
Please enter patient gender (M or F):
M
Please enter patient address (string):
123 Main Street
Please enter patient phone number (string):
555-123-4567
Please enter patient department (string):
Cardiology
Patient has urgency? (Y/N)
Y
Patient is a defined in-patient? (Y/N)
Y
Please input scheduled room number (integer):
101
Please input in time. Is the year 2024? (Y/N):
Y
Please input month (1-12):
3
Please input day (1-30):
21
Please input hour (0-23):
10
Success! In time: 2024 March 21, 10:00
Please input scheduled out time. Is the year 2024? (Y/N):
Y
Please input month (1-12):
3
Please input day (1-30):
28
Please input hour (0-23):
14
Success! Out time: 2024 March 28, 14:00

Please add new patient:
Please enter patient ID (integer):
102
Please enter patient name (string):
Jane Smith
Please enter patient age (int):
45
Please enter patient gender (M or F):
F
Please enter patient address (string):
456 Oak Avenue
Please enter patient phone number (string):
555-987-6543
Please enter patient department (string):
Orthopedics
Patient has urgency? (Y/N)
N
Patient is a defined in-patient? (Y/N)
N
Patient is a defined out-patient? (Y/N)
Y
Please input scheduled check-in time. Is the year 2024? (Y/N):
Y
Please input month (1-12):
3
Please input day (1-30):
25
Please input hour (0-23):
11
Success! Check-in time: 2024 March 25, 11:00

Please add new patient:
Please enter patient ID (integer):
103
Please enter patient name (string):
Michael Johnson
Please enter patient age (int):
50
Please enter patient gender (M or F):
M
Please enter patient address (string):
789 Elm Street
Please enter patient phone number (string):
555-222-3333
Please enter patient department (string):
Neurology
Patient has urgency? (Y/N)
N
Patient is a defined in-patient? (Y/N)
Y
Please input scheduled room number (integer):
103
Please input in time. Is the year 2024? (Y/N):
Y
Please input month (1-12):
3
Please input day (1-30):
20
Please input hour (0-23):
9
Success! In time: 2024 March 20, 09:00
Please input scheduled out time. Is the year 2024? (Y/N):
N
Success! Out time: 2024 March 23, 12:00

Patient ID: 101
Name: John Doe
Age: 35
Gender: M
Dept: Cardiology

Address: 123 Main Street
Phone #: 555-123-4567
Room #: 101
Urgency: Y
Patient Status: In-patient
Since: Sat Mar 21 10:00:00 2024
To: Wed Mar 28 14:00:00 2024
Current bill payable: 0.00
---------------------------------------

Patient ID: 102
Name: Jane Smith
Age: 45
Gender: F
Dept: Orthopedics

Address: 456 Oak Avenue
Phone #: 555-987-6543
Urgency: N
Patient Status: Out-patient
Next step: Check-in
Scheduled check-in: 2024 March 25, 11:00
Current bill payable: 0.00
---------------------------------------

Patient ID: 103
Name: Michael Johnson
Age: 50
Gender: M
Dept: Neurology

Address: 789 Elm Street
Phone #: 555-222-3333
Room #: 103
Urgency: N
Patient Status: In-patient
Since: Fri Mar 20 09:00:00 2024
To: Sat Mar 23 12:00:00 2024
Current bill payable: 0.00
---------------------------------------
 *
 */
