#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <string>

using namespace std;

class Procedure {
private:
    string name;
    string description;
    double cost; // Assuming cost is represented as a floating-point number

public:
    // Constructor
    Procedure(const string& name, const string& description, double cost)
        : name(name), description(description), cost(cost) {}

    // Getter methods
    string getName() const { return name; }
    string getDescription() const { return description; }
    double getCost() const { return cost; }

    // Setter methods (if needed)
    void setName(const string& newName) { name = newName; }
    void setDescription(const string& newDescription) { description = newDescription; }
    void setCost(double newCost) { cost = newCost; }
};

#endif //PROCEDURE_H