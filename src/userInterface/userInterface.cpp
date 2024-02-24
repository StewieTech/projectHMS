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
        string medicalStaff;
        string appointmentTime;
        string procedures;

    public:
        Appointment(string& patInput, const string& mInput, const string& atInput, const string& prInput) : patient(patInput), medicalStaff(mInput), appointmentTime(atInput), procedures(prInput) {}

    // Appointment.h ?
    string getAppointmentTime() const {
        return appointmentTime;
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
    cout << "1. Schedule Appointment" << endl; 
    cout << "2. Cancel Appointment" << endl; 
    cout << "3. Manage Staff" << endl; 
    cout << "4. Find Patient" << endl; 
    cout << "0. Exit Menu" << endl; 
    cout << "Enter Your Choice" << endl;

}

// void userInput(::vector<Patient*>& patients, list<Appointment>& appointments)
// void userInput(list<Appointment>& appointments)
// { 
//     int choice;
//     string name;


//     do {
//         cin >> choice;

//         switch (choice) {
//             case 1:
//             // Schedule Appointment
//             cout<< "Endter the name of the patient: ";

//         }
//     }
// }

int main() {
    displayMenu();
    return 0 ;
}