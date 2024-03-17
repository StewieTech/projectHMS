#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>

// using namespace std;

class Procedure {
private:
    std::string name;
    std::string description;

public:
    // Constructor
    Procedure(const std::string& name, const std::string& description)
        : name(name), description(description) {}

    // Getter methods
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }

    // Setter methods (if needed)
    void setName(const std::string& newName) { name = newName; }
    void setDescription(const std::string& newDescription) { description = newDescription; }
};

#endif //PROCEDURE_H
