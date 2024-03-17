#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <ctime>

class BaseException {
public:
    void reportError(const std::string& errorMessage);
};

class AppointmentConflictException : public BaseException {
public:
    void appointmentConflicts(std::time_t requestedApp, const std::vector<std::time_t>& scheduledApps);
};

class InvalidAgeException : public BaseException {
public:
    void invalidAges(int age);
};

class InvalidNameException : public BaseException {
public:
    void invalidNames(const std::string& Name);
};

#endif // EXCEPTIONS_H
