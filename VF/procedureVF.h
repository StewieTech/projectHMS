#ifndef PROCEDUREVF_H
#define PROCEDUREVF_H

#include <string>
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

#endif // PROCEDUREVF_H
