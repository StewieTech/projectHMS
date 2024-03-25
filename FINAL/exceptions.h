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
    static bool invalidAges(int age);
};

class AppointmentConflictException {
public:
    static void appointmentConflicts(time_t requestedApp, const  vector<time_t>& scheduledApps);
};

class InvalidNameException {
public:
    static bool invalidNames(const std::string& Name);
};

class InvalidIDException {
public:
    static bool validateID(const std::string& id);
    static bool validateID(const std::string& id, const std::vector<std::string>& existingIDs);
};

class GenderException {
public:
    static bool validateGender(const  string& gender);
};

class PhoneNumberException {
public:
    static bool validatePhoneNumber(const  string& phoneNumber);
};

class FieldNotEmptyException {
public:
    static bool validateField(const  string& field);
};

class BoolMustBeSetException {
public:
    static bool validateBool(bool flag);
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
