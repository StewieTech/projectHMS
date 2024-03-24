#include "ProcedureVF.h"
#include <iostream>
#include <map>
#include <vector>

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

// Function to initialize and return a map of procedures by specialization
map<string, map<string, vector<Procedure>>> initializeProcedureList() {
    map<string, map<string, vector<Procedure>>> procedureList;

    // Doctor Procedures
    procedureList["Doctor"]["Emergency Physician"] = {
        Procedure("Initial patient assessment and stabilization", "Assess and stabilize patients upon arrival."),
        Procedure("Ordering diagnostic tests", "Order tests like X-rays, CT scans."),
        Procedure("Performing procedures", "Perform procedures like suturing wounds and reducing dislocations."),
    };
    
    procedureList["Doctor"]["Pulmonologist"] = {
        Procedure("Conducting spirometry", "Lung function tests."),
        Procedure("Performing bronchoscopy and PFT", "Pulmonary function testing."),
        Procedure("Conducting thoracentesis and lung tissue biopsy", "Invasive procedures for diagnosis."),
    };
    
    procedureList["Doctor"]["Gastroenterologist"] = {
        Procedure("Performing endoscopy and colonoscopy", ""),
        Procedure("Conducting liver biopsy and ERCP", ""),
        Procedure("Performing manometry", ""),
    };

    // Nurse Procedures
    procedureList["Nurse"]["Emergency Nurse"] = {
        Procedure("Assisting with triage and patient assessment", "Help with triage and initial assessments."),
        Procedure("Administering medications and treatments", "Administer medications and other treatments."),
        Procedure("Providing patient education on discharge instructions", "Educate patients on discharge instructions."),
    };
    
    procedureList["Nurse"]["Respiratory Nurse"] = {
        Procedure("Performing pulmonary function tests", ""),
        Procedure("Administering nebulizer treatments and oxygen therapy", ""),
        Procedure("Assisting with bronchoscopy procedures", ""),
    };

    procedureList["Nurse"]["Gastrointestinal Nurse"] = {
        Procedure("Preparing patients for endoscopic procedures", ""),
        Procedure("Assisting with sedation and monitoring", ""),
        Procedure("Providing post-procedure care and education", ""),
    };

    return procedureList;
}