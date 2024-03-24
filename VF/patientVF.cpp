/*
 * patient.cpp
 *
 *  Created on: 2024-03-16
 *      Author: swu33
 */


#include "patientVF.h"

//Base clasee: patient:
//Constructors
/*	Func name:	Patient
 *	Summary:	Takes inputs as data fields and generate Patient objects
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */


Patient::Patient(int pID, string n, int a, char g, string add, string pN, string d, bool urg, bool ip, bool op, Appointment* is, Appointment* ns, int tebc){
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
	totalExpenseByCents = tebc;

	// Procedure p1("check-in","create profile");
	// Procedure p2("pre-process","classify into in-patient and out-patient");
	// Procedure p3("test","default test");
	// Procedure p4("consultation", "default consultation");
	// Procedure p5("exit","patient exit");
	// Procedure pi5("surgery","default surgery");
	// Procedure pi6("care","in-house care");

	// procedure.push_back(&p1);
	// procedure.push_back(&p2);
	// procedure.push_back(&p3);
	// procedure.push_back(&p4);
	// procedure.push_back(&p5);
	// procedure.push_back(&pi5);
	// procedure.push_back(&pi6);


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
string Patient:: getPhoneNum() const
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

list<Procedure*> Patient::getProcedure() const
{
	return procedure;
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
	dept = d;
}

void Patient::setAddress(string add)
{
	address = add;

}
void Patient::setPhoneNum(string pN)
{
	phoneNum = pN;
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
	totalExpenseByCents = t;
}

void Patient::setProcedure(list<Procedure*> procedureList)
{
	procedure = procedureList;
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
	// cout<<"Next step:"<<nextStep->getProcedure()->getName(); Errol Removed

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
	initialStep = is;
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
		cout<<"Since: "<<ctime(&inTime);
		cout<<"To: "<<ctime(&outTime);
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
	nextStep = appointment;
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

	initialStep = is;
	nextStep= ns;
	totalExpenseByCents=tebc;
}

/*	Func name:	displayInfo
 *	Summary:
 *	Author：		SZW
 *	Last Mod:	2023-03-18
 *	Status:		Complete
 */
void OutPatient::displayInfo() const
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
		// cout<<"Next step:"<<nextStep->getProcedure()->getName();
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
void OutPatient::exitCured()
{
	nextStep=nullptr;
	flag_urgency = false;
	bool is_inpatient = false;
}

void setPatientAppointment(Patient* patient, Appointment* appointment)
{
	patient->setAppointment(appointment);
}

Patient* patientManager::addNewPatient()
{
	string buffer;
	int pID;
	string n;
	int a;
	char g;
	string add;
	string pN;
	string d="Unassigned";
	bool urg=false;
	bool ip=false;
	bool op=false;
	Appointment* is=nullptr;
	Appointment* ns=nullptr;
	int tebc=0;

	cout<<"Please add new patient:"<<endl;
	cout<<"Please enter patient ID (integer): "<<endl;
	cin>>buffer; pID = stoi(buffer);
	cin.ignore();

	cout<<"Please enter patient name (string):"<<endl;
	cin>>buffer; n=buffer;
	cin.ignore();

	cout<<"Please enter patient age (int):"<<endl;
	cin>>buffer; a=stoi(buffer);
	cin.ignore();

	cout<<"Please enter patient gender (M or F):"<<endl;
	cin>>buffer; g=buffer.at(0);
	cin.ignore();

	cout<<"Please enter patient address (string):"<<endl;
	cin>>buffer; add = buffer;
	cin.ignore();

	cout<<"Please enter patient phone number (string):"<<endl;
	cin>>buffer; pN = buffer;
	cin.ignore();

	cout<<"Please enter patient department (string):"<<endl;
	cin>>buffer; d = buffer;
	cin.ignore();

	cout<<"Patient has urgency? (Y/N)"<<endl;
	cin>>buffer;
	if ((buffer=="Y")||buffer=="y"){urg = true;}
	cin.ignore();

	cout<<"Patient is a defined in-patient? (Y/N)"<<endl;
	cin>>buffer;
	if ((buffer=="Y")||buffer=="y")
	{
		ip = true;
		cin.ignore();

		int rn;
		time_t it;
		time_t ot;

		int temp_year;
		int temp_month;
		int temp_day;
		int temp_hour;

		cout<<"Please input scheduled room number (integer): "<<endl;
		cin>>buffer; rn = stoi(buffer);
		cin.ignore();

		cout<<"Please input in time. Is the year 2024? (Y/N)"<<endl;
		cin>>buffer;
		cin.ignore();
		if((buffer=="Y"||buffer=="y"))
		{
			temp_year = 2024;
		}
		else
		{
			cout<<"Please input year (integer): "<<endl;
			cin>>buffer;
			temp_year = stoi(buffer);
			cin.ignore();
		}

		cout<<"Please input month (1-12): "<<endl;
		cin>>buffer; temp_month = stoi(buffer);
		cin.ignore();

		cout<<"Please input day (1-30): "<<endl;
		cin>>buffer; temp_day = stoi(buffer);
		cin.ignore();

		cout<<"Please input hour (0-23):"<<endl;
		cin>>buffer; temp_hour = stoi(buffer);
		cin.ignore();

		tm inputTime={0};
		inputTime.tm_year = temp_year-1900;
		inputTime.tm_mon = temp_month-1;
		inputTime.tm_mday = temp_day;
		inputTime.tm_hour = temp_hour;

		it = mktime(&inputTime);
		stringstream ss;
		ss << "Success! In time: ";
		ss << put_time(&inputTime, "%Y %B %d, %H:%M");
		cout << ss.str() << endl;

		cout<<"Please input scheduled out time. Is the year 2024? (Y/N)"<<endl;
		cin>>buffer;
		cin.ignore();
		if((buffer=="Y"||buffer=="y"))
		{
			temp_year = 2024;
		}
		else
		{
			cout<<"Please input year (integer): "<<endl;
			cin>>buffer;
			temp_year = stoi(buffer);
			cin.ignore();
		}

		cout<<"Please input month (1-12): "<<endl;
		cin>>buffer; temp_month = stoi(buffer);
		cin.ignore();

		cout<<"Please input day (1-30): "<<endl;
		cin>>buffer; temp_day = stoi(buffer);
		cin.ignore();

		cout<<"Please input hour (0-23):"<<endl;
		cin>>buffer; temp_hour = stoi(buffer);
		cin.ignore();

		inputTime.tm_year = temp_year-1900;
		inputTime.tm_mon = temp_month-1;
		inputTime.tm_mday = temp_day;
		inputTime.tm_hour = temp_hour;

		ot = mktime(&inputTime);
		ss << "Success! Out time: ";
		ss << put_time(&inputTime, "%Y %B %d, %H:%M");
		cout << ss.str() << endl;

		cout<<a<<endl;

		return new InPatient(pID, n, a, g, add, pN, d, rn, is, ns, 0, it, ot);
	}


	cout<<"Patient is a defined out-patient? (Y/N)"<<endl;
	cin>>buffer;
	if ((buffer=="Y")||buffer=="y")
	{
		op = true;
		cin.ignore();
		return new OutPatient(pID, n, a, g, add, pN, d, is, ns, 0);
	}

	return new Patient (pID, n, a, g, add, pN, d, urg, ip, op, is, ns, 0);

}
Patient* patientManager::findPatientByName(const string& name, const list<unique_ptr<Patient>>& patientList) {
        for (const auto& patient : patientList) {
            if (patient->getName() == name) {
                return patient.get();
            }
        }
        return nullptr; // Not found
    }

Patient* patientManager::findPatientById(int id, const list<unique_ptr<Patient>>& patientList) {
	for (const auto& patient : patientList) {
		if (patient->getId() == id) {
			return patient.get();
		}
	}
	return nullptr; // Not found
}
