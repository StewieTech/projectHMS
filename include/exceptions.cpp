#include "exceptionsVF.h"

void BaseException::reportError(const std::string& errorMessage) {
    std::cerr << "Error! Invalid Argument, reason: " << errorMessage << std::endl;
}



    void AppointmentConflictException::appointmentConflicts(std::time_t requestedApp, const std::vector<std::time_t>& scheduledApps) {
        // BaseException exception;
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
        }
        catch (const std::invalid_argument& e) {
            reportError(e.what());
        }
    }



void InvalidAgeException::invalidAges(int age) {
    if (age <= 0) {
        throw std::invalid_argument("Age must be a positive number.");
    }
    if (age > 150) {
        throw std::invalid_argument("Age outside normal lifespan.");
    }
}

void InvalidNameException::invalidNames(const std::string& Name) {
    for (char c : Name) {
        if (!isalpha(c)) {
            throw std::invalid_argument("Names must contain letters only.");
        }
    }
}
