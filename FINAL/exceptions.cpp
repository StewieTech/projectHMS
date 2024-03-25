#include "exceptions.h"
#include <stdexcept>


using namespace std;

//function to validate date/time format
bool isValidAppointmentTimeFormat(const string& time) {
    // Check if the time string has the correct format (YYYY-MM-DD HH:MM)
    if (time.size() != 16) // Check if the string length is correct
        return false;

    if (time[4] != '-' || time[7] != '-' || time[10] != ' ' || time[13] != ':')
        return false; // Check if the separators are in the correct positions

    for (int i = 0; i < 16; ++i) {
        if (i == 4 || i == 7 || i == 10 || i == 13)
            continue; // Skip separators
        if (!isdigit(time[i]))
            return false; // Check if all characters except separators are digits
    }

    return true; // If all checks pass, the format is valid
}


// base throw message since repetition throughout executions
void BaseException::reportError(const string& errorMessage) {
    cerr << "Error! Invalid Argument, reason: " << errorMessage << endl;
}

// checks for positive number and that the person is within a normal human lifespan (isnt 10 thousand years old)
bool InvalidAgeException::invalidAges(int age) {
    try {
        if (age <= 0) {
            throw invalid_argument("Age must be a positive number.");
        }
        if (age > 150) {
            throw invalid_argument("Age outside normal lifespan.");
        }
        return true; // If no exception is thrown, the age is valid
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false; // Return false if an exception is caught
    }
}


// checks if appointment time is already taken and if the time has already passed (dont want to schedule an appointment in the past)
class AvailabilityException {
public:
    static void checkAvailability(bool available) {
        try {
            if (!available) {
                throw invalid_argument("Staff member is unavailable.");
            }
        }
        catch (const invalid_argument& e) {
            BaseException::reportError(e.what());
        }
    }
};
// checks that a name is only characters (cant be named X Æ A-12 sorry Elon)
bool InvalidNameException::invalidNames(const string& Name) {
    try {
        for (char c : Name) {
            if (isdigit(c)) { // Check if character is numeric
                throw invalid_argument("Names must not contain numbers.");
            }
        }
        // If no exception is thrown, the name is valid
        return true;
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false;
    }
}

// throws if ID isnt 6 of length, isnt all numeral or already exists
bool InvalidIDException::validateID(const string& id) {
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

        // If no exception is thrown, the ID is valid
        return true;
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false; // Return false if an exception is caught
    }
}


// overloaded to throw if ID exists
bool InvalidIDException::validateID(const string& id, const vector<string>& existingIDs) {
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

        // If no exception is thrown, the ID is valid
        return true;
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false; // Return false if an exception is caught
    }
}


// asks for a single character for gender will take 3 options M,F,O
bool GenderException::validateGender(const string& gender) {
    try {
        if (gender.length() != 1) {
            throw invalid_argument("Gender must be a single character.");
        }
        char g = tolower(gender[0]); // Convert the gender character to lowercase
        if (g != 'm' && g != 'f' && g != 'o') {
            throw invalid_argument("Invalid gender. Options are 'M' for Male, 'F' for Female, and 'O' for Other.");
        }
        return true; // If no exception is thrown, the gender is valid
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false; // Return false if an exception is caught
    }
}

// checks valid phone number based on it being exactly 10 digits
bool PhoneNumberException::validatePhoneNumber(const string& phoneNumber) {
    try {
        if (phoneNumber.length() != 10) {
            throw invalid_argument("Phone number must be exactly 10 digits long.");
        }
        for (char digit : phoneNumber) {
            if (!isdigit(digit)) {
                throw invalid_argument("Phone number must contain only digits.");
            }
        }
        return true; // If no exception is thrown, the phone number is valid
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false; // Return false if an exception is caught
    }
}


// throws if string empty
bool FieldNotEmptyException::validateField(const string& field) {
    try {
        if (field.empty()) {
            throw invalid_argument("Field cannot be empty.");
        }
        return true; // Field is not empty, so return true
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false; // Field is empty, so return false
    }
}

// throws if bool is empty
bool BoolMustBeSetException::validateBool(bool flag) {
    try {
        if (!flag) {
            throw invalid_argument("Flag must be set.");
        }
        return true; // Flag is set, so return true
    }
    catch (const invalid_argument& e) {
        BaseException::reportError(e.what());
        return false; // Flag is not set, so return false
    }
}

//confirm information
void confirmationException(const string& errorMessage, bool& confirmed) {
    try {
        cout << errorMessage << endl;
        char confirmation;
        cout << "Press 'C' to confirm or any other key to cancel: ";
        cin >> confirmation;
        if (confirmation != 'C' && confirmation != 'c') {
            throw invalid_argument("Confirmation denied.");
        }
        confirmed = true; // Set confirmed to true if confirmation is successful
    }
    catch (const invalid_argument& e) {
        cerr << "Error! " << e.what() << endl;
        confirmed = false; // Set confirmed to false if confirmation is denied
    }
}

//overload confirm information function recites back last recieved input
void confirmationException(const string& errorMessage, bool& confirmed, const string& lastInput) {
    try {
        cout << errorMessage << endl;
        cout << "Is \"" << lastInput << "\" the correct information? (Press 'C' to confirm or any other key to cancel): ";
        char confirmation;
        cin >> confirmation;
        if (confirmation != 'C' && confirmation != 'c') {
            throw invalid_argument("Confirmation denied.");
        }
        confirmed = true; // Set confirmed to true if confirmation is successful
    }
    catch (const invalid_argument& e) {
        cerr << "Error! " << e.what() << endl;
        confirmed = false; // Set confirmed to false if confirmation is denied
    }
}

