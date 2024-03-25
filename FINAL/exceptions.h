#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>

using namespace std;

// Base exception class for reporting errors
class BaseException {
public:
    static void reportError(const
        string& errorMessage); //function to report error messages
};
//Exception class for invalid age
class InvalidAgeException {
public:
    static bool invalidAges(int age);
};

//Exception class for appointment conflicts
class AppointmentConflictException {
public:
    static void appointmentConflicts(time_t requestedApp, const  vector<time_t>& scheduledApps);
};

//Exception class for invalid name inputs
class InvalidNameException {
public:
    static bool invalidNames(const string& Name);
};

//Exception class for invalid ID inputs
class InvalidIDException {
public:
    static bool validateID(const string& id); //function to validate ID
    static bool validateID(const string& id, const vector<string>& existingIDs); //function to validate ID against existing IDs
};

//Exception class for invalid gender inputs
class GenderException {
public:
    static bool validateGender(const  string& gender); //Function to validate gender input
};

//Exception class for invalid phone number inputs
class PhoneNumberException {
public:
    static bool validatePhoneNumber(const  string& phoneNumber); //function to validate phone number input
};

//Exception class for non-empty fields
class FieldNotEmptyException {
public:
    static bool validateField(const  string& field); //function to validate field has content
};

//Exception class for unset boolean flags
class BoolMustBeSetException {
public:
    static bool validateBool(bool flag); //function for boolean flag
};

//Custom exception class for invalid appointment time format
class InvalidAppointmentTimeFormat : public invalid_argument {
public:
    InvalidAppointmentTimeFormat(const string& msg)
        : invalid_argument(msg) {} //Constructor
};

//Function to validate time format
bool isValidAppointmentTimeFormat(const string& time);

//Function to handle confirmation exceptions
void confirmationException(const  string& errorMessage, bool& confirmed);
void confirmationException(const  string& errorMessage, bool& confirmed, const  string& lastInput);

#endif // EXCEPTIONS_H
