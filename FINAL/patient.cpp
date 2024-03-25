#include "patient.h"
#include <iostream>

using namespace std;

// Constructor
Patient::Patient(int pID, string n, int a, char g, string add, string pN, string d, bool urg, bool ip, bool op, Appointment* is, Appointment* ns, int tebc)
    : name(n), age(a), gender(g), address(add), phoneNum(pN), patientID(pID), flagUrgency(urg), dept(d), isInpatient(ip), isOutpatient(op), initialStep(is), nextStep(ns) {}

// Destructor
Patient::~Patient() {}

// Accessors - getters
int Patient::getId() const {
    return patientID;
}

string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

char Patient::getGender() const {
    return gender;
}

string Patient::getAddress() const {
    return address;
}

string Patient::getPhoneNum() const {
    return phoneNum;
}

string Patient::getDept() const {
    return dept;
}

bool Patient::getUrgency() const {
    return flagUrgency;
}

bool Patient::getStatusInpatient() const {
    return isInpatient;
}

bool Patient::getStatusOutpatient() const {
    return isOutpatient;
}

Appointment* Patient::getInitStep() const {
    return initialStep;
}

Appointment* Patient::getNextStep() const {
    return nextStep;
}

// Setters
void Patient::setId(int id) {
    patientID = id;
}

void Patient::setName(const string& name) {
    this->name = name;
}

void Patient::setAge(int age) {
    this->age = age;
}

void Patient::setGender(char gender) {
    this->gender = gender;
}

void Patient::setAddress(const string& address) {
    this->address = address;
}

void Patient::setPhoneNum(const string& phoneNum) {
    this->phoneNum = phoneNum;
}

void Patient::setDept(const string& dept) {
    this->dept = dept;
}

void Patient::setUrgency(bool urgency) {
    flagUrgency = urgency;
}

void Patient::setStatusInpatient(bool inpatient) {
    isInpatient = inpatient;
}

void Patient::setStatusOutpatient(bool outpatient) {
    isOutpatient = outpatient;
}

void Patient::setInitStep(Appointment* initStep) {
    initialStep = initStep;
}

void Patient::setNextStep(Appointment* nextStep) {
    this->nextStep = nextStep;
}

// Member functions
void Patient::displayInfo() const {
    cout << "Patient ID: " << patientID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNum << endl;
    cout << "Department: " << dept << endl;
    cout << "Urgency: " << (flagUrgency ? "Yes" : "No") << endl;
    cout << "Status: " << (isInpatient ? "Inpatient" : "Outpatient") << endl;
}

void Patient::addAppointment(const Appointment& appointment) {
    appointments.push_back(appointment);
}

void Patient::displayAppointments() const {
    // Display appointments for the patient
    for (const auto& appointment : appointments) {
        cout << "Appointment Time: " << appointment.getAppointmentTime() << endl;
        cout << "Medical Staff: " << appointment.getMedicalStaff()->getName() << endl;
        cout << "Procedures: " << appointment.getProcedures() << endl;
        cout << endl;
    }
}
Patient* Patient::searchById(int id, const list<unique_ptr<Patient>>& patientList) {
    for (const auto& patient : patientList) {
        if (patient->getId() == id) {
            return patient.get();
        }
    }
    return nullptr; // Patient with the specified ID not found
}
