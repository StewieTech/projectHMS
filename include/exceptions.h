#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>

class BaseException {
public:
    static void reportError(const std::string& errorMessage);
};

class InvalidAgeException {
public:
    static void invalidAges(int age);
};

class AppointmentConflictException {
public:
    static void appointmentConflicts(time_t requestedApp, const std::vector<time_t>& scheduledApps);
};

class InvalidNameException {
public:
    static void invalidNames(const std::string& Name);
};

class InvalidIDException {
public:
    static void validateID(const std::string& id);
    static void validateID(const std::string& id, const std::vector<std::string>& existingIDs);
};

class GenderException {
public:
    static void validateGender(const std::string& gender);
};

class PhoneNumberException {
public:
    static void validatePhoneNumber(const std::string& phoneNumber);
};

class FieldNotEmptyException {
public:
    static void validateField(const std::string& field, const std::string& fieldName);
};

class BoolMustBeSetException {
public:
    static void validateBool(bool flag, const std::string& flagName);
};

class TotalExpensesException {
public:
    static void validateTotalExpenses(int totalExpensesCents);
};

void confirmationException(const std::string& errorMessage, bool& confirmed);
void confirmationException(const std::string& errorMessage, bool& confirmed, const std::string& lastInput);

#endif // EXCEPTIONS_H
