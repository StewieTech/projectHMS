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
 *	Status:		Complete
 */
Patient::Patient(int pID, string n, int a, char g, string add="Unknown", string pN="Unknown", string d="Unassigned", bool urg=false, bool ip=false, bool op=false, Appointment* is, Appointment* ns, int tebc=0 ){
	name=n;
	age=a;
	gender=g;
	patientID=pID;

	address = add;
	phoneNum = pN;
	dept = d;

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

//Member Functions
/*	Func name:	displayInfo
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void Patient::displayInfo() const
{
	cout<<"Patient ID: "<<patientID<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Gender: "<<gender<<endl;
	cout<<"Dept: "<<dept<<endl;
	cout<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Phone #: "<<phoneNum<<endl;

	if (flag_urgency)
	{
		cout<<"Urgency: Y"<<endl;
	} else
	{
		cout<<"Urgency: N"<<endl;
	}

	if((!is_inpatient)&&(!is_outpatient))
	{
		cout<<"Patient Status: Unassigned"<<endl;
	}
	if(is_inpatient)
	{
		cout<<"Patient Status: In-patient"<<endl;
	}
	if(is_outpatient)
	{
		cout<<"Patient Status: Out-patient"<<endl;
	}

	cout<<endl;
	cout<<"Next step:"<<nextStep->getProcedure()->getName();
	cout<<"Scheduled: "<<nextStep->getAppointmentTime();
	cout<<endl;
	cout<<"Current bill payable: "<<(totalExpenseByCents/100.0)<<endl;
}

//Derived class: InPatient:
//Constructor & Destructor
InPatient::InPatient(int pID, string n, int a, char g, string add, string pN, string d, int rn, Appointment* is, Appointment* ns, int tebc, time_t it, time_t ot )
{
	patientID=pID;
	name=n;
	age=a;
	gender=g;
	address= add;
	phoneNum = pN;
	dept= d;
	roomNumber = rn;
	initStep = is;
	nextStep= ns;
	totalExpenseByCents=tebc;
	inTime = it;
	outTime = ot;

}

/*	Func name:	displayInfo
 *	Summary:	Outputs info of the inpatient on screen
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
void InPatient::displayInfo() const
{
	cout<<"Patient ID: "<<patientID<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Gender: "<<gender<<endl;
	cout<<"Dept: "<<dept<<endl;
	cout<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Phone #: "<<phoneNum<<endl;
	cout<<"Room #: "<<roomNumber<<endl;

	if (flag_urgency)
	{
		cout<<"Urgency: Y"<<endl;
	} else
	{
		cout<<"Urgency: N"<<endl;
	}

	if((!is_inpatient)&&(!is_outpatient))
	{
		cout<<"Patient Status: Unassigned"<<endl;
	}
	if(is_inpatient)
	{
		cout<<"Patient Status: In-patient"<<endl;
		cout<<"Since: "<<ctime(&inTime)<<endl;
		cout<<"To: "<<ctime(&outTime)<<endl;
	}
	if(is_outpatient)
	{
		cout<<"Patient Status: Out-Patient"<<endl;
	}
}

//Accessors - getters
/*	Func name:	getRoomNo
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
int InPatient::getRoomNo() const
{
	return roomNumber;
}

/*	Func name:	getInTime
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
time_t InPatient::getInTime() const
{
	return inTime;
}

/*	Func name:	getOutTime
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
time_t InPatient::getOutTime() const
{
	return outTime;
}

// Acceessors - setters
/*	Func name:	setRoomNo
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
void InPatient::setRoomNo(int r)
{
	roomNumber = r;
}

/*	Func name:	setInTime
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
void InPatient::setInTime(time_t it)
{
	inTime = it;
}

/*	Func name:	setOutTime
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
void InPatient::setOutTime(time_t ot)
{
	outTime = ot;
}

/*	Func name:	setAppointment
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
void InPatient::setAppointment(Appointment* appointment)
{
	nextStep = apoointment
}

/*	Func name:	setTotalInCents
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
void InPatient::setTotalInCents(int t)
{
	totalExpenseByCents = t;
}

//other functions
/*	Func name:	exitCured
 *	Summary:	Take current time and set as outTime
 *				Clear next step
 *				Clear flags
 *	Author：		SZW
 *	Last Mod:	2023-03-21
 *	Status:		Complete
 */
void InPatient::exitCured()
{
	time(&outTime);
	nextStep=NULL;
	flag_urgency = false;
	bool is_inpatient = false;
}

//Derieved class: Outpatient
//Constructor
OutPatient::OutPatient(int pID, string n, int a, char g, string add, string pN, string d, Appointment* is, Appointment* ns, int tebc)
{
	patientID=pID;
	name=n;
	age=a;
	gender=g;
	address= add;
	phoneNum = pN;
	dept= d;

	initStep = is;
	nextStep= ns;
	totalExpenseByCents=tebc;
}

/*	Func name:	displayInfo
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
string displayInfo() const
{
	cout<<"Patient ID: "<<patientID<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Gender: "<<gender<<endl;
	cout<<"Dept: "<<dept<<endl;
	cout<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Phone #: "<<phoneNum<<endl;

	if (flag_urgency)
	{
		cout<<"Urgency: Y"<<endl;
	} else
	{
		cout<<"Urgency: N"<<endl;
	}

	if((!is_inpatient)&&(!is_outpatient))
	{
		cout<<"Patient Status: Unassigned"<<endl;
	}
	if(is_inpatient)
	{
		cout<<"Patient Status: In-patient"<<endl;
	}
	if(is_outpatient)
	{
		cout<<"Patient Status: Out-patient"<<endl;
		cout<<"Next step:"<<nextStep->getProcedure()->getName();
		cout<<"Scheduled: "<<nextStep->getAppointmentTime();
	}

	cout<<endl;
	cout<<"Current bill payable: "<<(totalExpenseByCents/100.0)<<endl;
}

/*	Func name:	exitCured
 *	Summary:	Clear next step
 *				Clear flags
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void exitCured()
{
	nextStep=NULL;
	flag_urgency = false;
	bool is_inpatient = false;
}
