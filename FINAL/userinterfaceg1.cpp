#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <memory>
#include <algorithm>
#include <ctime>
#include "exceptions.h"
#include "medicalStaff.h"
#include "procedure.h"
#include "patient.h"
#include "appointment.h"

using namespace std;

// Function prototypes
void userInput(list<Appointment>& appointments, list<unique_ptr<Patient>>& patientList);
void displayMenu();
Patient* searchPatientById(int id, const list<unique_ptr<Patient>>& patientList);
bool isValidAppointmentTimeFormat(const string& time);
void displayAvailableAppointments(const list<Appointment>& appointments);
void displayBookedAppointments();

// Function definitions
void displayMenu() {
    cout << "Hospital Management System Menu:" << endl;
    cout << "1. Search patient" << endl;
    cout << "2. Add patient" << endl;
    cout << "3. Display all patients" << endl;
    cout << "4. Schedule appointment" << endl;
    cout << "5. Reschedule appointment" << endl;
    cout << "6. Cancel appointment" << endl;
    cout << "7. Display all available appointments" << endl;
    cout << "8. Display booked appointments" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

void userInput(list<Appointment>& appointments, list<unique_ptr<Patient>>& patientList) {
    char choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case '1': // Search patient
            // Implement search patient functionality
            break;
        case '2': // Add patient
            try {
                // Implement add patient functionality with input validation
                string name;
                cout << "Enter patient's name: ";
                getline(cin, name);
                InvalidNameException::invalidNames(name);

                string id;
                cout << "Enter patient's ID: ";
                getline(cin, id);
                // Implement your ID validation logic here

                string gender;
                cout << "Enter patient's gender (M/F/O): ";
                getline(cin, gender);
                GenderException::validateGender(gender);

                string phoneNumber;
                cout << "Enter patient's phone number: ";
                getline(cin, phoneNumber);
                PhoneNumberException::validatePhoneNumber(phoneNumber);

                // Create and add the patient to the list
                unique_ptr<Patient> newPatient = make_unique<Patient>(name, id, gender[0], "", phoneNumber, "", false, false, false, nullptr, nullptr, 0);
                patientList.push_back(move(newPatient));
                cout << "Patient added successfully." << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case '3': // Display all patients
            cout << "All Patients:" << endl;
            for (const auto& patient : patientList) {
                patient->displayInfo();
                cout << endl;
            }
            break;
        case '4': // Schedule appointment
            try {
                // Implement schedule appointment functionality with input validation
                string patientID;
                cout << "Enter the patient's ID: ";
                cin >> patientID;

                // Search for the patient by ID
                auto patient = searchPatientById(stoi(patientID), patientList);
                if (patient == nullptr) {
                    cerr << "Patient with ID " << patientID << " not found." << endl;
                    break;
                }

                // Choose medical staff type
                string staffType;
                cout << "Select the type of medical staff (1. Doctor, 2. Nurse): ";
                cin >> staffType;
                if (staffType != "1" && staffType != "2") {
                    cerr << "Invalid selection. Please choose 1 for Doctor or 2 for Nurse." << endl;
                    break;
                }

                // Prompt for doctor or nurse specialties based on user choice
                string specialization;
                if (staffType == "1") { // Doctor
                    cout << "Select the Doctor's specialty:\n";
                    cout << "1. Emergency Physician\n";
                    cout << "2. Pulmonologist\n";
                    cout << "3. Gastroenterologist\n";
                    cout << "Enter 1, 2, or 3: ";

                    int specialtyChoice;
                    cin >> specialtyChoice;

                    // Mapping user choice to the specialty string
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
                        cerr << "Invalid choice. Defaulting to Emergency Physician." << endl;
                        specialization = "Emergency Physician";
                    }
                }
                else { // Nurse
                    cout << "Select the Nurse's specialty:\n";
                    cout << "1. Emergency Nurse\n";
                    cout << "2. Respiratory Nurse\n";
                    cout << "3. Gastrointestinal Nurse\n";
                    cout << "Enter 1, 2, or 3: ";

                    int specialtyChoice;
                    cin >> specialtyChoice;

                    // Mapping user choice to the specialty string
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
                        cerr << "Invalid choice. Defaulting to Emergency Nurse." << endl;
                        specialization = "Emergency Nurse";
                    }
                }

                // Choose appointment time
                string appointmentTime;
                cout << "Enter the appointment time (YYYY-MM-DD HH:MM): ";
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, appointmentTime);

                // Validate appointment time format
                if (!isValidAppointmentTimeFormat(appointmentTime)) {
                    throw invalid_argument("Invalid appointment time format. Please use the format YYYY-MM-DD HH:MM.");
                }

                // Create the medical staff object
                MedicalStaff* medicalStaff;
                if (staffType == "1") { // Doctor
                    // Create Doctor object based on specialization
                    // Example values for demonstration
                    string name = "Dr. Smith";
                    bool availability = true;
                    int employeeID = 123;
                    string licenseNumber = "Lic123456";

                    medicalStaff = new Doctor(name, specialization, availability, employeeID, licenseNumber);
                }
                else { // Nurse
                    // Create Nurse object based on specialization
                    // Example values for demonstration
                    string name = "Nurse Joy"; // Ensure this is correctly set
                    bool availability = true;
                    int employeeID = 456;

                    medicalStaff = new Nurse(name, specialization, availability, employeeID);
                }

                // Create the appointment
                Appointment newAppointment(patient->getName(), patient->getId(), medicalStaff, appointmentTime, "");

                // Schedule the appointment
                appointmentSchedule(appointments, newAppointment);

                cout << "Appointment successfully scheduled" << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;

        case '5': // Reschedule appointment
            try {
                // Implement reschedule appointment functionality
                cout << "Enter the patient's ID: ";
                string patientID;
                cin >> patientID;

                // Search for the patient by ID
                auto patient = searchPatientById(stoi(patientID), patientList);
                if (patient == nullptr) {
                    cerr << "Patient with ID " << patientID << " not found." << endl;
                    break;
                }

                // Display the patient's appointments
                cout << "Patient's Appointments:" << endl;
                patient->displayAppointments();

                cout << "Enter the ID of the appointment to reschedule: ";
                string appointmentID;
                cin >> appointmentID;

                // Get the new date and time for the appointment
                string newTime;
                cout << "Enter the new date and time for the appointment (YYYY-MM-DD HH:MM): ";
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, newTime);

                // Validate appointment time format
                if (!isValidAppointmentTimeFormat(newTime)) {
                    throw invalid_argument("Invalid appointment time format. Please use the format YYYY-MM-DD HH:MM.");
                }

                // Reschedule the appointment
                appointment->setDateTime(newTime);
                cout << "Appointment successfully rescheduled." << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;

        case '6': // Cancel appointment
            try {
                // Implement cancel appointment functionality
                cout << "Enter the patient's ID: ";
                string patientID;
                cin >> patientID;

                // Search for the patient by ID
                auto patient = searchPatientById(stoi(patientID), patientList);
                if (patient == nullptr) {
                    cerr << "Patient with ID " << patientID << " not found." << endl;
                    break;
                }

                // Display the patient's appointments
                cout << "Patient's Appointments:" << endl;
                patient->displayAppointments();

                cout << "Enter the ID of the appointment to cancel: ";
                string appointmentID;
                cin >> appointmentID;

                // Cancel the appointment
                cancelAppointment(appointments, appointmentID);
                cout << "Appointment successfully canceled." << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case '7': // Display all available appointments
            // Implement display all available appointments functionality
            cout << "Available Appointments:" << endl;
            displayAvailableAppointments();
            break;

        case '8': // Display booked appointments
            // Implement display booked appointments functionality
            cout << "Booked Appointments:" << endl;
            displayBookedAppointments();
            break;

        case '9': // Exit
            cout << "Thanks for using our Hospital Management System :)" << endl;
            break;

        default:
            cout << choice << " Is an invalid input" << endl;
        }
    } while (choice != '9');
}

