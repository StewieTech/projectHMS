#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>
#include <memory>
#include <map>
#include <vector>

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
map<string, map<string, vector<Procedure>>> initializeProcedureList();

#endif // PROCEDURE_H
