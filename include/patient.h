#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <time.h>
#include "Appointment.h" 
#include "exceptions.h"
#include "Procedure.h" 

using namespace std;

// Forward declaration to avoid circular dependencies
class Appointment;
class InPatient;
class OutPatient;

class Procedure; // Forward declaration of Procedure class

class Patient {
	friend class Appointment; // allow access from Appointment objects;
public:
	Patient(int patientID, string name, int age, char gender); // need to set initial appointment here
	virtual ~Patient();

	// Accessors - getters
	int getId() const;  // Retrieve ID. No need to override
	string getName() const;
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

	// Accessor and modifier for procedures
	const vector<Procedure*>& getProcedures() const;
	void addProcedure(Procedure* procedure);

	//Accessors - setters
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
	/*
	void confirmInfo(int newAge, char newGender, string address, int phoneNum); //confirm patient info function
	void updateInfo(int newAge, char newGender, string address, int phoneNum); //update patient info function
	void addMedicalProcedure(string procedureName); //add medical procedure function - not sure if I will keep it
	*/
	void displayHealthHistory() const;
	Appointment* getHealthHistory() const; //function to get health history

protected:
	string name;
	int age;
	char gender;
	string address;
	string phoneNum;
	int patientID;  // Assuming each patient has a unique ID
	vector<string> medicalProcedures;  // Store a list of medical procedures

	bool flag_urgency = false;	// Pls display urgent patients first in all caller functions

	string dept;	// range within defined departments

	// Determined by pre-process
	/* On the application level, when patient is classified, to create new objects of derived class accordingly
	 * We can use "static_cast<Derived*>(this)->derivedMethod();" to do so,
	 * but creating a pointer to derived class might cause internal memory leak - pls remind me to write lesson learned
	 */
	bool is_inpatient = false;
	bool is_outpatient = false;

	/*
	 * The list will be in-build, as:
	 * Patient: reception -> appointment.pre-process -> classification into outpatient & inpatient;
	 * 		Outpatient: appointment.testing & consultation (...-> more testing if needed) -> payment;
	 * 		Inpatient: 	inpatient.room allocation (built in) -> appointment.treatment -> appointment.monitoring -> billing;
	 */
	Appointment* initialStep;
	Appointment* nextStep;
	int totalExpenseByCents;

};


#endif // PATIENT_H
