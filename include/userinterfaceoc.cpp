#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include "patient.h"
#include "appointment.h"
#include "exceptions.h"
#include "exceptionsError.h"
#include "medicalStaff.h"
#include "procedure.h"

using namespace std;

// Function definitions related to appointments
void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment) {
    list<string> scheduledAppointments;
    for (const auto& apt : appointments) {
        scheduledAppointments.push_back(apt.getAppointmentTime());
    }

    if (find(scheduledAppointments.begin(), scheduledAppointments.end(), appointment.getAppointmentTime()) != scheduledAppointments.end()) {
        throw AppointmentConflictException();
    }

    appointments.push_back(appointment);
}

void appointmentCancel(list<Appointment>& appointments, const string& appointmentTime) {
    auto iter = find_if(appointments.begin(), appointments.end(), [appointmentTime](const Appointment& apt) {
        return apt.getAppointmentTime() == appointmentTime;
        });

    if (iter != appointments.end()) {
        appointments.erase(iter);
    }
}

void displayMenu() {
    cout << "HMS Menu Options" << endl;
    cout << "1. Schedule New Patient Appointment" << endl;
    cout << "2. Cancel Appointment" << endl;
    cout << "3. Manage Staff" << endl;
    cout << "4. Find Existing Patient By ID" << endl;
    cout << "5. Referral for Doctor" << endl;
    cout << "0. Exit Menu" << endl;
    cout << "Enter Your Choice" << endl;
}

void userInput(list<Appointment>& appointments, vector<Patient*>& patients, vector<MedicalStaff*>& staffMembers) {
    int choice;
    string appointmentTime;

    do {
        cin >> choice;

        switch (choice) {
        case 1:
            // Schedule Appointment
            cout << "Enter the name of the patient: ";
            cin.ignore();
            string name;
            getline(cin, name);

            cout << "Enter Patient ID" << endl;
            int patientID;
            cin >> patientID;

            cout << "Enter the name of the medical staff: ";
            string medicalStaff;
            cin.ignore();
            getline(cin, medicalStaff);

            cout << "Enter the Time of the Appointment: ";
            getline(cin, appointmentTime);

            cout << "Enter the procedure: ";
            string procedures;
            getline(cin, procedures);

            try {
                // Validate inputs and schedule appointment
                InvalidNameException nameException;
                nameException.invalidNames(name);

                InvalidNameException staffException;
                staffException.invalidNames(medicalStaff);

                AppointmentConflictException appointmentException;
                appointmentException.appointmentConflicts(appointments, appointmentTime);

                Patient* patientPtr = findPatientByName(name, patients);
                MedicalStaff* staffPtr = findMedicalStaff(medicalStaff, staffMembers);

                if (patientPtr == nullptr) {
                    throw invalid_argument("patient not found");
                }
                if (staffPtr == nullptr) {
                    throw invalid_argument("medical staff not found.");
                }

                appointmentSchedule(appointments, Appointment(patientPtr, staffPtr, appointmentTime, procedures));
                cout << "Your appointment has been scheduled!" << endl;
            }
            catch (const invalid_argument& e) {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 2:
            // Cancel Appointment
            cout << "List of booked appointments:" << endl;
            for (const auto& appointment : appointments) {
                cout << "Appointment Time: " << appointment.getAppointmentTime() << endl;
            }

            cout << "Enter the appointment time to cancel: ";
            cin.ignore();
            getline(cin, appointmentTime);

            appointmentCancel(appointments, appointmentTime);
            cout << "Appointment canceled successfully!" << endl;
            break;
        }
    } while (choice != 0);
}

int main() {
    list<Appointment> appointments;
    vector<Patient*> patients;
    vector<MedicalStaff*> staffMembers;

    displayMenu();
    userInput(appointments, patients, staffMembers);
    return 0;
}
