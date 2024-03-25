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
    string patient;
    string patientID;
    MedicalStaff* medicalStaff;
    string appointmentTime;
    string procedures;
    bool canceled; // Flag to indicate whether the appointment is canceled
    int appointmentID;

public:
    Appointment(const string& patInput, int inputID, MedicalStaff* mInput, const string& atInput, const string& prInput);
    ~Appointment();

    string getPatientName() const;
    string getAppointmentTime() const;
    int getAppointmentID() const;
    bool isCanceled() const;
    MedicalStaff* getMedicalStaff() const;
    string getProcedures() const;

    void setAppointmentTime(const string& appointmentTime);
    void setPatientID(const string& patientID);
    void setPatientName(const string& patientName);
    void setMedicalStaff(MedicalStaff* staff);
    void setProcedures(const string& procedures);
    void cancelAppointment();
};

void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment);
void cancelAppointment(list<Appointment>& appointments, const string& appointmentID);
void appointmentCancel(list<Appointment>& appointments, const Appointment& appointment);

#endif // APPOINTMENT_H
