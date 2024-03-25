#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "medicalstaff.h"
#include "procedure.h"

using namespace std;

class Patient; // Forward declaration to avoid circular dependencies

class Appointment {
private:
    string patient; //name of patient
    string patientID; //patient ID
    MedicalStaff* medicalStaff; //pointer to medical staff assigned to appointment
    string appointmentTime; //time of appointment
    string procedures; //procedures associated with appointment
    bool canceled; // Flag for if appointment is cancelled
    int appointmentID; //appointment ID

public:
//Constructor
    Appointment(const string& patInput, int inputID, MedicalStaff* mInput, const string& atInput, const string& prInput);
//Destructor    
~Appointment();

 //Getters
    string getPatientName() const;
    string getAppointmentTime() const;
    int getAppointmentID() const;
    bool isCanceled() const;
    MedicalStaff* getMedicalStaff() const;
    string getProcedures() const;

//Setters
    void setAppointmentTime(const string& appointmentTime);
    void setPatientID(const string& patientID);
    void setPatientName(const string& patientName);
    void setMedicalStaff(MedicalStaff* staff);
    void setProcedures(const string& procedures);
    void cancelAppointment();

//Static function to reschedule appointment
    static void rescheduleAppointment(list<Appointment>& appointments, const string& appointmentID, const string& newTime);
};

//function to schedule appointment
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment);

//Function to cancel appointment
void cancelAppointment(list<Appointment>& appointments, const string& appointmentID);

//function to cancel appointment (overload)
void appointmentCancel(list<Appointment>& appointments, const Appointment& appointment);

#endif // APPOINTMENT_H
