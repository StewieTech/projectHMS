/*
 * patient.cpp
 *
 *  Created on: 2024-03-16
 *      Author: swu33
 */

#include "patient.h"

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

//WIP
char Patient:: getGender() const;

string Patient:: getAddress() const;

int Patient:: getPhoneNum() const;

string Patient:: getDept() const;

bool Patient:: getUrgency() const;

bool Patient:: getStatusInpatient() const;

bool Patient:: getStatusOutpatient() const;

Appointment* Patient:: getInitStep() const;

Appointment* Patient:: getNextStep() const;

int Patient:: getTotalInCents() const;

const Patient:: vector<Procedure*>& getProcedures() const; // Getter for procedures

void Patient:: addProcedure(Procedure* procedure); // Function to add a medical procedure


//Member Functions

/*
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

	bool is_inpatient = false;
	bool is_outpatient = false;


	Appointment* initialStep;
	Appointment* nextStep;
	int totalExpenseByCents;
};

Patient* findPatientByName(const string& name, const vector<Patient*>& patients)  // may need to remove
*/
