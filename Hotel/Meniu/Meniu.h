// Meniu.h

#ifndef MENIU_H
#define MENIU_H


#include "../Cladire/Cladire.h"
#include "../Angajati/Angajati.h"

class Meniu {
public:
    Meniu();  // Constructor (if needed)

    void run();  // Function to run the menu program

private:
    Cladire cladire;
    Camera cameraInstance;
    Angajati angajat;
};

#endif  // MENIU_H