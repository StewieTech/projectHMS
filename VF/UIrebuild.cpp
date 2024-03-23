#include <iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>

using namespace std;

/*
Appointment Scheduling (Errol):
   - Implement a class called "Appointment" to represent an appointment. 
It should store the patient information, the medical staff assigned, the appointment time, and any necessary procedures.
   - Utilize STL containers to handle appointment scheduling, track appointment conflicts, and manage appointment cancellations or rescheduling.
*/

class AppointmentConflictException : public exception {
    public:
     const char* what() const noexcept override {
        return "There's already an appointment for this time";
     }
};


// Appointment Scheduling
class Appointment {
    private:
        string patient; // Will make a dynamic reference to the patient class from Question 1
        int patientID;
        string medicalStaff;
        string appointmentTime;
        string procedures;

    public:
        Appointment(string& patInput, int& inputID, const string& mInput, const string& atInput, const string& prInput) : patient(patInput), patientID(inputID), medicalStaff(mInput), appointmentTime(atInput), procedures(prInput) {}

    // Appointment.h ?
    string getAppointmentTime() const {
        return appointmentTime;
    }

    int getPatientID() const {
        return patientID;
    }
        
        void displayMenu() const {
            cout << "Patient: " << patient << endl;
            cout << "Medical Staff: " << medicalStaff << endl;
            cout << "Appointment Time: " << appointmentTime << endl;
            cout << "Procedures: " << procedures << endl;
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
    cout << "4. Manage Staff" << endl; 
    cout << "5. Find Patient By ID" << endl; 
    cout << "0. Exit Menu" << endl; 
    cout << "Enter Your Choice" << endl;

}

// void userInput(::vector<Patient*>& patients, list<Appointment>& appointments)
void userInput(list<Appointment>& appointments)


{ 
    int choice;
    int patientID;
    list<int> patientIDs;
    string patientName;
    string medicalStaff;
    string appointmentTime;
    string procedures;
    
    bool isPatientMatched = false;

    do {

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        }
        displayMenu();
        // cout << "Select from Menu: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
            // Schedule Appointment
            cout<< "Enter the name of the patient: ";
            cin.ignore();
            getline(cin, patientName);

            cout << "Enter Patient ID: ";
            cin >> patientID ;

            

            // Search for patientID in the list of patientIDs
            isPatientMatched = false; 
            for (const auto& id : patientIDs) {
                if (id == patientID) {
                    isPatientMatched = true;
                    cout << "Patient ID already exists" << endl;
                    break;
                };
            };

            // Add patientID to a list of patientIDs only if it doesn't exist in the list
            if (!isPatientMatched) {
                patientIDs.push_back(patientID);
            }

            
                cout << "Enter the name of the mediacal staff: " ; 
                cin.ignore();
                getline(cin, medicalStaff);

                cout << "Enter the Time of the Appointment: ";
                cin.ignore();
                getline(cin, appointmentTime);

                cout << "Enter the procedure: ";
                cin.ignore();
                getline(cin, procedures);
            

            try {
                appointmentSchedule(appointments, Appointment(patientName, patientID, medicalStaff,appointmentTime, procedures));
                cout << "Your appointment has been scheduled !" << endl << endl;
            } catch (const AppointmentConflictException& e) {
                cout << "Exception: " << e.what() << endl;
            }        

  
        break;
            

        case 3 :

            cout << "List of Appointments:" << endl;
            for (const auto& appointment : appointments) {
                appointment.displayMenu();
                cout << endl;
            }
    break;

    case 5 :
        cout << "Enter patient ID to search: ";
        cin >> patientID;

        for (const auto& appointment : appointments) {
            if (appointment.getPatientID() == patientID) {
        cout << "List of Patients by ID: " << endl;
                appointment.displayMenu();
            }
        }

        break;



        case 0:
            cout << "Thanks for using our Hospital Management System :)" << endl;
        break;
        
        default: 
            cout << choice << " Is an invalid input" << endl;

        }


    } while (choice != 0);
}


int main() {
    list<Appointment> appointments;

    // displayMenu();
    userInput(appointments);
    return 0 ;
}