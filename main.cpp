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
    Etaj etaj(1, &cladire, 2, true);

    Angajati angajat1(1, &etaj, 3000, "John Doe");
    Angajati angajat2(2, &etaj, 4000, "Jane Doe");

    std::cout << "Angajat1 ID: " << angajat1.getId() << std::endl;
    std::cout << "Angajat1 Salary: " << angajat1.getSalariu() << std::endl;
    std::cout << "Angajat1 Name: " << angajat1.getNume() << std::endl;

    angajat1.setId(101);
    angajat1.setSalariu(3500);
    angajat1.setNume("John Smith");

    std::cout << "Updated Angajat1 ID: " << angajat1.getId() << std::endl;
    std::cout << "Updated Angajat1 Salary: " << angajat1.getSalariu() << std::endl;
    std::cout << "Updated Angajat1 Name: " << angajat1.getNume() << std::endl;

    std::cout << angajat1 << std::endl;

    return 0;
}
