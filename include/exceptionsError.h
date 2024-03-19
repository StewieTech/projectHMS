#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <ctime>
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

// Base class for exception handling
class BaseException {
public:
    // Common error reporting functionality
    // void reportError(const std::string& errorMessage) {
    //     std::cerr << "Error! Invalid Argument, reason: " << errorMessage << std::endl;
    // }
    void reportError(const string& errorMessage) {
    cerr << "Error! Invalid Argument, reason: " << errorMessage << endl;
        
    }
};

// Exception handling for invalid age
class InvalidAgeException : public BaseException {
public:
    void invalidAges(int age) {
        try {
            if (age <= 0) {
                throw invalid_argument("Age must be a positive number.");
            }
            if (age > 150) {
                throw invalid_argument("Age outside normal lifespan.");
            }
        }
        catch (const invalid_argument& e) {
            reportError(e.what());
        }
    }
};

// Exception handling for appointment conflict
class AppointmentConflictException : public BaseException {
public:
    void appointmentConflicts(time_t requestedApp, const vector<time_t>& scheduledApps) {
        try {
            for (const auto& scheduledApp : scheduledApps) {
                if (scheduledApp == requestedApp) {
                    throw invalid_argument("Appointment already taken.");
                }
            }
            time_t currentTime = time(nullptr);
            if (requestedApp > currentTime) {
                throw invalid_argument("Requested appointment already passed.");
            }
        }
        catch (const invalid_argument& e) {
            reportError(e.what());
        }
    }
};

// Exception handling for invalid name
class InvalidNameException : public BaseException {
public:
    void invalidNames(const string& Name) {
        try {
            for (char c : Name) {
                if (!isalpha(c)) {
                    throw invalid_argument("Names must contain letters only.");
                }
            }
        }
        catch (const invalid_argument& e) {
            reportError(e.what());
        }
    }
};

#endif // EXCEPTIONS_H
