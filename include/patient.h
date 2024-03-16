#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <time.h>
#include "Appointment.h"
#include "exceptions.h"
#include "Procedure.h" 

// using namespace std;  // removing as causing compiling issues

// Forward declaration to avoid circular dependencies
class Appointment;
class InPatient;
class OutPatient;
class Procedure; // Forward declaration of Procedure class

class Patient {
	friend class Appointment; // allow access from Appointment objects;
public:
	Patient(int patientID, string name, int age, char gender); // Constructor
	virtual ~Patient(); // Destructor

	// Accessors - getters
	int getId() const;
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

Patient* findPatientByName(const string& name, const vector<Patient*>& patients)

#endif // PATIENT_H

