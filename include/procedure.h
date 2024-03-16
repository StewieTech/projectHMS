#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>

// using namespace std;

class Procedure {
private:
    string name;
    string description;

public:
    // Constructor
    Procedure(const string& name, const string& description)
        : name(name), description(description) {}

    // Getter methods
    string getName() const { return name; }
    string getDescription() const { return description; }

    // Setter methods (if needed)
    void setName(const string& newName) { name = newName; }
    void setDescription(const string& newDescription) { description = newDescription; }
};

#endif //PROCEDURE_H
