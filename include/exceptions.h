#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

class BaseException {
public:
    // Common error reporting functionality
    void reportError(const string& errorMessage);
};

// Exception handling for invalid age
class InvalidAgeException : public BaseException {
public:
    void invalidAges(int age);
};

// Exception handling for appointment conflict
class AppointmentConflictException : public BaseException {
public:
    void appointmentConflicts(time_t requestedApp, const vector<time_t>& scheduledApps);
};

// Exception handling for invalid name
class InvalidNameException : public BaseException {
public:
    void invalidNames(const string& Name);
};

#endif // EXCEPTIONS_H