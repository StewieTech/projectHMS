#ifndef APPOINTMENTVF_H
#define APPOINTMENTVF_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "medicalStaffVF.h"

using namespace std;

// Forward declarations to avoid circular dependencies
class Patient;
class MedicalStaff;
class Procedure;


class Appointment {
    private:
        Patient* patient; 
        MedicalStaff* medicalStaff;
        time_t appointmentTime;
        string procedures;

    public:
        Appointment(Patient* patInput,  MedicalStaff* mInput, time_t atInput, const string& prInput);

        ~Appointment();

        time_t getAppointmentTime() const;
        void displayInfoUI(const list<unique_ptr<Patient>>& patientList) const;
        MedicalStaff* getMedicalStaff() const;
        string getProcedures() const;
        void setAppointmentTime(time_t newAppointmentTime);
        void setPatient(Patient* patient);
        void setMedicalStaff(MedicalStaff* staff);
        void setProcedures(const string& procedures);
        int getPatientID() const;
};


// Additional functions for appointment scheduling
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment);
void appointmentCancel(list<Appointment>& appointments, const Appointment& appointment);
void displayMenu();

#endif // APPOINTMENTVF_H 