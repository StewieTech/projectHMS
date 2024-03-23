#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include "Appointment.h"
#include "exceptionsVF.h"
#include "MedicalStaffVF.h"
#include "Patient.h"
#include "procedure.h"


using namespace std;



// Appointment Scheduling (Errol):
//    - Implement a class called "Appointment" to represent an appointment. 
// It should store the patient information, the medical staff assigned, the appointment time, and any necessary procedures.
//    - Utilize STL containers to handle appointment scheduling, track appointment conflicts, and manage appointment cancellations or rescheduling.


// class AppointmentConflictException : public exception {
//     public:
//      const char* what() const noexcept override {
//         return "There's already an appointment for this time";
//      }
// };




Patient* findPatientByName(const string& name, const vector<Patient*>& patients) {
    for (auto& p : patients) {
        if(p->getName() == name) return p;
       
    }
    return nullptr; // turn this to an exception maybe ?
};
// Patient* findPatientByName(const string& name, const vector<Patient*>& patients) {
//     for (auto& p : patients) {
//         if(p->getName() == name) return p;
       
//     }
//     return nullptr; // turn this to an exception maybe ?
// };

MedicalStaff* findMedicalStaff(const string& specialization, const vector<MedicalStaff*>& staffMembers ) {
    for (auto& staff : staffMembers) {
        if (staff->getSpecialization() == specialization && staff -> isAvailable()) return staff;
    }

};

// Appointment Scheduling
        Appointment::Appointment(Patient* patInput, MedicalStaff* mInput, const string& atInput, const string& prInput) : patient(patInput), medicalStaff(mInput), appointmentTime(atInput), procedures(prInput) {}

    // Appointment.h ?
    string Appointment::getAppointmentTime() const {
        return appointmentTime;
    };
        
        void Appointment::displayMenu() const {
            cout << "Patient: " << patient << endl;
            cout << "Medical Staff: " << medicalStaff << endl;
            cout << "Appointment Time: " << appointmentTime << endl;
            cout << "Procedures: " << procedures << endl;
        };

void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment) {
    list<string> scheduledAppointments;
    for (const auto& appointment : appointments) {
        scheduledAppointments.push_back(appointment.getAppointmentTime());
    }

    if (find(scheduledAppointments.begin(), scheduledAppointments.end(), appointment.getAppointmentTime()) != scheduledAppointments.end()) {
        throw AppointmentConflictException();
    }

    appointments.push_back(appointment);
};

void appointmentCancel(list<Appointment>& appointments, const string& appointmentTime) {
    auto iter = find_if(appointments.begin(), appointments.end(), [appointmentTime](const Appointment& appointment) {
        return appointment.getAppointmentTime() == appointmentTime;
    });

    if (iter != appointments.end()) {
        appointments.erase(iter);
    }
};



// User Interface
/* 

User Interface (Errol):
   - Implement a user interface to interact with the Hospital Management System.
   - Allow users to add patients, schedule appointments, manage medical staff, handle exceptions gracefully, and display relevant information.
   - Provide appropriate menus, prompts, and error messages to enhance usability.

*/


#include <iostream>
using namespace std;


void displayMenu() {
    cout << "HMS Menu Options" << endl;
    cout << "1. Schedule New Patient Appointment" << endl; 
    cout << "2. Cancel Appointment" << endl; 
    cout << "3. Manage Staff" << endl; 
    cout << "4. Find Existing Patient By ID" << endl; 
    cout << "5. Referral for Doctor" << endl; // searches for a Doctor // New Patient
    cout << "0. Exit Menu" << endl; 
    cout << "Enter Your Choice" << endl;

};

// void userInput(::vector<Patient*>& patients, list<Appointment>& appointments)
void userInput(list<Appointment>& appointments, vector<Patient*>& patients, vector<MedicalStaff*>& staffMembers)
{ 
    int choice;
    int patientID;
    list<int> patientIDs;
    string name;
    string medicalStaff;
    string appointmentTime;
    string procedures;
    string patientMatched; // FINISH FUNCTION
    bool isPatientMatched = false;

    do {
        cin >> choice;

        switch (choice) {
            case 1:
            // Schedule Appointment
            cout<< "Enter the name of the patient: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Patient ID" << endl;
            cin.ignore();
            cin >> patientID ;

            // Add patientID to a list of patientIDs
            patientIDs.push_back(patientID);

            // Search for patientID in the list of patientIDs
            isPatientMatched = false; 
            for (const auto& id : patientIDs) {
                if (id == patientID) {
                    isPatientMatched = true;
                    break;
                };
            };

            // Set patientMatched based on search result
            if (isPatientMatched) {
                patientMatched = nullptr;
            } else {
                patientMatched = "create patient search function";
            };
            if (!patientMatched.empty()) { 

                cout << "Enter the name of the mediacal staff: " ; 
                
                getline(cin, medicalStaff);

                cout << "Enter the Time of the Appointment: ";
                getline(cin, appointmentTime);

                cout << "Enter the procedure: ";
                getline(cin, procedures);
            
            try {
                InvalidNameException nameException;
                nameException.invalidNames(patientMatched);

                InvalidNameException staffException;
                staffException.invalidNames(medicalStaff);

                AppointmentConflictException appointmentException;
                list<string> scheduledAppointments;
                for (const auto& appointment : appointments) {
                    scheduledAppointments.push_back(appointment.getAppointmentTime());
                };

                if (find(scheduledAppointments.begin(), scheduledAppointments.end(), appointmentTime) != scheduledAppointments.end()) {
                    throw AppointmentConflictException();
                };

                Patient* patientPtr = findPatientByName(name, patients) ;
                MedicalStaff* staffPtr = findMedicalStaff(medicalStaff, staffMembers);

                if (patientPtr == nullptr) {
                    throw invalid_argument("patient not found");
                };
                if (staffPtr == nullptr) {
                    throw invalid_argument("medical staff not found.");
                };

                appointmentSchedule(appointments, Appointment(patientPtr, staffPtr, appointmentTime, procedures));
                cout << "Your appointment has been scheduled!" << endl;
            } catch (const std::invalid_argument& e) {
                cout << "Exception: " << e.what() << endl;
            };
        };
        break;
        

            case 2:
                // Cancel Appointment
                cout << "List of booked appointments:" << endl;
                for (const auto& appointment : appointments) {
                    cout << "Appointment Time: " << appointment.getAppointmentTime() << endl;
                    // Display other relevant appointment information
                };

                cout << "Enter the appointment time to cancel: ";
                cin.ignore();
                getline(cin, appointmentTime);

                appointmentCancel(appointments, appointmentTime);
                cout << "Appointment canceled successfully!" << endl;

                // break;
        }
    } while (choice != 0);
};



int main() {
    list<Appointment> appointments;
    vector<Patient*> patients;
    vector<MedicalStaff*> staffMembers;

    displayMenu();
    userInput(appointments, patients, staffMembers);
    return 0;;
};

