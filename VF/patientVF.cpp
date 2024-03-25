#include "patientVF.h"
#include <iostream>
#include <ctime>

using namespace std;

// Definition of destructor for the Patient class
Patient::~Patient() {}

// Implementation of Patient class
Patient::Patient(int pID, string n, int a, char g, string add, string pN, string d, bool urg, bool ip, bool op, Appointment* is, Appointment* ns, int tebc)
    : name(n), age(a), gender(g), address(add), phoneNum(pN), patientID(pID), flag_urgency(urg), dept(d), is_inpatient(ip), is_outpatient(op), initialStep(is), nextStep(ns), totalExpenseByCents(tebc) {}

void Patient::displayInfo() const {
    cout << "Patient ID: " << patientID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNum << endl;
    cout << "Department: " << dept << endl;
    cout << "Urgency: " << (flag_urgency ? "Yes" : "No") << endl;
    cout << "Status: " << (is_inpatient ? "Inpatient" : (is_outpatient ? "Outpatient" : "Unassigned")) << endl;
    cout << "Total Expense: " << totalExpenseByCents << " cents" << endl;
}

// Implementation of InPatient class
InPatient::InPatient(int pID, string n, int a, char g, string add, string pN, string d, int rn, Appointment* is, Appointment* ns, int tebc, time_t it, time_t ot)
    : Patient(pID, n, a, g, add, pN, d, false, true, false, is, ns, tebc), roomNumber(rn), inTime(it), outTime(ot) {}

void InPatient::displayInfo() const {
    Patient::displayInfo();
    cout << "Room #: " << roomNumber << endl;
    if (is_inpatient) {
        cout << "Since: " << ctime(&inTime);
        cout << "To: " << ctime(&outTime);
    }
}

int InPatient::getRoomNo() const {
    return roomNumber;
}

time_t InPatient::getInTime() const {
    return inTime;
}

time_t InPatient::getOutTime() const {
    return outTime;
}

void InPatient::setRoomNo(int r) {
    roomNumber = r;
}

void InPatient::setInTime(time_t it) {
    inTime = it;
}

void InPatient::setOutTime(time_t ot) {
    outTime = ot;
}

void InPatient::exitCured() {
    time(&outTime);
    nextStep = nullptr;
    flag_urgency = false;
    is_inpatient = false;
}

// Implementation of OutPatient class
OutPatient::OutPatient(int pID, string n, int a, char g, string add, string pN, string d, Appointment* is, Appointment* ns, int tebc)
    : Patient(pID, n, a, g, add, pN, d, false, false, true, is, ns, tebc) {}

void OutPatient::displayInfo() const {
    Patient::displayInfo();
    if (is_outpatient && nextStep) {
        cout << "Scheduled: " << nextStep->getAppointmentTime() << endl;
    }
}

void OutPatient::exitCured() {
    nextStep = nullptr;
    flag_urgency = false;
    is_inpatient = false;
}

// Implementation of patientManager class
Patient* patientManager::addNewPatient() {
    int pID, a, rn, tebc;
    string n, add, pN, d;
    char g;
    bool urg, ip, op;

    // Get patient details from user
    cout << "Please enter patient ID (integer): ";
    cin >> pID;
    cout << "Please enter patient name (string): ";
    cin >> n;
    cout << "Please enter patient age (int): ";
    cin >> a;
    cout << "Please enter patient gender (M or F): ";
    cin >> g;
    cout << "Please enter patient address (string): ";
    cin >> add;
    cout << "Please enter patient phone number (string): ";
    cin >> pN;
    cout << "Please enter patient department (string): ";
    cin >> d;
    cout << "Patient has urgency? (Y/N): ";
    cin >> urg;
    cout << "Patient is a defined in-patient? (Y/N): ";
    cin >> ip;
    cout << "Patient is a defined out-patient? (Y/N): ";
    cin >> op;

    if (ip) {
        cout << "Please input scheduled room number (integer): ";
        cin >> rn;
    }

    cout << "Please input total expense by cents: ";
    cin >> tebc;

    // Create a new patient object based on user input
    if (ip) {
        // In-patient
        time_t it, ot;
        cout << "Please input in time. Is the year 2024? (Y/N): ";
        cin >> it;
        cout << "Please input out time. Is the year 2024? (Y/N): ";
        cin >> ot;
        return new InPatient(pID, n, a, g, add, pN, d, rn, nullptr, nullptr, tebc, it, ot);
    }
    else if (op) {
        // Out-patient
        return new OutPatient(pID, n, a, g, add, pN, d, nullptr, nullptr, tebc);
    }
    else {
        // Unassigned
        return new Patient(pID, n, a, g, add, pN, d, urg, false, false, nullptr, nullptr, tebc);
    }
}
