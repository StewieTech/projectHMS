#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>

class Procedure {
private:
    std::string name;
    std::string description;

public:
    // Constructor
    Procedure(const std::string& name, const std::string& description);

    // Getter methods
    std::string getName() const;
    std::string getDescription() const;

    // Setter methods
    void setName(const std::string& newName);
    void setDescription(const std::string& newDescription);
};

#endif // PROCEDURE_H
