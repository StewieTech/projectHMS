#include <iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
#include <map>

#include "medicalStaffVF.h"
#include "procedureVF.h"
#include "patientVF.h"
#include "appointmentVF.h"


using namespace std;


patientManager patManager;
list<unique_ptr<Patient>> patientList;


class AppointmentConflictException : public exception {
public:
    const char* what() const noexcept override {
        return "There's already an appointment for this time";
    }
};



void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment) {
    for (const auto& previousBookedAppointment : appointments) {
        if (previousBookedAppointment.getAppointmentTime() == appointment.getAppointmentTime()) {
            throw AppointmentConflictException();
        }
    }

    appointments.push_back(appointment);
}

void appointmentCancel(list<Appointment>& appointments, const string& appointmentTime) {
    auto iter = find_if(appointments.begin(), appointments.end(), [appointmentTime](const Appointment& appointment) {
        return appointment.getAppointmentTime() == appointmentTime;
        });

    if (iter != appointments.end()) {
        appointments.erase(iter);
    }
}




void displayMenu() {
    cout << "HMS Menu Options" << endl;
    cout << "1. Schedule New Patient Appointment" << endl;
    cout << "2. Cancel Appointment" << endl;
    cout << "3. Display All Available Appointments" << endl;
    cout << "4. Manage Staff WIP" << endl;
    cout << "5. Find Patient By ID" << endl;
    cout << "6. Choose Procedure for Patient WIP" << endl;
    cout << "0. Exit Menu" << endl;
    cout << "Enter Your Choice: ";
}

// void userInput(::vector<Patient*>& patients, list<Appointment>& appointments)
void userInput(list<Appointment>& appointments, list<unique_ptr<Patient>>& patientList, patientManager& patManager)


