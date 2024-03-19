#include "exceptionsVF.h"

using namespace std;

void BaseException::reportError(const string& errorMessage) {
    cerr << "Error! Invalid Argument, reason: " << errorMessage << endl;
}



    void AppointmentConflictException::appointmentConflicts(time_t requestedApp, const vector<time_t>& scheduledApps) {
        // BaseException exception;
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



void InvalidAgeException::invalidAges(int age) {
    if (age <= 0) {
        throw invalid_argument("Age must be a positive number.");
    }
    if (age > 150) {
        throw invalid_argument("Age outside normal lifespan.");
    }
}

void InvalidNameException::invalidNames(const string& Name) {
    for (char c : Name) {
        if (!isalpha(c)) {
            throw invalid_argument("Names must contain letters only.");
        }
    }
}
