#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>

using namespace std;

class BaseException {
public:
    static void reportError(const 
        string& errorMessage);
};

class InvalidAgeException {
public:
    static void invalidAges(int age);
};

class AppointmentConflictException {
public:
    static void appointmentConflicts(time_t requestedApp, const  vector<time_t>& scheduledApps);
};

class InvalidNameException {
public:
    static void invalidNames(const  string& Name);
};

class InvalidIDException {
public:
    static void validateID(const  string& id);
    static void validateID(const  string& id, const  vector< string>& existingIDs);
};

class GenderException {
public:
    static void validateGender(const  string& gender);
};

class PhoneNumberException {
public:
    static void validatePhoneNumber(const  string& phoneNumber);
};

class FieldNotEmptyException {
public:
    static void validateField(const  string& field, const  string& fieldName);
};

class BoolMustBeSetException {
public:
    static void validateBool(bool flag, const  string& flagName);
};

class InvalidAppointmentTimeFormat : public invalid_argument {
public:
    InvalidAppointmentTimeFormat(const string& msg)
        : invalid_argument(msg) {}
};

bool isValidAppointmentTimeFormat(const string& time); 


void confirmationException(const  string& errorMessage, bool& confirmed);
void confirmationException(const  string& errorMessage, bool& confirmed, const  string& lastInput);

#endif // EXCEPTIONS_H
