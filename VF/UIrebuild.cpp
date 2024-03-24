#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <memory>
#include <algorithm>
#include <map>
#include <iomanip>
#include <ctime>


#include "medicalStaffVF.h"
#include "procedureVF.h"
#include "patientVF.h"
#include "appointmentVF.h"


// g++ UIrebuild.cpp medicalStaffVF.cpp procedureVF.cpp 
// g++ UIrebuild.cpp medicalStaffVF.cpp procedureVF.cpp patientVF.cpp
using namespace std;

/*
Appointment Scheduling (Errol):
   - Implement a class called "Appointment" to represent an appointment. 
It should store the patient information, the medical staff assigned, the appointment time, and any necessary procedures.
   - Utilize STL containers to handle appointment scheduling, track appointment conflicts, and manage appointment cancellations or rescheduling.
*/

patientManager patManager;
list<unique_ptr<Patient>> patientList;


class AppointmentConflictException : public exception {
    public:
     const char* what() const noexcept override {
        return "There's already an appointment for this time";
     }
};


// Appointment Scheduling
/*
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
};
*/

void appointmentSchedule(list<Appointment>& appointments, const Appointment& appointment) {
    for (const auto& previousBookedAppointment : appointments) {
        if (previousBookedAppointment.getAppointmentTime() == appointment.getAppointmentTime()) {
            throw AppointmentConflictException();
        }
    }

    appointments.push_back(appointment);
}

void appointmentCancel(list<Appointment>& appointments, time_t appointmentTime) {
    auto iter = find_if(appointments.begin(), appointments.end(), [appointmentTime](const Appointment& appointment) {
        return appointment.getAppointmentTime() == appointmentTime;
    });

    if (iter != appointments.end()) {
        appointments.erase(iter);
    }
}



// User Interface
/* 

User Interface (Errol):
   - Implement a user interface to interact with the Hospital Management System.
   - Allow users to add patients, schedule appointments, manage medical staff, handle exceptions gracefully, and display relevant information.
   - Provide appropriate menus, prompts, and error messages to enhance usability.

*/

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
void userInput(list<Appointment>& appointments, list<unique_ptr<Patient>>& patientList, patientManager& patManager )


{ 
    char choice;
    int patientID;
    list<int> patientIDs;
    string patientName;
    MedicalStaff* medicalStaff;
    string appointmentDate;
    string appointmentHour;
    time_t appointmentTime;
    istringstream dateStream;
    istringstream hourStream;
   
    tm appointmentTm = {};
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
            cout<< "Enter the name of the patient: ";
            cin.ignore();
            getline(cin, patientName);

            cout << "Enter Patient ID: ";
            cin >> patientID ;
            // cin.ignore();
            // if ( !(patientID > 0) )  {
            //    cout << "Invalid input; Please enter a valid postive number only" << endl;
            //    cin.ignore();
            //    break ;
            // }



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
} else {
    cout << "Invalid Selection; Please choose 1 or 2 only " << endl << endl; 
    displayMenu();

}
          

  


            do {
                cout << "Enter the Date of the Appointment (YYYY-MM-DD):  ";
                cin.ignore();
                getline(cin, appointmentDate);

                dateStream.str(appointmentDate);
                dateStream >> get_time(&appointmentTm, "%Y-%m-%d");

                if (dateStream.fail()) {
                    cout << "Invalid input; Please enter a valid date in the format YYYY-MM-DD" << endl;
                }
                dateStream.clear(); // Clear the fail state for the next iteration
            } while (dateStream.fail());

   
            do {
                cout << "Enter the Hour of the Appointment (HH:MM) in 24 hour time: ";
                cin.ignore();
                getline(cin, appointmentHour);

                hourStream.str(appointmentHour);
                hourStream >> get_time(&appointmentTm, "%H:%M");

                if (hourStream.fail()) {
                    cout << "Invalid input; Please enter a valid hour in the format" << endl;
                }
                hourStream.clear(); 
            } while (hourStream.fail());

            appointmentTime = mktime(&appointmentTm);
           
            

            try {
                appointmentSchedule(appointments, Appointment(patientName, patientID, medicalStaff, appointmentTime, procedureDescriptions));
                cout << "Your appointment has been scheduled !" << endl << endl;
            } catch (const AppointmentConflictException& e) {
                cout << "Exception: " << e.what() << endl;
            }        
        
  
        break;

        case '2':

        // if no appointments to delete show no appointments to delete //exceptions.h

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
            } else {
                ++iter; 
            }
        }



            

        case '3' :

        // if there is no appointment cout no appointments to show // exception.h
        // we can also have a default amount of appointments to show // exception.h

            cout << "List of Appointments:" << endl;
            for (const auto& appointment : appointments) {
                appointment.displayInfoUI();
                cout << endl;
            }
    break;

    case '5' :
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
    locale::global(locale("C"));    
    list<Appointment> appointments;
    list<unique_ptr<Patient>> patientList;
    patientManager patManager;

    // displayMenu();
    userInput(appointments, patientList, patManager);
    return 0 ;
}
