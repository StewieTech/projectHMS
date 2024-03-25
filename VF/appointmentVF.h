#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>

#include "medicalStaffVF.h"


using namespace std;

// Forward declarations to avoid circular dependencies
class Patient;
class MedicalStaff;
// time_t appointmentTime;

class Procedure;

class Appointment {
    
    private:
        string patient; // Will make a dynamic reference to the patient class from Question 1
        int patientID;
        MedicalStaff* medicalStaff;
        string appointmentTime;
        string procedures;

    public:
        Appointment(string& patInput, int& inputID, MedicalStaff* mInput, const string& atInput, const string& prInput) : patient(patInput), patientID(inputID), medicalStaff(mInput), appointmentTime(atInput), procedures(prInput) {}


    ~Appointment() {
        // delete medicalStaff;
    }
    // Appointment.h ?
    string getAppointmentTime() const {
        return appointmentTime;
    }

    int getPatientID() const {
        return patientID;
    }
        
        void displayInfoUI() const {
            cout << "Patient: " << patient << endl;
            cout << "Patient ID: " << patientID << endl;

           cout << "Medical Staff: " << medicalStaff->getName() << ", " 
            << medicalStaff->getSpecialization() << ", Availability: " 
            << (medicalStaff->getAvailability() ? "Available" : "Not Available") << ", Employee ID: " 
            << medicalStaff->getEmployeeID() << endl;

            cout << "Appointment Time: " << appointmentTime << endl;
            cout << "Procedures: " << procedures << endl;
        }


    // Accessors
    // string getAppointmentTime() const;
    // Patient* getPatient() const;
    MedicalStaff* getMedicalStaff() const;
    Procedure* getProcedure() const;
    string getProcedures() const; // Getter for procedures
    //  int getPatientID() const {}

    // Modifiers
    void setAppointmentTime(const string& appointmentTime);
    void setPatient(Patient* patient);
    void setMedicalStaff(MedicalStaff* staff);
    void setProcedure(Procedure* procedure);
    void setProcedures(const string& procedures); // Setter for procedures

    // Friend function declarations
    friend void setPatientAppointment(Patient* patient, Appointment* appointment);

    // Additional functions for appointment scheduling
   
};

// Additional functions for appointment scheduling
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment);
void appointmentCancel(list<Appointment>& appointments, const Appointment& appointment);
void displayMenu();
// void userInput(list<Appointment>& appointments, vector<Patient*>& patients, vector<MedicalStaff*>& staffMembers);

#endif // APPOINTMENT_H 
