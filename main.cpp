#include <iostream>
#include "Hotel/Cladire/Cladire.h"
#include "Hotel/Etaj/Etaj.h"
#include "Hotel/Camera/Camera.h"
#include "Hotel/Angajati/Angajati.h"

int main()
{
    Cladire cladire(1, "Main Street", "Office Building");
    Etaj etaj(1, &cladire, 2, true);

    std::cout << "Etaj ID: " << etaj.getId() << std::endl;
    etaj.setId(2);

    std::cout << "Etaj Nr: " << etaj.getNr() << std::endl;
    etaj.setNr(3);

    std::cout << "Etaj has lift? " << etaj.getLift() << std::endl;
    etaj.setLift(false);

    Cladire newCladire(2, "Broadway", "Commercial Building");
    etaj.setCladire(newCladire);

    std::cout << etaj << std::endl;

    std::cout << "Prima clasa(Cladire):" << std::endl;
    Cladire A(1, "204, Splaiul Independentei", "Camin Grozavesti");
    std::cout << A << std::endl;

    Cladire B;
    B = A;

    std::cout << "A doua clasa(Etaj):" << std::endl;
    Etaj C(1, &A, 3, false);
    std::cout << C;

    std::cout << "A treia clasa:(Camera)" << std::endl;
    Camera D(1, &C, 32, "neagra", "single");
    std::cout << D << std::endl;

    std::cout << "A patra clasa:(Angajati)" << std::endl;
    Angajati E(1, &C, 4000, "Mircea");
    std::cout << E;

    return 0;
}