{
    char choice;
    int patientID;
    list<int> patientIDs;
    string patientName;
    MedicalStaff* medicalStaff;
    string appointmentTime;
    string procedures;
    string staffType;
    string procedureDescriptions;

    bool isPatientMatched = false;

    do {
        displayMenu();
        // cout << "Select from Menu: " << endl;

        cin >> choice;
        cin.ignore();


        switch (choice) {
        case '1':

            // Schedule Appointment
            cout << "Enter the name of the patient: ";
            cin.ignore();
            getline(cin, patientName);

            cout << "Enter Patient ID: ";
            cin >> patientID;
            



            // Search for patientID in the list of patientIDs
            isPatientMatched = false;

            for (const auto& id : patientIDs) {
                if (id == patientID) {
                    isPatientMatched = true;
                    cout << "Patient ID already exists" << endl;
                    break;
                };
            };

            // Add patientID to a list of patientIDs only if it doesn't exist in the list // exceptions.h
            if (!isPatientMatched) {
                patientIDs.push_back(patientID);
            }

            // string staffType;
            cout << "Enter which medical staff is needed: " << endl;
            cout << "1. Doctor " << endl;
            cout << "2. Nurse " << endl;
            cout << "Enter 1 or 2: ";
            cin.ignore();
            getline(cin, staffType);

            if (staffType == "1") {
                cout << "Select the Doctor's specialty:\n";
                cout << "1. Emergency Physician\n";
                cout << "2. Pulmonologist\n";
                cout << "3. Gastroenterologist\n";
                cout << "Enter 1, 2, or 3: ";

                int specialtyChoice;
                cin >> specialtyChoice;

                // Mapping user choice to the specialty string
                string specialization;
                switch (specialtyChoice) {
                case 1:
                    specialization = "Emergency Physician";
                    break;
                case 2:
                    specialization = "Pulmonologist";
                    break;
                case 3:
                    specialization = "Gastroenterologist";
                    break;
                default:
                    cout << "Invalid choice. Defaulting to Emergency Physician." << endl;
                    specialization = "Emergency Physician";
                }


                string name = "Dr. Smith";
                bool availability = true;
                int employeeID = 123;
                string licenseNumber = "Lic123456";

                medicalStaff = new Doctor(name, specialization, availability, employeeID, licenseNumber);

                auto procedures = initializeProcedureList()["Doctor"][specialization];
                cout << "Procedures for " << specialization << ":\n";
                for (const auto& proc : procedures) {
                    cout << "- " << proc.getName() << ": " << proc.getDescription() << endl;
                    procedureDescriptions += proc.getName() + ": " + proc.getDescription() + "\n";

                }
            }

            else if (staffType == "2") {
                cout << "Select the Nurse's specialty:\n";
                cout << "1. Emergency Nurse\n";
                cout << "2. Respiratory Nurse\n";
                cout << "3. Gastrointestinal Nurse\n";
                cout << "Enter 1, 2, or 3: ";

                int specialtyChoice;
                cin >> specialtyChoice;

                // Mapping user choice to the specialty string
                string specialization;
                switch (specialtyChoice) {
                case 1:
                    specialization = "Emergency Nurse";
                    break;
                case 2:
                    specialization = "Respiratory Nurse";
                    break;
                case 3:
                    specialization = "Gastrointestinal Nurse";
                    break;
                default:
                    cout << "Invalid choice. Defaulting to Emergency Nurse." << endl;
                    specialization = "Emergency Nurse";
                }

                // Example values for demonstration
                string name = "Nurse Joy"; // Ensure this is correctly set
                bool availability = true;
                int employeeID = 456;

                medicalStaff = new Nurse(name, specialization, availability, employeeID);
                // Assuming 'initializeProcedureList' and 'procedureList' are accessible here
                auto procedures = initializeProcedureList()["Nurse"][specialization];
                cout << "Procedures for " << specialization << ":\n";
                for (const auto& proc : procedures) {
                    cout << "- " << proc.getName() << ": " << proc.getDescription() << endl;
                    procedureDescriptions += proc.getName() + ": " + proc.getDescription() + "\n";

                }
            }
            else {
                cout << "Invalid Selection; Please choose 1 or 2 only " << endl << endl;
                displayMenu();

            }




            cout << "Enter the Time of the Appointment: ";
            cin.ignore();
            getline(cin, appointmentTime);




            try {
                appointmentSchedule(appointments, Appointment(patientName, patientID, medicalStaff, appointmentTime, procedureDescriptions));
                cout << "Your appointment has been scheduled !" << endl << endl;
            }
            catch (const AppointmentConflictException& e) {
                cout << "Exception: " << e.what() << endl;
            }


            break;

        case '2':


            cout << "Enter the ID of the Appointment you want to cancel:" << endl;
            for (const auto& appointment : appointments) {
                appointment.displayInfoUI();
                cout << endl;
            }

            cin >> patientID;
            for (auto iter = appointments.begin(); iter != appointments.end(); ) {
                if (iter->getPatientID() == patientID) {
                    cout << "Appointment has been deleted " << endl << endl;

                    iter = appointments.erase(iter);
                }
                else {
                    ++iter;
                }
            }





        case '3':


            cout << "List of Appointments:" << endl;
            for (const auto& appointment : appointments) {
                appointment.displayInfoUI();
                cout << endl;
            }
            break;

        case '5':
            cout << "Enter patient ID to search: ";
            cin >> patientID;

            for (const auto& appointment : appointments) {
                if (appointment.getPatientID() == patientID) {
                    cout << "List of Patients by ID: " << endl;
                    appointment.displayInfoUI();
                }
            }

            break;


        case '0':
            cout << "Thanks for using our Hospital Management System :)" << endl;
            break;

        default:
            cout << choice << " Is an invalid input" << endl;

        }



    } while (choice != '0');
};


int main() {
    list<Appointment> appointments;
    list<unique_ptr<Patient>> patientList;
    patientManager patManager;

    // displayMenu();
    userInput(appointments, patientList, patManager);
    return 0;
}