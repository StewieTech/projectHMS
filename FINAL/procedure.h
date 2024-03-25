#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>
#include <vector>

using namespace std;

class Procedure {
private:
    //string variables for functions
    string name;
    string description;

public:
    // Const procedure obj
    Procedure(const string& name, const string& description);

    // Getters
    string getName() const;
    string getDescription() const;

    // Setters
    void setName(const string& newName);
    void setDescription(const string& newDescription);
};

#endif // PROCEDURE_H
