#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>

using namespace std;

class Procedure {
private:
    string name;
    string description;

public:
    // Constructor
    Procedure(const string& name, const string& description);

    // Getter methods
    string getName() const;
    string getDescription() const;

    // Setter methods
    void setName(const string& newName);
    void setDescription(const string& newDescription);
};

#endif // PROCEDURE_H