// Function to search a patient by ID
Patient* searchPatientById(int id, const list<unique_ptr<Patient>>& patientList) {
    for (const auto& patient : patientList) {
        if (patient->getId() == id) {
            return patient.get();
        }
    }
    return nullptr; // Patient with the specified ID not found
}

// Function to validate appointment time format
bool isValidAppointmentTimeFormat(const string& time) {

}

// Function to display all available appointments
void displayAvailableAppointments(const list<Appointment>& appointments) {
    // Implement the functionality to display available appointments
    // Iterate through the list of appointments and display those that are not canceled
    for (const auto& appointment : appointments) {
        if (!appointment.isCanceled()) {
            cout << "Patient: " << appointment.getPatientName() << endl;
            cout << "Appointment Time: " << appointment.getAppointmentTime() << endl;
            cout << "Medical Staff: " << appointment.getMedicalStaff()->getName() << endl;
            cout << "Procedures: " << appointment.getProcedures() << endl;
            cout << endl;
        }
    }
}

void displayBookedAppointments()
{
}

// Function to display booked appointments
void displayBookedAppointments(const list<Appointment>& appointments) {
    // Implement the functionality to display booked appointments
    // Iterate through the list of appointments and display those that are canceled
    for (const auto& appointment : appointments) {
        if (appointment.isCanceled()) {
            cout << "Patient: " << appointment.getPatientName() << endl;
            cout << "Appointment Time: " << appointment.getAppointmentTime() << endl;
            cout << "Medical Staff: " << appointment.getMedicalStaff()->getName() << endl;
            cout << "Procedures: " << appointment.getProcedures() << endl;
            cout << endl;
        }
    }
}

int main() {
    list<Appointment> appointments;
    list<unique_ptr<Patient>> patientList;
    userInput(appointments, patientList);
    return 0;
}