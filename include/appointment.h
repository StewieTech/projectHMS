#ifndef APPOINTMENT_H
#define APPOINTMENT_H

class Patient;  // Forward declaration to avoid circular dependencies

class Appointment {
public:
    Appointment();  // Constructor
    // Add other member functions and attributes as needed

    // Friend function declaration
    friend void setPatientAppointment(Patient* patient, Appointment* appointment);

private:
    // Define the attributes of the Appointment class
    // For example, patient information, medical staff, appointment time, etc.
};

#endif // APPOINTMENT_H
