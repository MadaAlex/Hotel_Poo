#include <iostream>
#include "Hotel/Cladire/Cladire.h"
#include "Hotel/Etaj/Etaj.h"
#include "Hotel/Camera/Camera.h"
#include "Hotel/Angajati/Angajati.h"

int main()
{
    Etaj etaj1(1, nullptr, 1, true);
    Etaj etaj2(2, nullptr, 2, false);

    Camera camera1(1, &etaj1, 101, "red", "wide");
    Camera camera2(2, &etaj2, 102, "blue", "telephoto");

    std::cout << "Camera1 ID: " << camera1.getId() << std::endl;
    std::cout << "Camera1 Number: " << camera1.getNr() << std::endl;
    std::cout << "Camera1 Color: " << camera1.getCuloare() << std::endl;
    std::cout << "Camera1 Type: " << camera1.getTip() << std::endl;

    camera1.setId(201);
    camera1.setNr(202);
    camera1.setCuloare("green");
    camera1.setTip("macro");

    std::cout << "Updated Camera1 ID: " << camera1.getId() << std::endl;
    std::cout << "Updated Camera1 Number: " << camera1.getNr() << std::endl;
    std::cout << "Updated Camera1 Color: " << camera1.getCuloare() << std::endl;
    std::cout << "Updated Camera1 Type: " << camera1.getTip() << std::endl;

    camera1.setEtaj(&etaj2);

    std::cout << camera1 << std::endl;

    Cladire cladire(1, "Main Street", "Office Building");

    std::cout << "Cladire ID: " << cladire.getId() << std::endl;
    cladire.setAdresa("New Address");
    std::cout << "Cladire Address: " << cladire.getAdresa() << std::endl;

    cladire.setName("New Name");
    std::cout << "Cladire Name: " << cladire.getName() << std::endl;

    std::cout << cladire << std::endl;

    Etaj etaj(1, &cladire, 2, true);
    std::cout << "Etaj ID: " << etaj.getId() << std::endl;
    etaj.setId(2);

    std::cout << "Etaj Nr: " << etaj.getNr() << std::endl;
    etaj.setNr(3);

    std::cout << "Etaj has lift? " << etaj.getLift() << std::endl;
    etaj.setLift(false);

    std::cout << etaj << std::endl;

    Cladire A(1, "204, Splaiul Independentei", "Camin Grozavesti");
    std::cout << A << std::endl;

    Cladire B;
    B = A;

    Etaj C(1, &A, 3, false);
    std::cout << C;

    Camera D(1, &C, 32, "neagra", "single");
    std::cout << D << std::endl;

    Angajati E(1, &C, 4000, "Mircea");
    std::cout << E;

    return 0;
}
