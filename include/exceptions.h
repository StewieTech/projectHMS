#include <stdexcept>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>

// Base class for exception handling
class BaseException {
public:
    // Common error reporting functionality
    void reportError(const std::string& errorMessage) {
        std::cerr << "Error! Invalid Argument, reason: " << errorMessage << std::endl;
    }
};

// Exception handling for invalid age
class InvalidAgeException : public BaseException {
public:
    void invalidAges(int age) {
        try {
            if (age <= 0) {
                throw std::invalid_argument("Age must be a positive number.");
            }
            if (age > 150) {
                throw std::invalid_argument("Age outside normal lifespan.");
            }
        } catch (const std::invalid_argument& e) {
            reportError(e.what());
        }
    }
};

// Exception handling for appointment conflict
class AppointmentConflictException : public BaseException {
public:
    void appointmentConflicts(std::time_t requestedApp, const std::vector<std::time_t>& scheduledApps) {
        try {
            for (const auto& scheduledApp : scheduledApps) {
                if (scheduledApp == requestedApp) {
                    throw std::invalid_argument("Appointment already taken.");
                }
            }
            std::time_t currentTime = std::time(nullptr);
            if (requestedApp > currentTime) {
                throw std::invalid_argument("Requested appointment already passed.");
            }
        } catch (const std::invalid_argument& e) {
            reportError(e.what());
        }
    }
};

// Exception handling for invalid name
class InvalidNameException : public BaseException {
public:
    void invalidNames(const std::string& Name) {
        try {
            for (char c : Name) {
                if (!isalpha(c)) {
                    throw std::invalid_argument("Names must contain letters only.");
                }
            }
        } catch (const std::invalid_argument& e) {
            reportError(e.what());
        }
    }
};
