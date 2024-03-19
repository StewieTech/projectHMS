/*
 * patient.cpp
 *
 *  Created on: 2024-03-16
 *      Author: swu33
 */

#include "patient.h"

//Base clasee: patient:
//Constructors
/*	Func name:	Patient
 *	Summary:	Takes inputs as data fields and generate Patient objects
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		WIP
 */
Patient::Patient(int pID, string n, int a, char g, string add, string pN, string d, bool urg=false, bool ip=false, bool op=false, Appointment* is, Appointment* ns, int tebc ){
	name=n;
	age=a;
	gender=g;
	patientID=pID;

	address = add;
	phoneNum = pN;
	dept = d;

	//WIP
	vector<Procedure*> procedures; // Store a list of medical procedures

	flag_urgency = urg;
	is_inpatient = ip;
	is_outpatient = op;
	initialStep=is;
	nextStep = ns;
	totalExpenseByCents = tecp;
}

Patient:: ~Patient(){
	// Destructor code here if needed
}

// Accessors - getters
/*	Func name:	getID
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
int Patient:: getId() const{
	return patientID;
}

/*	Func name:	getName
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
string Patient:: getName() const
{
	return name;
}

/*	Func name:	getAge
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
int Patient:: getAge() const
{
	return age;
}

/*	Func name:	getAge
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
char Patient:: getGender() const
{
	return age;
}

/*	Func name:	getAddress
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
string Patient:: getAddress() const
{
	return address;
}

/*	Func name:	getPhoneNum
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
int Patient:: getPhoneNum() const
{
	return phoneNum;
}

/*	Func name:	getDept
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
string Patient:: getDept() const
{
	return dept;
}

/*	Func name:	getUrgency
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
bool Patient:: getUrgency() const
{
	return flag_urgency;
}

/*	Func name:	getStatusInpatient
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
bool Patient:: getStatusInpatient() const
{
	return is_inpatient;
}

/*	Func name:	getStatusOutpatient
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
bool Patient:: getStatusOutpatient() const
{
	return is_outpatient;
}

/*	Func name:	getInitStep
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
Appointment* Patient:: getInitStep() const
{
	return initialStep;
}

/*	Func name:	getNextStep
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
Appointment* Patient:: getNextStep() const
{
	return nextStep;
}

/*	Func name:	getTotalInCents
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
int Patient:: getTotalInCents() const
{
	return totalExpenseByCents;
}

/*	Func name:	getProcedures
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		WIP: a global procedure needs to be created
 */
const vector<Procedure*>& Patient::getProcedures() const // Getter for procedures
{
	//WIP
}

/*	Func name:	setID
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setID(int i)
{
	patientID=i;
}

/*	Func name:	setName
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setName(string n)
{
	name = n;
}

/*	Func name:	setAge
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setAge(int i)
{
	age = i;
}

/*	Func name:	setGender
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setGender(char g)
{
	gender = g;
}

/*	Func name:	setDept
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setDept(string d)
{
	depy = d;
}

/*	Func name:	setUrgency
 *	Summary:	set urgency to true
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setUrgency()
{
	flag_urgency = true;
}

/*	Func name:	setUrgency
 *	Summary:	set urgency to false
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::resetUrgency()
{
	flag_urgency = false;
}

/*	Func name:	setInpatient
 *	Summary:	set inpatient to true;
 *				make sure that a patient is not an outpatient at the same time
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setInpatient()
{
	is_inpatient = true;
	is_outpatient = false;
}

/*	Func name:	resetInpatient
 *	Summary:	set inpatient to false
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::resetInpatient()
{
	is_inpatient = false;
}

/*	Func name:	setOutpatient
 *	Summary:	set outpatient to true;
 *				make sure that a patient is not an inpatient at the same time
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setOutpatient()
{
	is_outpatient = true;
	is_inpatient = false;
}

/*	Func name:	resetOutpatient
 *	Summary:	set outpatient to false
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::resetOutpatient()
{
	is_outpatient = false;
}

/*	Func name:	setAppointment
 *	Summary:	set a pointer to apppointment as the next step
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setAppointment(Appointment* appointment)
{
	nextStep = appointment;
}

/*	Func name:	setTotalInCents
 *	Summary:	sets bill amount to i (in cents)
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::setTotalInCents(int t)
{
	totalExpenseByCents = i;
}

/*	Func name:	addProcedures
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		WIP: a global procedure needs to be created
 */
void Patient:: addProcedure(Procedure* procedure) // Function to add a medical procedure


//Member Functions
/*	Func name:	addProcedures
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		WIP: a global procedure needs to be created
 */
void Patient::preProcess();
void Patient::displayInfo() const;
void Patient::displayHealthHistory() const;
Appointment* Patient::getHealthHistory() const;



/*

class InPatient : public Patient {
	friend class Appointment; // allows access from Appointment objects
public:
    InPatient(int ID, string name, int age, char gender, int roomNumber);
    virtual string displayInfo() const override;

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



*/