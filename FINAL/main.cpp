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

// Menu display
void displayMenu() {
    cout << "Hospital Management System Menu:" << endl;
    cout << "1. Add patient" << endl;
    cout << "2. Search patient" << endl;
    cout << "3. Display all patients" << endl;
    cout << "4. Schedule appointment" << endl;
    cout << "5. Reschedule appointment" << endl;
    cout << "6. Cancel appointment" << endl;
    cout << "7. Display booked appointments" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}
// bool function to check if patient already exists
bool isPatientIDUnique(int patientID, const list<unique_ptr<Patient>>& patientList) {
    for (const auto& patient : patientList) {
        if (patient->getId() == patientID) {
            return false; // return false already exists
        }
    }
    return true; // true if unique
}

void userInput(list<Appointment>& appointments, list<unique_ptr<Patient>>& patientList) {
    char choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // clear input

        switch (choice) {
            case '1': // Add patient switch case for first option
            {
                // variables to set at the end
                string id, name, age, gender, address, phoneNumber, urgency, department, inPatient, outPatient;
                int ageInt;
                int patientID;

        bool validIDEntered = false;
        while (!validIDEntered) {
        // get input for patient ID
            try {
                cout << "Enter patient's ID (6 digits): ";
                getline(cin, id);
                validIDEntered = InvalidIDException::validateID(id);
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // get name 
        bool validNameEntered = false;
        while (!validNameEntered) {
            try {
                cout << "Enter patient's name: ";
                getline(cin, name);
                validNameEntered = InvalidNameException::invalidNames(name);
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // get age
        bool validAgeEntered = false;
        while (!validAgeEntered) {
            try {
                cout << "Enter patient's age: ";
                getline(cin, age);
                ageInt = stoi(age); // convert age input to integer for exception handling
                validAgeEntered = InvalidAgeException::invalidAges(ageInt);
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // grab single character gender (M,F,O)
        bool validGenderEntered = false;
        while (!validGenderEntered) {
            try {
                cout << "Enter patient's gender (M/F/O): ";
                getline(cin, gender);
                validGenderEntered = GenderException::validateGender(gender);
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // get patients address
        bool validAddressEntered = false;
        while (!validAddressEntered) {
            try {
                cout << "Enter patient's address: ";
                getline(cin, address);
                validAddressEntered = FieldNotEmptyException::validateField(address);
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // get phone number
        bool validPhoneNumEntered = false;
        while (!validPhoneNumEntered) {
            try {
                cout << "Enter patient's phone number: ";
                getline(cin, phoneNumber);
                validPhoneNumEntered = PhoneNumberException::validatePhoneNumber(phoneNumber);
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // set urgency
        bool validUrgencyEntered = false;
        while (!validUrgencyEntered) {
            try {
                cout << "Enter 1 for urgent, otherwise 0: ";
                string input;
                getline(cin, input);
                int urgencyValue = stoi(input); //convert to an int for bool exception
                if (urgencyValue != 0 && urgencyValue != 1) {
                    throw invalid_argument("Invalid input. Please enter either 1 for urgent or 0 for not urgent.");
                }
                validUrgencyEntered = true;
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // Set department patient will be staying
        bool validDepartmentEntered = false;
        while (!validDepartmentEntered) {
            try {
                cout << "Enter patient's department: ";
                getline(cin, department);
                validDepartmentEntered = FieldNotEmptyException::validateField(department); // check for non empty field
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // set if patient is inpatient
        bool validInPatientEntered = false;
        while (!validInPatientEntered) {
            try {
                cout << "Enter 1 for inpatient, otherwise 0: ";
                string input;
                getline(cin, input);
                int inpatientValue = stoi(input); // convert to int for bool exception
                if (inpatientValue != 0 && inpatientValue != 1) {
                    throw invalid_argument("Invalid input. Please enter either 1 or 0.");
                }
                validInPatientEntered = true;
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // set if patient is out patient
        bool validOutPatientEntered = false;
        while (!validOutPatientEntered) {
            try {
                cout << "Enter 1 for Outpatient, otherwise 0: ";
                string input;
                getline(cin, input);
                int outpatientValue = stoi(input); // convert to int for bool exception
                if (outpatientValue != 0 && outpatientValue != 1) {
                    throw invalid_argument("Invalid input. Please enter either 1 or 0.");
                }
                validOutPatientEntered = true;
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // Create and add the patient to the list
        int newPatientID = 0;
        newPatientID = stoi(id); // convert id from string to int to work with object
        unique_ptr<Patient> newPatient = make_unique<Patient>(newPatientID, name, ageInt, gender[0], "", phoneNumber, "", false, false, false, nullptr, nullptr, 0);
        patientList.push_back(move(newPatient));
        cout << "Patient added successfully." << endl;

            }
            break;

        case '2': // Search patient
        {
    string patientID;
    bool validIDEntered = false;
    while (!validIDEntered) {
        try {
            cout << "Enter patient's ID: ";
            getline(cin, patientID);
            // Check if input is empty
            if (patientID.empty()) {
                cerr << "Error: Please enter a valid ID." << endl;
                continue; // Skip further processing
            }
            // Validating ID
            validIDEntered = InvalidIDException::validateID(patientID);
            if (!validIDEntered) {
                cerr << "Error: Invalid ID format. Please enter a valid ID." << endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    int id;
    try {
        id = stoi(patientID);
    } catch (const invalid_argument&) {
        cerr << "Invalid ID format. Please enter a valid integer ID." << endl;
        break;
    }

    // Search by ID
    auto patient = Patient::searchById(id, patientList);
    if (patient == nullptr) {
        cerr << "Patient with ID " << id << " not found." << endl;
    } else {
        // if found display their information
        cout << "Patient found:" << endl;
        patient->displayInfo();
    }
    break;
}
        case '3': // Display all patients
            cout << "All Patients:" << endl;
            for (const auto& patient : patientList) {
                patient->displayInfo();
                cout << endl;
            }
            break;
        case '4': // Schedule appointment
{
    try {
        // setting variables for id and a flag
        bool validIDEntered = false;
        string patientID;
        while (!validIDEntered) {
            try {
                cout << "Enter the patient's ID: ";
                getline(cin, patientID);
                validIDEntered = InvalidIDException::validateID(patientID);
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // get ID for search
        auto patient = searchPatientById(stoi(patientID), patientList);
        if (patient == nullptr) {
            cerr << "Patient with ID " << patientID << " not found." << endl;
            break;
        }

        // Choose doctor/nurse 1 or 2
        string staffType;
        cout << "Select the type of medical staff (1. Doctor, 2. Nurse): ";
        cin >> staffType;
        if (staffType != "1" && staffType != "2") {
            cerr << "Invalid selection. Please choose 1 for Doctor or 2 for Nurse." << endl;
            break;
        }

        // deeper switch and display for specialties under doctor/nurse
string specialization;

if (staffType == "1") { // Doctor specialties display
    while (true) {
        cout << "Select the Doctor's specialty:\n";
        cout << "1. Emergency Physician\n";
        cout << "2. Pulmonologist\n";
        cout << "3. Gastroenterologist\n";
        cout << "Enter 1, 2, or 3: ";

        int specialtyChoice;
        cin >> specialtyChoice;

        // switch for doctor specialties 
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
                cerr << "Invalid choice. Please enter 1, 2, or 3." << endl;
                continue; //looping until valid option
        }

        // break loop when valid field
        if (!specialization.empty()) {
            break;
        }
    }
} else { // Nurse specialty display 
    while (true) {
        cout << "Select the Nurse's specialty:\n";
        cout << "1. Emergency Nurse\n";
        cout << "2. Respiratory Nurse\n";
        cout << "3. Gastrointestinal Nurse\n";
        cout << "Enter 1, 2, or 3: ";

        int specialtyChoice;
        cin >> specialtyChoice;

        // switch for selecting nurse specialty
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
                cerr << "Invalid choice. Please enter 1, 2, or 3." << endl;
                continue; // loop til valid
        }

        // break for when loop is valid
        if (!specialization.empty()) {
            break;
        }
    }
}
        // get appointment time
        string appointmentTime;
        cout << "Enter the appointment time (YYYY-MM-DD HH:MM): ";
        cin.ignore(); // Ignore newline character left in the buffer
        getline(cin, appointmentTime);

        // Validate time format
        if (!isValidAppointmentTimeFormat(appointmentTime)) {
            throw invalid_argument("Invalid appointment time format. Please use the format YYYY-MM-DD HH:MM.");
        }

        // Create the medical staff object
        MedicalStaff* medicalStaff;
        if (staffType == "1") { 
            string name = "Dr. Smith";
            bool availability = true;
            int employeeID = 123;
            string licenseNumber = "Lic123456";

            medicalStaff = new Doctor(name, specialization, availability, employeeID, licenseNumber);
        } else {
            string name = "Nurse Joy";
            bool availability = true;
            int employeeID = 456;

            medicalStaff = new Nurse(name, specialization, availability, employeeID);
        }

        // Create the appointment
        Appointment newAppointment(patient->getName(), patient->getId(), medicalStaff, appointmentTime, "");

        // Schedule appointment
        appointmentSchedule(appointments, newAppointment);

        cout << "Appointment successfully scheduled" << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    break;
}

case '5': // Reschedule appointment case
    try {
        // get id
        cout << "Enter the patient's ID: ";
        string patientID;
        cin >> patientID;

        // check if id exists otherwise break
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

        // Get new appointment info
        string newTime;
        cout << "Enter the new date and time for the appointment (YYYY-MM-DD HH:MM): ";
        cin.ignore();
        getline(cin, newTime);

        // throw if appointment format isnt correct
        if (!isValidAppointmentTimeFormat(newTime)) {
            throw invalid_argument("Invalid appointment time format. Please use the format YYYY-MM-DD HH:MM.");
        }

        // call reschedule function
        Appointment::rescheduleAppointment(appointments, appointmentID, newTime);
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    break;


        case '6': // Cancel appointment
            try {
                // get id
                cout << "Enter the patient's ID: ";
                string patientID;
                cin >> patientID;

                // Search by ID
                auto patient = searchPatientById(stoi(patientID), patientList);
                if (patient == nullptr) {
                    cerr << "Patient with ID " << patientID << " not found." << endl;
                    break;
                }

                // output all appointments tied to that ID
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
        case '7': // display appointments
            cout << "Available Appointments:" << endl;
            displayAvailableAppointments(appointments);
            break;

        case '8': // Exit with a nice msg 
            cout << "Thanks for using our Hospital Management System :)" << endl;
            break;

        default:
            cout << choice << " Is an invalid input" << endl;
        }
    } while (choice != '8');
}

// Function: search a patient by ID
Patient* searchPatientById(int id, const list<unique_ptr<Patient>>& patientList) {
    for (const auto& patient : patientList) {
        if (patient->getId() == id) {
            return patient.get();
        }
    }
    return nullptr; 
}


// Function to display all available appointments
void displayAvailableAppointments(const list<Appointment>& appointments) {
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

//weird leftover overload scared to remove for code breaking
void displayBookedAppointments()
{
}

// Function to display booked appointments
void displayBookedAppointments(const list<Appointment>& appointments) {
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

// main
int main() {
    list<Appointment> appointments;
    list<unique_ptr<Patient>> patientList;
    userInput(appointments, patientList);
    return 0;
}
