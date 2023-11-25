#include <iostream>
#include "Hotel/Cladire/Cladire.h"
#include "Hotel/Etaj/Etaj.h"
#include "Hotel/Camera/Camera.h"
#include "Hotel/Angajati/Angajati.h"

int main()
{
    Cladire cladire(1, "Main Street", "Office Building");

    std::cout << "Cladire ID: " << cladire.getId() << std::endl;
    cladire.setAdresa("New Address");
    std::cout << "Cladire Address: " << cladire.getAdresa() << std::endl;

    cladire.setName("New Name");
    std::cout << "Cladire Name: " << cladire.getName() << std::endl;

    Etaj etaj(1, &cladire, 2, true);
    std::cout << "Etaj ID: " << etaj.getId() << std::endl;
    etaj.setId(2);

    std::cout << "Etaj Nr: " << etaj.getNr() << std::endl;
    etaj.setNr(3);

    std::cout << "Etaj has lift? " << etaj.getLift() << std::endl;
    etaj.setLift(false);

    Etaj newCladireEtaj;
    etaj.setCladire(newCladireEtaj.getCladire());
    std::cout << etaj.getCladire() << std::endl;

    std::cout << etaj << std::endl;

    Camera camera(1, &etaj, 32, "neagra", "single");

    Etaj* cameraEtaj = camera.getEtaj();
    std::cout << "Camera's Etaj ID: " << cameraEtaj->getId() << std::endl;

    std::cout << camera << std::endl;

    Angajati angajat(1, &etaj, 4000, "Mircea");

    std::cout << angajat << std::endl;

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

    Cladire cladire2(1, "Main Street", "Office Building");
    Etaj etaj3(1, &cladire2, 2, true);

    Angajati angajat1_2(1, &etaj3, 3000, "John Doe");
    Angajati angajat2_2(2, &etaj3, 4000, "Jane Doe");

    std::cout << "Angajat1 ID: " << angajat1_2.getId() << std::endl;
    std::cout << "Angajat1 Salary: " << angajat1_2.getSalariu() << std::endl;
    std::cout << "Angajat1 Name: " << angajat1_2.getNume() << std::endl;

    angajat1_2.setId(101);
    angajat1_2.setSalariu(3500);
    angajat1_2.setNume("John Smith");

    std::cout << "Updated Angajat1 ID: " << angajat1_2.getId() << std::endl;

    return 0;
}
