#include "exceptions.h"

// base throw message since repetition throughout executions
void BaseException::reportError(const string& errorMessage) {
    cerr << "Error! Invalid Argument, reason: " << errorMessage << endl;
}

// checks for positive number and that the person is within a normal human lifespan (isnt 10 thousand years old)
void InvalidAgeException::invalidAges(int age) {
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

// checks if appointment time is already taken and if the time has already passed (dont want to schedule an appointment in the past)
void AppointmentConflictException::appointmentConflicts(time_t requestedApp, const vector<time_t>& scheduledApps) {
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

// checks that a name is only characters (cant be named X Æ A-12 sorry Elon)
void InvalidNameException::invalidNames(const string& Name) {
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

// throws if ID isnt 6 of length, isnt all numeral or already exists
void InvalidIDException::validateID(const string& id) {
    try {
        // Check if ID length is 6 characters
        if (id.length() != 6) {
            throw invalid_argument("ID must be exactly 6 characters long.");
        }
        
        // Check if all characters are numerals
        for (char c : id) {
            if (!isdigit(c)) {
                throw invalid_argument("ID must contain numerals only.");
            }
        }
    }
    catch (const invalid_argument& e) {
        reportError(e.what());
    }
}

// overloaded to throw if ID exists 
void InvalidIDException::validateID(const string& id, const vector<string>& existingIDs) {
    try {
        // Check if ID length is 6 characters
        if (id.length() != 6) {
            throw invalid_argument("ID must be exactly 6 characters long.");
        }
        
        // Check if all characters are numerals
        for (char c : id) {
            if (!isdigit(c)) {
                throw invalid_argument("ID must contain numerals only.");
            }
        }
        
        // Check if ID already exists
        for (const auto& existingID : existingIDs) {
            if (existingID == id) {
                throw invalid_argument("ID already exists.");
            }
        }
    }
    catch (const invalid_argument& e) {
        reportError(e.what());
    }
}

// asks for a single character for gender will take 3 options M,F,O
void GenderException::validateGender(const string& gender) {
    try {
        if (gender.length() != 1) {
            throw invalid_argument("Gender must be a single character.");
        } else if (gender[0] != 'M' && gender[0] != 'F' && gender[0] != 'O') {
            throw invalid_argument("Invalid gender. Options are 'M' for Male, 'F' for Female, and 'O' for Other.");
        }
    }
    catch (const invalid_argument& e) {
        reportError(e.what());
    }
}

// checks valid phone number based on it being exactly 10 digits
void PhoneNumberException::validatePhoneNumber(const string& phoneNumber) {
    try {
        if (phoneNumber.length() != 10) {
            throw invalid_argument("Phone number must be exactly 10 digits long.");
        }
        for (char digit : phoneNumber) {
            if (!isdigit(digit)) {
                throw invalid_argument("Phone number must contain only digits.");
            }
        }
    }
    catch (const invalid_argument& e) {
        reportError(e.what());
    }
}

// throws if string empty
void FieldNotEmptyException::validateField(const string& field, const string& fieldName) {
    try {
        if (field.empty()) {
            throw invalid_argument(fieldName + " cannot be empty.");
        }
    }
    catch (const invalid_argument& e) {
        reportError(e.what());
    }
}

// throws if bool is empty
void BoolMustBeSetException::validateBool(bool flag, const string& flagName) {
    try {
        if (!flag) {
            throw invalid_argument(flagName + " must be set.");
        }
    }
    catch (const invalid_argument& e) {
        reportError(e.what());
    }
}

// checks for expenses to be a INT since were doing it in cents
void TotalExpensesException::validateTotalExpenses(int totalExpensesCents) {
    try {
        if (totalExpensesCents < 0) {
            throw invalid_argument("Total expenses cannot be negative.");
        }
        // Check if the type of totalExpensesCents is not a string
        if (std::is_same<decltype(totalExpensesCents), string>::value) {
            throw invalid_argument("Total expenses cannot be a string.");
        }
        // Check if the totalExpensesCents is not a floating-point number
        if (totalExpensesCents != static_cast<int>(totalExpensesCents)) {
            throw invalid_argument("Total expenses are in cents no decimal.");
        }
    }
    catch (const invalid_argument& e) {
        reportError(e.what());
    }
}

//confirm information
void confirmationException(const std::string& errorMessage, bool& confirmed) {
    try {
        std::cout << errorMessage << std::endl;
        char confirmation;
        std::cout << "Press 'C' to confirm or any other key to cancel: ";
        std::cin >> confirmation;
        if (confirmation != 'C' && confirmation != 'c') {
            throw std::invalid_argument("Confirmation denied.");
        }
        confirmed = true; // Set confirmed to true if confirmation is successful
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error! " << e.what() << std::endl;
        confirmed = false; // Set confirmed to false if confirmation is denied
    }
}

//overload confirm information function recites back last recieved input
void confirmationException(const std::string& errorMessage, bool& confirmed, const std::string& lastInput) {
    try {
        std::cout << errorMessage << std::endl;
        std::cout << "Is \"" << lastInput << "\" the correct information? (Press 'C' to confirm or any other key to cancel): ";
        char confirmation;
        std::cin >> confirmation;
        if (confirmation != 'C' && confirmation != 'c') {
            throw std::invalid_argument("Confirmation denied.");
        }
        confirmed = true; // Set confirmed to true if confirmation is successful
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error! " << e.what() << std::endl;
        confirmed = false; // Set confirmed to false if confirmation is denied
    }
}

