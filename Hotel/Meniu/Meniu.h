// Meniu.h

#ifndef MENIU_H
#define MENIU_H

#include "../Cladire/Cladire.h"
#include "../Angajati/Angajati.h"
#include "../Client/Client.h"
#include <stdexcept>

class MeniuException : public std::runtime_error {
public:
    explicit MeniuException(const char* message) : std::runtime_error(message) {}
};

class InvalidChoiceException : public MeniuException {
public:
    InvalidChoiceException() : MeniuException("Invalid choice. Please enter a number between 1 and 7.") {}
};

class InvalidFloorIdException : public MeniuException {
public:
    InvalidFloorIdException() : MeniuException("Invalid floor ID.") {}
};

class Meniu {
public:
    Meniu();

    void run();

private:
    Cladire cladire;
    Camera cameraInstance;
    Angajati angajat;
    Etaj etaj;

    static bool isValidEmail(const std::string &email);
};

#endif  // MENIU_H
