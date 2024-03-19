#include "Procedure.h"
#include <iostream>

using namespace std;

// Constructor
Procedure::Procedure(const string& name, const string& description)
    : name(name), description(description) {}

// Getter methods
string Procedure::getName() const {
    return name;
}

string Procedure::getDescription() const {
    return description;
}

// Setter methods
void Procedure::setName(const string& newName) {
    name = newName;
}

void Procedure::setDescription(const string& newDescription) {
    description = newDescription;
}
