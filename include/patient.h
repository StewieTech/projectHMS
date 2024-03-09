#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <time.h>
#include "Appointment.h" 

using namespace std;

class Appointment;
class InPatient;
class OutPatient;

class Patient {
	friend class Appointment; // allow access from Appointment objects;
public:
    Patient(int ID, string name, int age, char gender); // need to set initial appointment here
    virtual ~Patient();

    // Accessors - getters
    int getId() const;  // Retrieve ID. No need to override
	string getName() const;
	int getAge() const;
	char getGender() const;
	string getInsurer() const;
	string getInsuranceNum() const;
	int getHp() const;
	int getSan() const;
	string getDept() const;

	bool getUrgency() const;
	bool getStatusInpatient() const;
	bool getStatusOutpatient() const;

	Appointment* getInitStep() const;
	Appointment* getNextStep() const;
	int getTotalInCents() const;

	//Accessors - setters
	Patient* setID(int i);
	Patient* setName(string n);
	Patient* setAge (int i);
	Patient* setGender(char g);
	Patient* setInsurer(string i);
	Patient* setInsuranceNum(string i);
	Patient* setHp(int h);
	Patient* setSan(int s);
	Patient* setDept(string d);

	Patient* setUrgency();
	Patient* resetUrgency();
	Patient* setInpatient();
	Patient* resetInpatient();
	Patient* setOutpatient();
	Patient* resetOutpatient();

	Patient* setAppointment(Appointment* appointment);
	Patient* setTotalInCents(int t);


    // Member functions
	Patient* preProcess();
    virtual void displayInfo() const;
	/*
	void confirmInfo(int newAge, char newGender, string address, int phoneNum); //confirm patient info function
    void updateInfo(int newAge, char newGender, string address, int phoneNum); //update patient info function
    void addMedicalProcedure(string procedureName); //add medical procedure function - not sure if I will keep it
    */
    void displayHealthHistory () const;
    Appointment* getHealthHistory() const; //function to get health history

protected:
    string name;
    int age;
    char gender;
    string insurer;
    string insuranceNum;
    int id;  // Assuming each patient has a unique ID
    vector<string> medicalProcedures;  // Store a list of medical procedures

    bool flag_urgency = false;	// Pls display urgent patients first in all caller functions

	int hp;		// has range of 1-5
	int san;	// has range of 1-5
	string dept;	// range within defined departments

	// Determined by pre-process
	/* On the application level, when patient is classified, pls create new objects of derived class accordingly
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

class InPatient : public Patient {
public:
    InPatient(string name, int age, char gender, int roomNumber, appointment * appointment);
    virtual string displayInfo() const override;

private:
    int roomNumber;

    friend class Appointment; // allows access from Appointment objects
public:
	InPatient(int ID, string name, int age, char gender, int roomNumber, Appointment * appointment));

	// Accessors - getters
	int getRoomNum() const;
	time_t getInTime() const;
	time_t getInTime() cosnt;

	// Acceessors - setters
	InPatient* setRoomNum(int r);
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
	string displayInfo() const override;

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
};

#endif // PATIENT_H
